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
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <ctype.h>
int runs = -1;
char *ab = NULL;
int wrong = 0;
char name[16];
int dot = 0;
#define ANSI_COLOR_RESET   "\x1b[0m"
batsmannode *onstrike, *offstrike;
bowlernode *bowling;
bowlernode *searchbowler(bowler *bowl, char *name) { /*searches bowler in the list*/
	bowlernode *temp;
	temp = bowl->head;
	while(temp){
		if((strcmp(temp->name, name)) == 0)
			return temp;
		temp = temp->next;
	}
	return NULL;
}
int scorepredict(team *overall, matchinfo *info) { /*predicts score and winnig percentage*/
	int score;
	int percent;
	if(overall->innings == 1) {
		if(overall->overs <= (info->overs * 0.30))
			score = overall->totalruns + overall->runrate * (info->overs - overall->overs);
		else if((overall->overs > (info->overs * 0.30)) && (overall->overs <= (info->overs * 0.8)))
			score = overall->totalruns + overall->totalruns * (info->overs / overall->overs);
		else
			score = overall->totalruns + overall->runrate * 10;
		return score;
	}
	else {
		if((overall->runrate == overall->reqrate) && (overall->wickets <= 3))
			percent = 75;
		else if((overall->runrate == overall->reqrate && overall->wickets > 3) && (overall->wickets <= 5))
			percent = 65;
		else if((overall->runrate == overall->reqrate) && (overall->wickets > 5))
			percent = 55;
		else if((overall->runrate < overall->reqrate) && (overall->wickets <= 3))
			percent = 65;
		else if((overall->runrate < overall->reqrate) && (overall->wickets > 3) && (overall->wickets <= 5))
			percent = 57;
		else if((overall->runrate < overall->reqrate) && (overall->wickets > 5))
			percent = 45;
		else if((overall->runrate > overall->reqrate) && (overall->wickets <= 3))
			percent = 84;
		else if((overall->runrate > overall->reqrate) && (overall->wickets > 3) && (overall->wickets <= 5))
			percent = 70;
		else if((overall->runrate > overall->reqrate) && (overall->wickets > 5))
			percent = 54;
		else 
			percent = 50;
		return percent;                        
	}	
}
void changestrike() { /*changes strike*/
	batsmannode *temp;
	temp = onstrike;
	onstrike = offstrike;
	offstrike = temp;
}
void newbatsman(batsman *team1, char ci) { /*adds new batsman in batsman list*/
	char name[16];
	char a;
	batsmannode *on;
	move(0, 32);
	printf("enter name of new batsman : ");
	move(30, 32);
	scanf("%s", name);
	if((ci == 'c') || (ci == 'r')) {
		move(0, 33);
		printf("is new batsman on strike ? y/n "); /*in the case of catch and runout , we cannot assume batman is onstrike/offstrike*/ 
		getchar();				   /*as batman may have crossed ends*/		
		move(33, 33);
		a = getchar();
		if(a == 'y') {
			on = onstrike = send_batsman(team1, name);
		}
		else
			on = offstrike = send_batsman(team1, name);
	}
	else 		
		on = onstrike = send_batsman(team1, name);
	taking_guard(on);
}	
void changebowler(bowler *team2) { /* changes bowler at the end of over*/
	bowlernode *newbowler;
	move(0, 28);
	printf("enter name of bowler:\n");
	move(25, 28);
	scanf("%s", name);
	newbowler = searchbowler(team2, name);
	if(newbowler == bowling){ /*if user enters name of current bowler, which not allowed*/
		move(0, 29);
		printf("change bowler\n");
		changebowler(team2);
	}
	else if(newbowler)
		bowling = newbowler;
	else {
		bowling = give_bowl(team2, name);
		shining_bowl(bowling);
	}
}
void afterwicket(batsman *team1, bowler *team2, team *overall, matchinfo *info) { /*updates bowling info sfter fall of wickets*/
	bowling->overs += 0.1;
	bowling->balls++;
	overall->overs += 0.1;
	overall->balls++;
	dot++;
	bowling->strikerate = (float)bowling->balls / bowling->wickets;
	overall->runrate = (overall->totalruns * 6) / overall->balls;
	bowling->economy = (bowling->runs * 6) / (bowling->balls);
	overall->pscore = scorepredict(overall, info);
	if(((bowling->balls) % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		overall->runrate = (overall->totalruns) / overall->overs;
		bowling->economy = (bowling->runs ) / (bowling->overs);
		display(team1, team2, overall, onstrike, offstrike, bowling, info);
		if((overall->innings == 2)  && (info->overs - overall->overs != 0))
			overall->reqrate = overall->target / (info->overs - overall->overs);
		if(overall->balls != (info->overs * 6)) {
			changebowler(team2);
			changestrike();
		}
	}
	else {
		bowling->economy = ((bowling->runs) * 6) / (bowling->balls);
		overall->runrate = (overall->totalruns * 6) / overall->balls;
		if((overall->innings == 2) && (((info->overs * 6) - overall->balls) != 0))
			overall->reqrate = (overall->target * 6) / ((info->overs * 6) - overall->balls);
		display(team1, team2, overall, onstrike, offstrike, bowling, info);
	}

}	
void wicket(batsman *team1, bowler *team2, team *overall, matchinfo *info) { /* updates info about wicket fall*/
	char s[64];
	char *e, *f, *b, *d, *c, *p;
	char cj;
	int bo, on;
	bo = strlen(bowling->name);
	on = strlen(onstrike->name);
	if(overall->lastwicket)
		free(overall->lastwicket);
	getchar();
	cj = getchar();	
	switch(cj) {
		case 'c' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			c = (char *)malloc((sizeof(char)) * 4);
			c = " c ";
			f = (char *)malloc((sizeof(char)) * 16);
			b = (char *)malloc((sizeof(char)) * 4);
			b = " b ";
			move(0, 30);
			printf("enter name of catcher\n");
			move(0, 31);
			scanf("%s", f);
			strcpy(s, c);
			strcat(s, f);
			strcat(s, b);
			strcat(s, bowling->name);
			overall->lastwicket = (char *)malloc(sizeof(char) * ((bo + on + 9 + strlen(f))));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, s);
			strcpy(onstrike->status, s);
			free(f);
			newbatsman(team1, 'c');
			afterwicket(team1, team2, overall, info);
			break;
		case 'b' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			b = (char *)malloc((sizeof(char)) * 4);
			b = " b ";
			strcpy(s, b);
			strcat(s, bowling->name);
			overall->lastwicket = (char *)malloc(sizeof(char) * ((bo + on + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcpy(onstrike->status, s);
			strcat(overall->lastwicket, s);
			newbatsman(team1, 'b');
			afterwicket(team1, team2, overall, info);
			break;
		case 'l' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			b = (char *)malloc((sizeof(char)) * 4);
			b = " l ";
			strcpy(s, b);	
			strcat(s, bowling->name);
			overall->lastwicket = (char *)malloc(sizeof(char) * ((bo + on + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcpy(onstrike->status, s);
			strcat(overall->lastwicket, s);
			newbatsman(team1, 'l');
			afterwicket(team1, team2, overall, info);
			break;
		case 't' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			d = (char *)malloc((sizeof(char)) * 5);
			d = " ht ";
			strcpy(s, d);
			strcat(s, bowling->name);
			overall->lastwicket = (char *)malloc(sizeof(char) * ((bo + on + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcpy(onstrike->status, s);
			strcat(overall->lastwicket, s);
			newbatsman(team1, 't');
			afterwicket(team1, team2, overall, info);
			break;
		case 'h' :
			e = (char *)malloc((sizeof(char)) * 16);
			e = " retired hurt ";
			overall->lastwicket = (char *)malloc(sizeof(char) * (on + strlen(e) + 1));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, e);
			strcpy(onstrike->status, e);
			onstrike->balls++;
			newbatsman(team1, 'h');
			afterwicket(team1, team2, overall, info);
			break;
		case 'r' :
			overall->wickets++;
			onstrike->balls++;
			f = (char *)malloc((sizeof(char)) * 16);
			f = " run out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(f) + on + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, f);
			strcpy(onstrike->status, f);
			newbatsman(team1, 'r');
			afterwicket(team1, team2, overall, info);
			break;
		case 'o' :
			overall->wickets++;
			onstrike->balls++;
			p = (char *)malloc((sizeof(char) * 16));
			p = " time out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(p) + on + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, p);
			strcpy(onstrike->status, p);
			newbatsman(team1, 'o');
			afterwicket(team1, team2, overall, info);
			break;
		default :
			move(0, 28);
			printf("invalid input");
	}
}				 
void add_runs_with_extra(batsman *team1, bowler *team2, team *overall, matchinfo *info) { /*as function name suggets, it updates total info*/	
	if((ab[0] == 'n') && runs > 1)	
		onstrike->runs += runs - 1;
	bowling->runs += runs;
	if(runs == 0)
		dot++;
	if(ab[0] == 'e') {
		overall->overs += 0.1;
		onstrike->balls++;
	}
	if(onstrike->balls)
		onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
	if((runs == 5) && (ab[0] == 'n')) {
		onstrike->four++;
		printf("10\n");
	}
	else if((runs == 7) && (ab[0] == 'n')) {  
		onstrike->six++;
		printf("11\n");
	}
	else if(runs == 2 || runs == 4 || runs == 6) {
		changestrike(onstrike, offstrike);
		printf("12\n");
	}
	if(ab[0] == 'e') {
		bowling->overs += 0.1;
		bowling->balls++;
	}
	if(bowling->wickets)
		bowling->strikerate = (bowling->balls) / (bowling->wickets);
	bowling->economy = ((bowling->runs) * 6) / (bowling->balls);
	overall->runrate = (float)(overall->totalruns * 6) / overall->balls;	
	overall->totalruns += runs;
	overall->partnership = overall->partnership + runs;
	overall->extras += runs;
	bowling->extras += runs;
	if((overall->innings == 2)) {
		overall->target = overall->target - runs;
		if(((info->overs * 6) - overall->balls) != 0)
			overall->reqrate = (overall->target * 6) / ((info->overs * 6) - overall->balls);
	}
	runs = -1;
	ab = NULL;
	overall->pscore = scorepredict(overall, info);
	if((((bowling->balls) % 6) == 0) && (bowling->balls != 0)) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		overall->runrate = (overall->totalruns) / overall->overs;
		bowling->economy = (bowling->runs ) / (bowling->overs);
		if((overall->innings == 2) && (info->overs - overall->overs != 0))
			overall->reqrate = overall->target / (info->overs - overall->overs);
		display(team1, team2, overall, onstrike, offstrike, bowling, info);
		if(overall->balls != (info->overs * 6)) {
			changebowler(team2);
			changestrike();
		}
	}
	else
		display(team1, team2, overall, onstrike, offstrike, bowling, info);
}	
void add_runs_with_no_extra(batsman *team1, bowler *team2, team *overall, matchinfo *info) {
	onstrike->runs += runs;
	bowling->runs += runs;
	onstrike->balls++;
	overall->balls++;
	onstrike->strikerate = ((onstrike->runs) * 100) / (onstrike->balls);
	if(runs == 0)
		dot++;
	if(runs == 4)
		onstrike->four++;
	else if(runs == 6)  
		onstrike->six++;
	else if(runs == 1 || runs == 3 || runs == 5)
		changestrike(onstrike, offstrike);
	bowling->overs += 0.1;
	bowling->balls++;
	if(bowling->wickets)
		bowling->strikerate = (bowling->balls) / (bowling->wickets);
	bowling->economy = ((bowling->runs) * 6) / (bowling->balls);
	overall->overs += 0.1;
	if(overall->innings == 2) {
		overall->target = overall->target - runs;
		if(((info->overs * 6) - overall->balls) != 0)
			overall->reqrate = (overall->target * 6) / ((info->overs * 6) - overall->balls);
	}
	overall->totalruns += runs;
	overall->runrate = (float)(overall->totalruns * 6) / overall->balls;
	overall->partnership = overall->partnership + runs;
	runs = -1;
	overall->pscore = scorepredict(overall, info);
	if((bowling->balls % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		overall->runrate = overall->totalruns / overall->overs;
		bowling->economy = (bowling->runs) / (bowling->overs);
		if((overall->innings == 2) && (info->overs - overall->overs != 0))
			overall->reqrate = overall->target / (info->overs - overall->overs);
		changestrike();
		if(dot == 6)
			bowling->maidens++;
		dot = 0;
		display(team1, team2, overall, onstrike, offstrike, bowling, info);
		if(overall->balls != (info->overs * 6)) {
			changebowler(team2);
			changestrike();
		}
	}
	else
		display(team1, team2, overall, onstrike, offstrike, bowling, info);
}		 
void input(char *a) { /* divides input srting into runs and char, e.g. two extras are scored(2e), then it divides 2e into 2 and e*/
	int i = 0;
	int j = 0;
	int k = 0;
	if(ab)
		free(ab);
	ab = (char *)malloc(sizeof(char) * 2);
	while(a[i] != '\0') {
		if(isdigit(a[i])) {
			runs = a[i] - '0';
			i++;
			k++;
			if(k >= 2) {
				wrong = 1;
				runs = -1;
				return;
			}
		}
		else {
			if(a[i] == 'w'|| a[i] == 'y'|| a[i] == 'n'|| a[i] ==  'e') {
				ab[j] = a[i];
				j++;
				i++;
			}
			else if(j >= 2) {
				wrong = 1;
				return;
			}
			else {
				wrong = 1;
				return;
			}
		}
	}
	ab[j] = '\0';
}			
void update(team *overall, batsman *team1, bowler *team2, matchinfo *info) { /*it is main updater function*/
	char a[4];
	char *e = "%s";
	int v;
	system("clear");
	start(overall);
	in_the_ground(team1);
	warming_up(team2);
	move(10, 11);
	printf("\e[1menter name of batsman on stike: " ANSI_COLOR_RESET);
	move(45, 11);
	scanf(e, name);
	onstrike = send_batsman(team1, name);
	move(10, 12);
	printf("\e[1menter name of batsman off strike:"  ANSI_COLOR_RESET);
	move(45, 12);
	scanf(e, name);
	offstrike = send_batsman(team1, name);
	taking_guard(onstrike);
	taking_guard(offstrike);
	move(10, 13);
	printf("\e[1menter name of bowler: "  ANSI_COLOR_RESET);
	move(35, 13);		
	scanf(e, name);	
	bowling = give_bowl(team2, name);
	shining_bowl(bowling);
	while((overall->balls != (info->overs * 6)) && (overall->wickets != 10)) {
		move(0, 26);     	
		printf("\e[1menter runs made , wicket(w), wide(y), noball(n), extra(e) end inning(esc)"  ANSI_COLOR_RESET);
		move(0, 27);		
		scanf("%s", a);
		if(a[0] == 27)
			break;
		input(a);
		if(wrong) {
			move(0, 28);
			printf("\e[1mINVALIND INPUT:"  ANSI_COLOR_RESET);
			move(0, 27);
			printf("\t");
			wrong = 0;
			continue;
		}
		else if(ab[0] == '\0')
			add_runs_with_no_extra(team1, team2, overall, info);
		else {			
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e') {
				add_runs_with_extra(team1, team2, overall, info);
			}
			else {
				move(0,28);
				printf("\e[1mbowled(b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t), time out(o)"  ANSI_COLOR_RESET);
				move(0, 29);
				wicket(team1, team2, overall, info);			
			}
		}
		if((overall->innings == 2) && overall->target <= 0) 
			break;			
	}
	if(strcmp(onstrike->status, " batting ") == 0) 
		strcpy(onstrike->status, " not out ");
	if(strcmp(offstrike->status, " batting ") == 0) 
		strcpy(offstrike->status, " not out ");
	if(overall->wickets != 10) {
		move(0, 30);
		printf("\e[1menter names of remaining players"  ANSI_COLOR_RESET);
		v = overall->wickets;
		while(v != (9 - overall->wickets)) {
			scanf("%s", name);
			offstrike = send_batsman(team1, name);
			did_not_bat(offstrike);
			v++;
		}
	}
	system("clear");
	if(overall->innings == 2) {
		move(0, 27);
		printf("\e[1menter result"  ANSI_COLOR_RESET);
		getchar();
		move(13, 28);
		scanf("%[^\n]", overall->result);
	}
	system("clear");
	if(overall->innings ==  1) {
		overall->innings = 2;
		overall->target = overall->totalruns + 1;
	}
}		
