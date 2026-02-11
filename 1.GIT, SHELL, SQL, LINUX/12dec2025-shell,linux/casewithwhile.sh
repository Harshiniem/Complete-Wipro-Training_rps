while echo "enter empid"
do
	read empid
	case "$empid" in
		[0-9][0-9][0-9]) grep "^empid" emp.lst ;;
		0)exit ;;
		*) echo "employee id:  %empid not found" ;;
	esac
done
