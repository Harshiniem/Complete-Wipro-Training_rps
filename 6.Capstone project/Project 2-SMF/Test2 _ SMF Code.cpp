// ================================================================
// 5G Core - SMF PDU Session Establishment Simulator
// Spec:   3GPP TS 23.502, TS 29.502, TS 29.244 (PFCP)
// ================================================================

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// PDU Session Type (3GPP TS 24.501)
enum PDUSessionType {
    PDU_IPv4 = 1, PDU_IPv6 = 2, PDU_IPv4v6 = 3,
    PDU_Unstructured = 4, PDU_Ethernet = 5
};

// Request Type
enum RequestType {
    INITIAL_REQUEST = 1, EXISTING_PDU = 2,
    INITIAL_EMERGENCY = 3, MODIFICATION_REQ = 4
};

// PDU Session State Machine
enum PDUSessionState {
    STATE_IDLE,
    STATE_SM_CONTEXT_CREATING,
    STATE_N4_SESSION_SETUP,
    STATE_WAITING_AN_TUNNEL_INFO,
    STATE_N4_SESSION_MODIFYING,
    STATE_ACTIVE,
    STATE_RELEASED,
    STATE_ERROR
};

// 5QI Values (TS 23.501 Table 5.7.4-1)
enum QoS5QI {
    QI_1_CONVERSATIONAL = 1,
    QI_5_IMS_SIGNALING  = 5,
    QI_9_DEFAULT_INTERNET = 9,
    QI_80_LOW_LATENCY   = 80
};

string state_to_string(PDUSessionState s) {
    const char* names[] = {
        "IDLE",
        "SM_CONTEXT_CREATING",
        "N4_SESSION_SETUP",
        "WAITING_AN_TUNNEL_INFO",
        "N4_SESSION_MODIFYING",
        "ACTIVE",
        "RELEASED",
        "ERROR"
    };
    return names[s];
}

// ================================================================
// STEP 2: Core Data Structures (3GPP Aligned)
// ================================================================

// S-NSSAI: Single Network Slice Selection Assistance Info
struct SNSSAI {
    int sst;
    int sd;

    string to_string() const {
        return "SST=" + std::to_string(sst) +
               ",SD=" + std::to_string(sd);
    }
};

// GTP-U Tunnel Endpoint Identifier
struct FTEID {
    uint32_t teid;
    string ip_addr;

    string to_string() const {
        stringstream ss;
        ss << "TEID=0x" << hex << teid
           << ",IP=" << ip_addr;
        return ss.str();
    }
};

// QoS Flow descriptor
struct QoSFlow {
    int  qfi;
    int  fiveqi;
    int  priority;
    int  mbr_dl, mbr_ul;
    int  gbr_dl, gbr_ul;
    bool is_default;
};

struct SessionAMBR {
    int dl_ambr;
    int ul_ambr;
};

// PFCP Rules (3GPP TS 29.244)
struct PDR {
    int pdr_id;
    int precedence;
    string source_interface;
    int far_id, qer_id, urr_id;
};

struct FAR {
    int far_id;
    string apply_action;
    string destination;
    bool header_creation;
};

struct QER {
    int qer_id, qfi;
    int mbr_dl, mbr_ul;
    int gbr_dl, gbr_ul;
};

struct PCCRule {
    string rule_id;
    int precedence;
    int fiveqi;
    string flow_description;
    string gate_status;
};

struct SMSubscriptionData {
    string dnn;
    PDUSessionType allowed_pdu_type;
    SessionAMBR subscribed_ambr;
    int default_5qi;
    bool authorized;
};

// PDU Session Context (SMF maintains this)
struct PDUSessionContext {
    int pdu_session_id;
    string supi, dnn;
    SNSSAI snssai;
    PDUSessionType pdu_type;
    PDUSessionState state;

    string ue_ip_addr;

    FTEID upf_n3_fteid;
    FTEID gnb_n3_fteid;
    FTEID upf_n4_fteid;

