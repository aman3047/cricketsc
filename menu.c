#include <stdio.h>
#include"main.h"
char menu() {
	char ch;
	//move(5, 35);
	printf("MENU");
	//move(7, 25);
	printf("1. NEW SCORECARD");
	//move(9, 25);
	printf("2. OPEN SCORECARD");
	//move(11, 25);
	printf("3. BYE");
	ch = getchar();
	return ch;
}
