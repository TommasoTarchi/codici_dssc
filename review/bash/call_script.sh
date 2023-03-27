# this script calls another bash script (called middle.sh) passing to it
# the command line argument that was passed to this script

bash middle.sh "$1" | wc
