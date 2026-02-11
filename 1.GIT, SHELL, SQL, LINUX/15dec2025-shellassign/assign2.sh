while true
do
	echo "enter the number"
	read num
	if [ $num -eq 0 ];
	then
		echo "exiting program"
	elif [ $((num % 2)) -eq 0 ];
	then
		echo "$num is even"
	else
		echo "$num is odd"
	fi
done
