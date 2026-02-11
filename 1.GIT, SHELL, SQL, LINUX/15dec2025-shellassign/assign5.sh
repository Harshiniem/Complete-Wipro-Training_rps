DEBUG=true
if [ -d TestDir ]; then echo "Directory exists"; exit 1; fi
mkdir TestDir
[ "$DEBUG" = true ] && echo "Directory created"

