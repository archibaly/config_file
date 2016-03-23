CC = gcc
CFLAGS = -Wall
EXE = config_file

$(EXE): config_file.o kmp.o main.o
	$(CC) -o $@ $^

config_file.o: config_file.c config_file.h
kmp.o: kmp.c kmp.h
main.o: main.c

clean:
	-rm -f config_file.o kmp.o main.o $(EXE)
