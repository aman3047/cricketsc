#include <stdio.h>
#include <main.h>
char menu() {
	char ch;
	move(5, 35);
	printw("MENU");
	move(7, 25);
	printw("1. NEW SCORECARD");
	move(9, 25);
	printw("2. OPEN SCORECARD");
	move(11, 25);
	printw("3. BYE");
	ch = getchar();
	return ch;
}
