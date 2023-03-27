# $(nomevar) si usa per chiamare una variabile

# the structure of the 'commands' for the compiler is:
# TARGET: DEPENDENCIES
# <TAB> COMMANDS

# NOTICE: tabs before commands CANNOT be subtituted by normal spaces

# $@ refers to the current target (instead of it I could have just used hello.x)
# $^ refers to all the current dependencies (instead of it I could have just used src/hello.o main.o)

# what does a Makfile do:
# the target is just the name of the command that follows (I could for instance call 'pippo' the command
# that I called 'src/hello.o'; obviously I should also change its name in the dependencies of the
# previous command): if you use 'make target' only the target command will be executed, and the following
# ones will be executed ONLY if they are among its dependencies; if you use just 'make' te first command
# will be executed.
# for example in this case: when you call 'make' from command line the compiler tries to execute the command
# with target 'hello.x'; since it has two other commands as dependencies, before executing it, it executes
# the other two commands; the command with target 'clean' is not executed, unless we call it explicitly with
# 'make clean'



# compiler
CC = g++
# header folder
INCDIR = head
# object files compiling command
CFLAGS = -I$(INCDIR)

hello.x: hello.o main.o
	$(CC) -o $@ $^

hello.o:
	$(CC) -c src/hello.cpp

main.o:
	$(CC) -c main.cpp $(CFLAGS)

clean:
	rm -rf hello.x *.o


# invece di fare tutti i passaggi (file oggetto e poi eseguibile) potevo usare una riga soltanto
# e compilare direttamente hello.x:
#
# hello.x: src/hello.cpp main.cpp
#	 $(CC) -o hello.x src/hello.cpp main.cpp $(CFLAGS)
