project : main.o createlist.o file.o menu.o update.o
		cc main.o createlist.o file.o menu.o update.o -o project
main.o : main.c main.h
		cc main.c -c  
createlist.o : createlist.c main.h
		cc createlist.c -c
file.o : file.c main.h
		cc file.c -c
menu.o : menu.c main.h
		cc menu.c -c  
update.o : update.c main.h
		cc update.c -c    
