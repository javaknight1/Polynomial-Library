# Sample makefile
# D. Frey
# Spring 2011
##

CC = /usr/bin/gcc
CFLAGS = -Wall -std=c99 -g

# name of the executable to be created
PROJECT = project3

# list of all .c files
SRCS = project3.c polynomials.c

#list of all .h files
HDRS = polynomials.h

# list of .o files
OBJS = project3.o polynomials.o

# the first rule is the default rule
# build the executable from the .o files
$(PROJECT) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROJECT)

# a separate rule to compile each .c file
project3.o: project3.c polynomials.h
	$(CC) $(CFLAGS) -c project3.c

polynomials.o : polynomials.c polynomials.h
	$(CC) $(CFLAGS) -c polynomials.c

# some handy commands that you can "make"
clean:
	rm -fv core* $(PROJECT) $(OBJS)

cleaner: clean
	rm -fv #* *~

