# in a shell script "$some_number" is a way to call an argument given to
# the program via command line; some_number is the number of the argument
# in the order on the command line (1 is the first argument, name of the
# script excluded)

# "$@" refers to all the arguments passed from command line


head -n 15 "$1" | tail -n 5
