# string=hello.world
# echo ${string%.world}

string=hello.world
echo ${string:2:1}
echo ${string:2:2}
echo ${string:2:20}
echo ${string: -1} # mind the space before - sign
echo ${string: -4}
echo ${string:2: -1}