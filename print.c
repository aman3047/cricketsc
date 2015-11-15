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
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
char *a = "%[^\n]";
void move(int x, int y) {
	printf("\033[%d;%df", y, x);
}
void printbat(batsman *bat, batsmannode *onstrike, batsmannode *offstrike) {
	batsmannode  *temp;
	temp = bat->head;
	int x = 6; 
	while(temp) {
		move(0, x);
		if(temp == onstrike)
			printf(ANSI_COLOR_BLUE "%s*\t", temp->name);
		else if(temp == offstrike)
			printf(ANSI_COLOR_BLUE "%s\t", temp->name);
		else
			printf("%s\t", temp->name);
		if(temp->runs == -1) {
			continue;
		}
		move(16, x);
		printf("%s\t", temp->status);
		move(40, x);
		printf("%d\t", temp->runs);
		move(44, x);
		printf("%d\t", temp->balls);
		move(48, x);
		printf("%d\t", temp->four);
		move(52, x);
		printf("%d\t", temp->six);
		move(56, x);
		printf("%0.2f\n" ANSI_COLOR_RESET, temp->strikerate);
		temp = temp->next;
		x++;
	}
} 
void printbowl(bowler *bowl, bowlernode *bowling) {
	bowlernode  *temp;
	temp = bowl->head;
	int x = 16;
	while(temp) {
		move(0, x);
		if(temp == bowling)
			printf(ANSI_COLOR_BLUE "%s*\t", temp->name);
		else 
			printf("%s\t", temp->name);
		move(16, x);
		printf("%0.1f\t", temp->overs);
		move(20, x);
		printf("%d\t", temp->runs);
		move(24, x);
		printf("%d\t", temp->wickets);
		move(28, x);
		printf("%d\t", temp->maidens);
		move(32, x);
		printf("%d\t", temp->extras);
		move(36, x);
		printf("%0.2f\t", temp->economy);
		move(42, x);
		if(temp->strikerate)
			printf("%0.2f\n" ANSI_COLOR_RESET, temp->strikerate);
		else 
			printf(" -\n" ANSI_COLOR_RESET);
		temp = temp->next;
		x++;
	}
}
char *date() {
	struct tm *tm_now;
	time_t now;	
	char b[16];
	char *r;
	r = (char *)malloc((sizeof(char)) * 16);
	now = time (NULL);
	tm_now = localtime(&now);
	strftime(b, sizeof b, "%a %d %m %Y", tm_now);
	strcpy(r, b);
	return r;
}
void getinfo(matchinfo *info) {
	char *s;
	s = (char *)malloc((sizeof(char)) * 16);
	move(0, 5);
	printf("\e[1mseries name: " ANSI_COLOR_RESET);
	getchar();
	move(13, 5);
	scanf(a, info->sname);
	move(0, 6);
	printf("\e[1mteam 1: " ANSI_COLOR_RESET);
	getchar();
	move(9, 6);
	scanf(a, info->teama);
	move(20, 6);
	printf("\e[1mteam 2 : " ANSI_COLOR_RESET);
	getchar();
	move(29, 6);
	scanf(a, info->teamb);
	move(40, 6);
	printf("\e[1mteam batting first : " ANSI_COLOR_RESET);
	getchar();
	move(60, 6);
	scanf(a, info->fbat);
	move(0, 7);
	getchar();
	printf("\e[1mtoss: " ANSI_COLOR_RESET);
	move(7, 7); 
	scanf(a, info->toss);
	move(0, 8);
	printf("\e[1mvenue: " ANSI_COLOR_RESET);
	move(8, 8);
	getchar();
	scanf(a, info->venue);
	move(25, 8);
	getchar();
	printf("\e[1mdate: " ANSI_COLOR_RESET);
	s = date();
	move(33, 8);
	printf("%s", s);
	strcpy(info->date, s);
	move(0,9);
	printf("\e[1mumpire1 : " ANSI_COLOR_RESET);
	move(11, 9);
	getchar();
	scanf(a, info->umpire1);
	move(25, 9);
	printf("\e[1mumpire2 : " ANSI_COLOR_RESET);
	move(36, 9);
	getchar();
	scanf(a, info->umpire2);
	move(0, 10);
	printf("\e[1movers : " ANSI_COLOR_RESET);
	getchar();
	move(18, 10);
	scanf("%d", &(info->overs));
	getchar();
	free(s);
}
void printinfo(matchinfo *info) {
	move(0, 5);
	printf("\e[1mseries name: " ANSI_COLOR_RESET);
	move(13, 5);
	printf("%s", info->sname);
	move(0, 6);
	printf("\e[1mteam 1: " ANSI_COLOR_RESET);
	move(9, 6);
	printf("%s", info->teama);
	move(20, 6);
	printf("\e[1mteam 2: " ANSI_COLOR_RESET);
	move(29, 6);
	printf("%s", info->teamb);
	move(0, 7);
	printf("\e[1mtoss: " ANSI_COLOR_RESET);
	move(7, 7); 
	printf("%s", info->toss);
	move(0, 8);
	printf("\e[1mvenue: " ANSI_COLOR_RESET);
	move(8, 8);
	printf("%s", info->venue);
	move(25, 8);
	printf("\e[1mdate: " ANSI_COLOR_RESET);
	move(33, 8);
	printf("%s",info->date);
	move(0,10);
	printf("\e[1mumpire1 : " ANSI_COLOR_RESET);
	move(11, 10);
	printf("%s", info->umpire1);
	move(25, 10);
	printf("\e[1mumpire2 : " ANSI_COLOR_RESET);
	move(36, 10);
	printf("%s", info->umpire2);
	printf("\e[1movers : ");
	printf("%d", (info->overs));
} 			 			
void display(batsman *team1, bowler *team2, team *overall, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, matchinfo *info) {
	system("clear");	
	move(0,5);
	printf("\e[1mbatsman"ANSI_COLOR_RESET);
	move(40, 5);
	printf("\e[1mr"ANSI_COLOR_RESET);
	move(44, 5);
	printf("\e[1mb"ANSI_COLOR_RESET);
	move(48, 5);
	printf("\e[1m4s"ANSI_COLOR_RESET);
	move(52, 5);
	printf("\e[1m6s"ANSI_COLOR_RESET);
	move(56, 5);
	printf("\e[1mst"ANSI_COLOR_RESET);
	printbat(team1, onstrike, offstrike);
	move(0, 15);
	printf("\e[1mbowler");
	move(16, 15);
	printf("o");
	move(20, 15);
	printf("\e[1mr");
	move(24, 15);
	printf("\e[1mw");
	move(28, 15);
	printf("\e[1mm");
	move(32, 15);
	printf("e");
	move(36, 15);
	printf("\e[1meco");
	move(42, 15);
	printf("\e[1mst"ANSI_COLOR_RESET);
	printbowl(team2, bowling);
	move(0, 1);
	printf("\e[1m%s %d/%d (%0.1f)" ANSI_COLOR_RESET,info->fbat, overall->totalruns, overall->wickets, overall->overs);
	move(0, 2);
	printf("\e[1mpartnership ");
	printf("%d",overall->partnership);
	move(40, 2);
	if(overall->lastwicket) {
		printf("\e[1mlastwicket ");
		printf("%s",overall->lastwicket);
	}
	move(15, 2);
	printf("\e[1mextras ");
	printf("%d  ",overall->extras);
	move(25, 2);
	printf("\e[1minnings ");
	printf("%d  ",overall->innings);
	if(overall->innings == 2) {
		move(0, 3);
		printf("\e[1mreqrate ");
		printf("%0.2f",overall->reqrate);
		move(22, 3);
		printf("\e[1mtarget ");
		printf("%d ",overall->target);
		move(35, 3);
		printf("\e[1mwinning percentage ");
		printf("%d",overall->pscore);	
	}
	else {	
		move(0, 3);	
		printf("\e[1mprojected score ");
		printf("%d ",overall->pscore);
	}
	move(0,4);
	printf("\e[1mrunrate " ANSI_COLOR_RESET);
	printf("%0.2f ",overall->runrate);
}
