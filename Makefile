
all: build clear
build: main.c
	gcc -Wall -O0 -g3 -DDEBUG  main.c -o programm.exe
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm.exe
