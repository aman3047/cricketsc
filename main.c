#include <stdio.h>
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
int main() {
	char c;
	char *s;
	s = (char *)malloc((sizeof(char)) * 16);
	c = menu();
	switch(c) {
		case '1' :
			printf("enter title\n");
			scanf("%s", s); 
			openfile(s);
			free(s);
			break;
		case '2' :
			printf("scoresheet name\n");
			scanf("%s", s);
			searchfile(s);
			free(s);
			break;
		case '3' :
			exit(1);
	}
	return 0;
}

		
