#include <stdio.h>
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
int main() {
	char c;
	char *s;
	s = (char *)malloc((sizeof(char)) * 16);
	c = menu();
	FILE *new;
	switch(c) {
		case '1' :
			printf("enter title\n");
			scanf("%s", s); 
			openfile(s);
			free(s);
		case '2' :
			printf("scoresheet name\n");
			scanf("%s", s);
			searchfile(s);
			free(s);
		case '3' :
			exit(1);
	}
	return 0;
}

		