    SessionAMBR session_ambr;

    vector<QoSFlow> qos_flows;
    vector<PDR> pdrs;
    vector<FAR> fars;
    vector<QER> qers;
    vector<PCCRule> pcc_rules;
};

// ================================================================
// STEP 3: Network Function Simulators (UDM, PCF, UPF)
// ================================================================

class UDM_Simulator {
public:
    SMSubscriptionData get_sm_data(
        const string& supi,
        const string& dnn,
        const SNSSAI& snssai
    ) {
        cout << "  [UDM] Nudm_SDM_Get: SUPI=" << supi
             << ", DNN=" << dnn << endl;

        SMSubscriptionData data;
        data.dnn = dnn;
        data.allowed_pdu_type = PDU_IPv4v6;
        data.subscribed_ambr = {500000, 100000};
        data.default_5qi = 9;
        data.authorized = true;

        cout << "  [UDM] Subscription: AMBR DL="
             << data.subscribed_ambr.dl_ambr
             << "kbps, UL=" << data.subscribed_ambr.ul_ambr
             << "kbps, 5QI=" << data.default_5qi << endl;

        cout << "  [UDM] Authorization: GRANTED" << endl;
        return data;
    }
};

class PCF_Simulator {
public:
    struct PolicyDecision {
        SessionAMBR session_ambr;
        vector<PCCRule> pcc_rules;
        int default_qfi, default_5qi;
    };

    PolicyDecision create_sm_policy(
        const string& supi,
        const string& dnn,
        const SNSSAI& snssai
    ) {
        cout << "  [PCF] Npcf_SMPolicyControl_Create for DNN="
             << dnn << endl;

        PolicyDecision d;
        d.session_ambr = {500000, 100000};
        d.default_qfi = 1;
        d.default_5qi = 9;

        PCCRule r1{"PCC_DEFAULT", 255, 9,
                   "permit out ip from any", "OPEN"};

        PCCRule r2{"PCC_VIDEO", 100, 7,
                   "permit out ip 10.0.0.0/8", "OPEN"};

        d.pcc_rules = {r1, r2};

        cout << "  [PCF] Rules: " << d.pcc_rules.size()
             << " PCC rules installed" << endl;

        for (auto& r : d.pcc_rules)
            cout << "         " << r.rule_id
                 << " 5QI=" << r.fiveqi
                 << " Gate=" << r.gate_status << endl;

        return d;
    }
};

class UPF_Simulator {
    int next_teid = 0x1000;

public:
    struct N4Response {
        bool success;
        FTEID upf_n3_fteid;
        FTEID upf_n4_fteid;
        string cause;
    };

    N4Response pfcp_session_establishment(
        const vector<PDR>& pdrs,
        const vector<FAR>& fars,
        const vector<QER>& qers
    ) {
        cout << "  [UPF] N4: PFCP Session Est Request" << endl;

        cout << "  [UPF] Installing: " << pdrs.size()
             << " PDRs, " << fars.size()
             << " FARs, " << qers.size()
             << " QERs" << endl;

        for (auto& p : pdrs)
            cout << "  [UPF]   PDR#" << p.pdr_id << " "
                 << p.source_interface << "->FAR#"
                 << p.far_id << endl;

        N4Response r;
        r.success = true;
        r.cause = "Request Accepted";

        r.upf_n3_fteid = {(uint32_t)next_teid++, "10.200.1.100"};
        r.upf_n4_fteid = {(uint32_t)next_teid++, "10.200.1.100"};

        cout << "  [UPF] N3 F-TEID: "
             << r.upf_n3_fteid.to_string() << endl;

        cout << "  [UPF] Cause: " << r.cause << endl;

        return r;
    }

    bool pfcp_session_modification(const FTEID& gnb_fteid) {
        cout << "  [UPF] N4: PFCP Session Mod Request" << endl;
        cout << "  [UPF] Updating DL FAR with gNB: "
             << gnb_fteid.to_string() << endl;
        cout << "  [UPF] DL path activated" << endl;
        return true;
    }
};

