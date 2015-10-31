#include <stdio.h>
#include"main.h"
char menu() {
	char ch;
	//move(5, 35);
	printf("MENU\n");
	//move(7, 25);
	printf("1. NEW SCORECARD\n");
	//move(9, 25);
	printf("2. OPEN SCORECARD\n");
	//move(11, 25);
	printf("3. BYE\n");
	ch = getchar();
	return ch;
}
