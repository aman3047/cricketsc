/*****************************************************************************
 * Copyright (C) AMAN TADVI amanftadvi@yahoo.co.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#define ANSI_COLOR_RESET   "\x1b[0m"
void write(char *s, team *overall, batsman *team1, bowler *team2, matchinfo *info) { /* writes data to file*/
	FILE *write;
	write = fopen(s, "a+");
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
	fclose(write);	
}
void openfile(char *s) { /*opens new score sheet*/
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
        	candy = fgetc(list);/*it is checked here if file name already exists or not*/
        	a[i] = candy;
        	if(candy == '\n') {
                	a[i] = '\0';
                	i = -1;
                	if(strcmp(a, s) == 0) {
                		printf("File already exists!\n");
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
void searchfile(char *s) { /* searches file and after reading file prints data*/ 
	team overall;
	batsmannode bat;
	bowlernode bowl;
	matchinfo info;
	int l, m;
	int i = 0;
	strcat(s, ".txt");
	FILE *search;
	search = fopen(s, "r");
	if(search == NULL) {
		perror("error :");
		return;
	}
	rewind(search);
	while(i < 2) {
		l = 0;
		m = 0;
		fread(&info, sizeof(matchinfo), 1, search);
		if(i == 0) {
			printf("\e[1mseries name: " ANSI_COLOR_RESET);
			printf("%s \n", info.sname);
			printf("\e[1mteam 1: " ANSI_COLOR_RESET);
			printf("%s\n", info.teama);
			printf("\e[1mteam 2: " ANSI_COLOR_RESET);
			printf("%s\n", info.teamb);
			printf("\e[1mtoss: " ANSI_COLOR_RESET);
			printf("%s\n", info.toss);
			printf("\e[1mvenue: " ANSI_COLOR_RESET);
			printf("%s\n", info.venue);
			printf("\e[1mdate: " ANSI_COLOR_RESET);
			printf("%s\n",info.date);
			printf("\e[1mumpire1 : " ANSI_COLOR_RESET);
			printf("%s\n", info.umpire1);
			printf("\e[1mumpire2 : " ANSI_COLOR_RESET);
			printf("%s\n", info.umpire2);
			printf("\e[1movers : ");
			printf("%d\n", (info.overs));
		}
		fread(&overall, sizeof(team), 1, search);
		printf("\e[1m%d/%d (%0.1f)\n", overall.totalruns, overall.wickets, overall.overs);
		printf("partnership ");
		printf("%d\t",overall.partnership);
		printf("extras ");
		printf("%d\n",overall.extras);
		printf("innings ");
		printf("%d\t",overall.innings);
		printf("runrate");
		printf("%0.2f\n",overall.runrate);
		printf("batsman\t\t");
		printf("r\t");
		printf("b\t");
		printf("4s\t");
		printf("6s\t");
		printf("st\n" ANSI_COLOR_RESET);
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
			printf("%d\t", bat.runs);
			printf("%d\t", bat.balls);
			printf("%d\t", bat.four);
			printf("%d\t", bat.six);
			printf("%0.2f\n", bat.strikerate);
		}
		fread(&l, sizeof(int), 1, search);
		printf("\e[1mName of bowler\t");
		printf("o\t");
		printf("r\t");
		printf("w\t");
		printf("m\t");
		printf("e\t");
		printf("eco\t");
		printf("st\n" ANSI_COLOR_RESET);
		m = 0;
		while(l != m) {
			fread(&bowl, sizeof(bowlernode), 1, search);
			printf("%s\t", bowl.name);
			printf("%0.1f\t", bowl.overs);
			printf("%d\t", bowl.runs);
			printf("%d\t", bowl.wickets);
			printf("%d\t", bowl.maidens);
			printf("%d\t", bowl.extras);
			printf("%0.2f ", bowl.economy);
			if(bowl.strikerate)
				printf("%0.2f", bowl.strikerate);
			printf("\n");
			m++;
		}
		i++;
	}
	printf("\e[1m%s\n" ANSI_COLOR_RESET, overall.result);
	fclose(search);
}
