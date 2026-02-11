grep "ERROR" app.log | awk '{print $1, $2, $4, $5, $6}'