// ================================================================
// STEP 4: SMF - Session Management Function (Core Logic)
// ================================================================

class SMF {
private:
    UDM_Simulator udm;
    PCF_Simulator pcf;
    UPF_Simulator upf;

    map<int, PDUSessionContext> sessions;
    int next_ip_suffix = 10;

    void transition(PDUSessionContext& ctx,
                    PDUSessionState newState) {
        cout << "  [SMF] State: "
             << state_to_string(ctx.state) << " -> "
             << state_to_string(newState) << endl;
        ctx.state = newState;
    }

    string allocate_ip() {
        return "10.45.0." + to_string(next_ip_suffix++);
    }

    void create_pfcp_rules(PDUSessionContext& ctx) {
        cout << "  [SMF] Creating PFCP rules from PCC policy..."
             << endl;

        // UL PDR
        PDR ul_pdr{1, 100, "ACCESS", 1, 1, 1};
        ctx.pdrs.push_back(ul_pdr);

        // DL PDR
        PDR dl_pdr{2, 100, "CORE", 2, 1, 1};
        ctx.pdrs.push_back(dl_pdr);

        // UL FAR
        FAR ul_far{1, "FORWARD", "CORE", false};
        ctx.fars.push_back(ul_far);

        // DL FAR (initially BUFFER)
        FAR dl_far{2, "BUFFER", "ACCESS", true};
        ctx.fars.push_back(dl_far);

        // QER
        QER qer;
        qer.qer_id = 1;
        qer.qfi = ctx.qos_flows[0].qfi;
        qer.mbr_dl = ctx.session_ambr.dl_ambr;
        qer.mbr_ul = ctx.session_ambr.ul_ambr;
        qer.gbr_dl = 0;
        qer.gbr_ul = 0;
        ctx.qers.push_back(qer);

        cout << "  [SMF] Rules: 2 PDRs, 2 FARs, 1 QER created"
             << endl;

        cout << "  [SMF] DL FAR initially set to BUFFER (gNB TEID unknown)"
             << endl;
    }

public:

