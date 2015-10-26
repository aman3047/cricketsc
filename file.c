#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
void openfile(char *s) {
	strcat(s, ".txt");
	FILE *list;
	list = fopen("records", "a+");
	if(list == NULL) {
		perror("error :");
		return;
	}
	fseek(list, 0, SEEK_END);
        fprintf(list, "%s", s);
        fprintf(list, "\n");
        fclose(list);	
	FILE *file = fopen(s, "w");
	if(file == NULL) {
		perror("error :");
		return;
	}
	display();
	fclose(file);	
}
void searchfile(char *s) {
	strcat(s, ".txt");
	FILE *search;
	search = fopen(s, "r");
	if(search == NULL) {
		perror("error :");
		return;
	}
	fread(&team, sizeof(team, 1, search);
        fread(&batsman, sizeof(batsmannode, 11, search);
	fread(&bowler, sizeof(bowlernode, 11, search);
        fread(&matchinfo, sizeof(matchinfo, 1, search);
	display();
	fclose(search);
	main();
}
