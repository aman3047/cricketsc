project : main.o creatlist.o file.o menu.o update.o print.o
		cc main.o creatlist.o file.o menu.o update.o print.o -o  project
creatlist.o : creatlist.c main.h
		cc creatlist.c -c -Wall
file.o : file.c main.h
		cc file.c -c -Wall
menu.o : menu.c main.h
		cc menu.c -c -Wall
update.o : update.c main.h
		cc update.c -c -Wall    
print.o : print.c main.h
		cc print.c -c -Wall
main.o : main.c main.h
		cc main.c -c  -Wall