    bool create_sm_context(
        const string& supi,
        int pdu_session_id,
        const string& dnn,
        const SNSSAI& snssai,
        PDUSessionType pdu_type,
        RequestType req_type
    ) {
        cout << endl;
        cout << string(60, '=') << endl;
        cout << "  SMF: Nsmf_PDUSession_CreateSMContext" << endl;
        cout << string(60, '=') << endl;

        PDUSessionContext ctx;
        ctx.pdu_session_id = pdu_session_id;
        ctx.supi = supi;
        ctx.dnn = dnn;
        ctx.snssai = snssai;
        ctx.pdu_type = pdu_type;
        ctx.state = STATE_IDLE;

        cout << "  [SMF] New session: ID=" << pdu_session_id
             << ", SUPI=" << supi << endl;

        cout << "  [SMF] DNN=" << dnn
             << ", S-NSSAI=" << snssai.to_string() << endl;

        transition(ctx, STATE_SM_CONTEXT_CREATING);

        // Phase A1: UDM Query
        cout << endl << "  --- Phase A1: UDM Query ---" << endl;
        auto sm_data = udm.get_sm_data(supi, dnn, snssai);

        if (!sm_data.authorized) {
            cout << "  [SMF] DENIED by UDM!" << endl;
            transition(ctx, STATE_ERROR);
            return false;
        }

        // Phase A2: PCF Policy
        cout << endl << "  --- Phase A2: PCF Policy ---" << endl;
        auto policy = pcf.create_sm_policy(supi, dnn, snssai);

        ctx.session_ambr = policy.session_ambr;
        ctx.pcc_rules = policy.pcc_rules;

        // Phase A3: IP Allocation
        cout << endl << "  --- Phase A3: IP Allocation ---" << endl;
        ctx.ue_ip_addr = allocate_ip();

        cout << "  [SMF] Allocated UE IP: " << ctx.ue_ip_addr << endl;

        // Default QoS Flow
        QoSFlow def_flow;
        def_flow.qfi = policy.default_qfi;
        def_flow.fiveqi = policy.default_5qi;
        def_flow.priority = 9;
        def_flow.mbr_dl = policy.session_ambr.dl_ambr;
        def_flow.mbr_ul = policy.session_ambr.ul_ambr;
        def_flow.gbr_dl = 0;
        def_flow.gbr_ul = 0;
        def_flow.is_default = true;

        ctx.qos_flows.push_back(def_flow);

        cout << "  [SMF] Default QoS Flow: QFI="
             << def_flow.qfi << ", 5QI="
             << def_flow.fiveqi << endl;

        // Phase B: N4 PFCP Session Setup
        cout << endl;
        cout << string(60, '-') << endl;
        cout << "  Phase B: N4/PFCP Session Setup" << endl;
        cout << string(60, '-') << endl;

        transition(ctx, STATE_N4_SESSION_SETUP);

        create_pfcp_rules(ctx);

        auto n4_resp = upf.pfcp_session_establishment(
            ctx.pdrs, ctx.fars, ctx.qers
        );

        if (!n4_resp.success) {
            cout << "  [SMF] UPF N4 FAILED!" << endl;
            transition(ctx, STATE_ERROR);
            return false;
        }

        ctx.upf_n3_fteid = n4_resp.upf_n3_fteid;
        ctx.upf_n4_fteid = n4_resp.upf_n4_fteid;

        // Phase C: N1N2 Message Transfer
        cout << endl;
        cout << string(60, '-') << endl;
        cout << "  Phase C: N1N2MessageTransfer to AMF" << endl;
        cout << string(60, '-') << endl;

        transition(ctx, STATE_WAITING_AN_TUNNEL_INFO);

        cout << "  [SMF] Sending to AMF:" << endl;
        cout << "    N1 (NAS): PDU Session Est Accept" << endl;
        cout << "      PDU Session ID: " << ctx.pdu_session_id << endl;
        cout << "      PDU Type: IPv4v6" << endl;
        cout << "      UE IP: " << ctx.ue_ip_addr << endl;
        cout << "      Session AMBR: DL=" << ctx.session_ambr.dl_ambr
             << " UL=" << ctx.session_ambr.ul_ambr << endl;
        cout << "      QoS Flow: QFI=" << def_flow.qfi
             << " 5QI=" << def_flow.fiveqi << endl;

        cout << "    N2 (NGAP): PDU Session Resource Setup Request" << endl;
        cout << "      UPF N3 TEID: " << ctx.upf_n3_fteid.to_string() << endl;
        cout << "      QoS Flow List for DRB mapping" << endl;

        sessions[pdu_session_id] = ctx;
        return true;
    }

    bool update_sm_context(int pdu_session_id, const FTEID& gnb_fteid) {

        cout << endl;
        cout << string(60, '=') << endl;
        cout << "  SMF: Nsmf_PDUSession_UpdateSMContext" << endl;
        cout << string(60, '=') << endl;

        if (sessions.find(pdu_session_id) == sessions.end()) {
            cout << "  [SMF] ERROR: Session not found!" << endl;
            return false;
        }

        auto& ctx = sessions[pdu_session_id];
        ctx.gnb_n3_fteid = gnb_fteid;

        cout << "  [SMF] Received gNB N3: "
             << gnb_fteid.to_string() << endl;

        cout << endl;
        cout << string(60, '-') << endl;
        cout << "  Phase D: N4 Session Modification" << endl;
        cout << string(60, '-') << endl;

        transition(ctx, STATE_N4_SESSION_MODIFYING);

        cout << "  [SMF] Updating DL FAR#2: BUFFER -> FORWARD" << endl;
        cout << "  [SMF] Adding outer header creation with gNB TEID" << endl;

        bool mod_ok = upf.pfcp_session_modification(gnb_fteid);

        if (mod_ok) {
            transition(ctx, STATE_ACTIVE);

            cout << endl;
            cout << "  *************************************" << endl;
            cout << "  *  PDU SESSION ESTABLISHED SUCCESS  *" << endl;
            cout << "  *  User Plane Data Active           *" << endl;
            cout << "  *************************************" << endl;

            return true;
        }

        transition(ctx, STATE_ERROR);
        return false;
    }

