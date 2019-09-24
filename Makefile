CC=gcc
CFLAGS=-Wall
TARGETS=getopt getopt_long
.PHONY:all
all:$(TARGETS)
getopt:getopt.o
getopt_long:getopt_long.o
%:%.o
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY:clean
clean:
	$(RM) *.o $(TARGETS)
