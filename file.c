#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
void write(char *s, team *overall, batsman *team1, bowler *team2, matchinfo *info) {
	FILE *write;
	write = fopen(s, "w");
	if(write == NULL) {
		perror("error :");
		return;
	}
	if(overall->innings == 2)
		fseek(write, 0, SEEK_END);
	int l;
	l = team1->count;
	batsmannode *p;
	bowlernode *q;
	fwrite(info, sizeof(matchinfo), 1, write);
	fwrite(overall, sizeof(team), 1, write);
	fwrite(&l, sizeof(int), 1, write);
	p = team1->head;
	while(p) {
        	fwrite(p, sizeof(batsmannode), 1, write);
		p = p->next;
	}
	q = team2->head;
	l = team2->count;
	fwrite(&l, sizeof(int), 1, write);
	while(q) {
		fwrite(q, sizeof(bowlernode), 1, write);
		q = q->next;
	}
	fwrite(overall->result, sizeof(char), 64, write);
	fclose(write);	
}
void openfile(char *s) {
	team overall;
	batsman team1, team3;
	bowler team2, team4;
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
	overall.innings = 1;
	update(&overall, &team1, &team2, &info);
	write(s, &overall, &team1, &team2, &info);
	printf("press any key to start next innings\n");
	getchar();
	candy = getchar();
	overall.innings = 2;
	update(&overall, &team3, &team4, &info);
	write(s, &overall, &team3, &team4, &info);
	fclose(file);	
}
void searchfile(char *s) {
	team overall;
	batsmannode bat;
	bowlernode bowl;
	matchinfo info;
	char result[64];
	int l = 0, m = 0;
	strcat(s, ".txt");
	FILE *search;
	search = fopen(s, "r");
	if(search == NULL) {
		perror("error :");
		return;
	}
	rewind(search);
	fread(&info, sizeof(matchinfo), 1, search);
	printinfo(&info);
	fread(&overall, sizeof(team), 1, search);
	printf("totalruns\n");
	printf("%d/%d (%0.1f)\n",overall.totalruns, overall.wickets, overall.overs);
	printf("partnership\n");
	printf("%d\n",overall.partnership);
	printf("extras\n");
	printf("%d\n",overall.extras);
	printf("innings\n");
	printf("%d\n",overall.innings);
	printf("runrate\n");
	printf("%0.2f\n",overall.runrate);
	printf("Name of batsman\t");
	//move(16, 15);
	printf("r\t");
	//move(20, 15);
	printf("b\t");
	//move(24, 15);
	printf("4s\t");
	//move(28, 15);
	printf("6s\t");
	//move(32, 15);
	printf("st\n");
	fread(&l, sizeof(int), 1, search);
	while(l != m) {
        	fread(&bat, sizeof(batsmannode), 1, search);
		printf("%s\t", bat.name);
		m++;
		if(bat.runs == -1) {
			printf("\n");
			continue;
		}
		printf("%s\t", bat.status);
		//move(16, x);
		printf("%d\t", bat.runs);
		//move(20, x);
		printf("%d\t", bat.balls);
		//move(24, x);
		printf("%d\t", bat.four);
		//move(28, x);
		printf("%d\t", bat.six);
		//move(32, x);
		printf("%0.2f\n", bat.strikerate);
	}
	fread(&l, sizeof(int), 1, search);
	//move(0, 25);
	printf("Name of bowler\t");
	//move(16, 25);
	printf("o\t");
	//move(20, 25);
	printf("r\t");
	//move(24, 25);
	printf("w\t");
	//move(28, 25);
	printf("m\t");
	//move(32, 25);
	printf("e\t");
	//move(36, 25);
	printf("eco\t");
	//move(40, 25);
	printf("st\n");
	m = 0;
	while(l != m) {
		fread(&bowl, sizeof(bowlernode), 1, search);
		printf("%s\t", bowl.name);
		//move(16, x);
		printf("%0.1f\t", bowl.overs);
		//move(20, x);
		printf("%d\t", bowl.runs);
		//move(24, x);
		printf("%d\t", bowl.wickets);
		//move(28, x);
		printf("%d\t", bowl.maidens);
		//move(32, x);
		printf("%d\t", bowl.extras);
		//move(36, x);
		printf("%0.2f\t", bowl.economy);
		//move(40, x);
		if(bowl.strikerate)
			printf("%0.2f\n", bowl.strikerate);
		m++;
	}
	int u = fread(result, sizeof(char), 64, search);
	result[u] = '\0';
	printf("%s\n", result);
	fclose(search);
	main();
}
