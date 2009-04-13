for COMMAND in x-www-browser $DEFAULTBROWSER firefox mozilla dillo opera 
do
	which $COMMAND
	if [ $? -eq 0 ];
	then
		$COMMAND $1 &
		exit 0
	else
		echo $COMMAND is not found.
	fi
done
exit 1

