echo "enter the a value"
read a
echo "enter the b value"
read b
echo "enter the c value"
read c
if [ $a -gt $b ];
then
	echo "a is greater than b"
elif [ $a -gt $c ];
then
        echo "a is greater than b"
else
	echo "a is not greater than b and c"
fi