    void print_session(int id) {

        if (sessions.find(id) == sessions.end()) {
            cout << "Session not found!" << endl;
            return;
        }

        auto& s = sessions[id];

        cout << endl << string(60, '=') << endl;
        cout << "  PDU SESSION SUMMARY" << endl;
        cout << string(60, '=') << endl;

        cout << "  Session ID  : " << s.pdu_session_id << endl;
        cout << "  SUPI        : " << s.supi << endl;
        cout << "  DNN         : " << s.dnn << endl;
        cout << "  S-NSSAI     : " << s.snssai.to_string() << endl;
        cout << "  State       : " << state_to_string(s.state) << endl;
        cout << "  UE IP       : " << s.ue_ip_addr << endl;
        cout << "  UPF N3      : " << s.upf_n3_fteid.to_string() << endl;
        cout << "  gNB N3      : " << s.gnb_n3_fteid.to_string() << endl;

        cout << "  AMBR        : DL=" << s.session_ambr.dl_ambr
             << "kbps, UL=" << s.session_ambr.ul_ambr
             << "kbps" << endl;

        cout << "  QoS Flows   : " << s.qos_flows.size() << endl;

        for (auto& q : s.qos_flows)
            cout << "    QFI=" << q.qfi
                 << " 5QI=" << q.fiveqi
                 << (q.is_default ? " [DEFAULT]" : "")
                 << endl;

        cout << "  PFCP Rules  : " << s.pdrs.size()
             << " PDRs, " << s.fars.size()
             << " FARs, " << s.qers.size()
             << " QERs" << endl;

        cout << "  PCC Rules   : " << s.pcc_rules.size() << endl;
        cout << string(60, '=') << endl;
    }
};

// ================================================================
// STEP 5: Main - Complete PDU Session Establishment
// ================================================================

int main() {

    cout << string(60, '*') << endl;
    cout << "  5G Core - SMF PDU Session Establishment" << endl;
    cout << "  3GPP TS 23.502 / TS 29.502 Compliant" << endl;
    cout << string(60, '*') << endl;

    SMF smf;

    cout << endl;
    cout << ">>>>>> UE -> AMF: NAS PDU Session Est Req" << endl;
    cout << ">>>>>> AMF -> SMF: Nsmf CreateSMContext" << endl;

    SNSSAI slice = {1, 1};

    bool created = smf.create_sm_context(
        "imsi-001010123456789",
        5,
        "internet",
        slice,
        PDU_IPv4v6,
        INITIAL_REQUEST
    );

    if (!created) {
        cout << "PDU Session Creation FAILED!" << endl;
        return 1;
    }

    cout << endl;
    cout << ">>>>>> AMF -> gNB: PDU Session Resource Setup Request" << endl;
    cout << ">>>>>> gNB -> UE: RRC Reconfiguration (DRB setup + NAS Accept)" << endl;
    cout << ">>>>>> UE -> gNB: RRC Reconfig Complete" << endl;
    cout << ">>>>>> gNB -> AMF: Resource Setup Resp" << endl;
    cout << ">>>>>> AMF -> SMF: UpdateSMContext (gNB TEID)" << endl;

    FTEID gnb_teid = {0x2001, "192.168.1.50"};
    smf.update_sm_context(5, gnb_teid);

    smf.print_session(5);

    cout << endl << "Simulation Complete." << endl;
    return 0;
}

