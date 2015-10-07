#include <stdio.h>
#include "main.h"
#include <fcntl.h>
int main() {
	char c;
	char s[16];
	c = menu();
	FILE *new;
	switch(c) {
		case '1' :
			printf("enter title\n");
			scanf("%s", s); 
			opennewfile(s);
		case '2' :
			printf("scoresheet name\n");
			scanf("%s", s);
			searchfile(s);
		case '3' :
			exit(1);
	}
	return 0;
}

		
