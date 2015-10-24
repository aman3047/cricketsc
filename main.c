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
<<<<<<< HEAD
			scanf("%[^\n]", s); 
			opennewfile(s);
		case '2' :
			printf("scoresheet name\n");
			scanf("%[^\n]", s);
=======
			scanf("%s", s); 
			opennewfile(s);
		case '2' :
			printf("scoresheet name\n");
			scanf("%s", s);
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
			searchfile(s);
		case '3' :
			exit(1);
	}
	return 0;
}

		
