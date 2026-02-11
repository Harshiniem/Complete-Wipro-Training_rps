file="file1.txt"
if [ -f "$file" ]
then
	echo "File exists"
else
	echo "File not found"
fi
