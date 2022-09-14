all: Bank
#	@ Bank.exe

#make rule to generate the final binary
Bank: main.o
	@gcc main.o -o Bank.exe
	
main.o: main.c
	@gcc -c main.c