
all: build run clear
build: 2sem_lab6
	gcc -Wall -O0 -g3 -DDEBUG  2sem_lab6 -o programm.exe
	
run: programm.exe
	./programm.exe
	
clean: 
	rm -rf *.o programm.exe
