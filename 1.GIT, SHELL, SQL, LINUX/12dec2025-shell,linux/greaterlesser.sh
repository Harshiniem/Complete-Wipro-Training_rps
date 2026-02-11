echo 'Enter n1 and n2 values'
 
n1=$1
n2=$2
 
if  test  $n1 -ge $n2; then 
	echo "n1 and n2 are equal"
 
 
else
	 echo "n1 and n2 are not equal"
 
fi
 
 
if   [$n1 -gt $n2];  then
 
	echo "Its greater"
 
fi	
 
