#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
void openfile(char *s) {
	char *st;
	st = (char *)malloc((sizeof(char)) * 7);
	st = "files/";
	strcat(s, ".txt");
	FILE *list;
	list = fopen("files/records", "a+");
	if(list == NULL) {
		perror("error :");
		return;
	}
	fseek(list,0,SEEK_END);
        fprintf(list,"%s",s);
        fprintf(list,"\n");
        fclose(list);	
	strcat(s, ".txt");
	strcat(st, s);
	FILE *file = fopen(st, "w");
	if(file == NULL) {
		perror("error :");
		return;
	}
	display();	
}
void searchfile(char *s) {
	char *st;
	st = (char *)malloc((sizeof(char)) * 7);
	st = "files/";
	strcat(s, ".txt");
	strcat(st, s);
	FILE *search;
	search = fopen(st,"r");
	if(search == NULL) {
		perror("error :");
		return;
	}
	fread(&team, sizeof(team, 1, search);
        fread(&batsman, sizeof(batsmannode, 11, search);
	fread(&bowler, sizeof(bowlernode, 11, search);
        fread(&matchinfo, sizeof(matchinfo, 1, search);
	main();
}

	


