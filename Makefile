project : main.o createlist.o fileopen.o menu.o
		cc main.o createlist.o fileopen.o menu.o -o project
main.o : main.c main.h
		cc main.c -c  
createlist.o : createlist.c main.h
		cc createlist.c -c
fileopen.o : fileopen.c main.h
		cc fileopen.c -c
menu.o : menu.c main.h
		cc menu.c -c      
