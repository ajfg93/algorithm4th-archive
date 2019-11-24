# variable CC will be the compiler to use.
CC=clang++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall
INCLUDEPATH = -I algorithm-bookeeping/
all: main

main: 
	$(CC) -fsanitize=address -g -Wall main.cpp $(INCLUDEPATH); ASAN_OPTIONS=detect_leaks=1 ./a.out

ex:
	$(CC) -fsanitize=address -g -Wall ./exercises/2.2.6.cpp $(INCLUDEPATH)

m: 
	$(CC) -g -Wall main.cpp $(INCLUDEPATH)
t:
	$(CC) -g -Wall test.cpp $(INCLUDEPATH)

test:
	 $(CC) -fsanitize=address -g -Wall -lstdc++fs test.cpp $(INCLUDEPATH); ASAN_OPTIONS=detect_leaks=1 ./a.out



hello: main.o factorial.o hello.o
	$(CC) main.o factorial.o hello.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

factorial.o: factorial.cpp
	$(CC) $(CFLAGS) factorial.cpp

hello.o: hello.cpp
	$(CC) $(CFLAGS) hello.cpp

clean:
	rm *.out