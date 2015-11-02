#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
void write(char *s, team *overall, batsman *team1, bowler *team2, matchinfo *info) {
	strcat(s, ".txt");
	FILE *write;
	write = fopen(s, "w");
	if(write == NULL) {
		perror("error :");
		return;
	}
	fwrite(overall, sizeof(team), 1, write);
        fwrite(team1, sizeof(batsmannode), 11, write);
	fwrite(team2, sizeof(bowlernode), 11, write);
        fwrite(info, sizeof(matchinfo), 1, write);
	fclose(write);	
}
void openfile(char *s) {
	team overall;
	batsman team1;
	bowler team2;
	matchinfo info;
	char candy;
	char a[32];
	int i = 0;
	strcat(s, ".txt");
	FILE *list;
	list = fopen("records", "a+");
	if(list == NULL) {
		perror("error :");
		return;
	}
	while(candy != EOF) {
        	candy = fgetc(list);
        	a[i] = candy;
        	if(candy == '\n') {
                	a[i] = '\0';
                	i = -1;
                	if(strcmp(a, s) == 0) {
                		printf("File already exists!");
				scanf("%s", s);
				strcat(s, ".txt");
                		break;
               		}
            	}
            	i++;
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
	getinfo(&info);
	update(&overall, &team1, &team2, &info);
	write(s, &overall, &team1, &team2, &info);
	fclose(file);	
}
void searchfile(char *s) {
	team overall;
	batsman team1;
	bowler team2;
	matchinfo info;
	strcat(s, ".txt");
	FILE *search;
	search = fopen(s, "r");
	if(search == NULL) {
		perror("error :");
		return;
	}
	rewind(search);
	fread(&overall, sizeof(team), 1, search);
        fread(&team1, sizeof(batsmannode), 11, search);
	fread(&team2, sizeof(bowlernode), 11, search);
        fread(&info, sizeof(matchinfo), 1, search);
	printinfo(&info);
	display(&team1, &team2, &overall);
	fclose(search);
	main();
}
