# be careful to not put spaces where they shouldn't be,
# otherwise the first word will be considered a call to a
# bash function



# *.c automatically a list of all the files that match the
# description "*.c"

for file in *.c
do
  echo "the name of the file is $file"
done
echo *.c
echo ciao.{x,c}   # notice that "ciao.{x, c}" doesn't work
echo   # print a space



# "$number" refers to the command line arguments
# "$@" refers to all the command line arguments

echo "the name of the program is $0"
for thing in "$1" "$2" "$3"
do
  echo $thing
done
echo "$@"
echo



# we can call a function's output using $(...)
# in this example we call the fifth line of the file that
# we pass as a command line argument to the script

echo $(head -n5 "$1" | tail -n1)
echo



# definition of a variable

foo=bar   # notice that "foo = bar" wouldn't work
echo $foo
echo "$foo"
echo '$foo'
