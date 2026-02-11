DEBUG=true
if [ -d TestDir ];
then
	echo "Directory already exists";
	exit 1;
fi
mkdir TestDir
