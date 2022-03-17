all: mycp

# define a target to link the application
#
mycp: mycp.o
        g++ -g -lm mycp.o -o mycp

# define targets to compile the source code
#
mycp.o: mycp.cc lab8.h Makefile
        g++ -g -c mycp.cc -o mycp.o

# define a target to clean the directory
#
clean:
        rm -f mycp.o mycp
