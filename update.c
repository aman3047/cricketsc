#include <stdio.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <ctype.h>
int runs = -1;
char *ab = NULL;
int wrong = 0;
char name[16];
batsmannode *onstrike, *offstrike;
bowlernode *searchbowler(bowler *bowl, char *name) {
	bowlernode *temp;
	temp = bowl->head;
	while(temp){
		if((strcmp(temp->name, name)) == 0)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void changestrike(batsmannode *onstrike, batsmannode *offstrike) {
	batsmannode *temp;
	temp = onstrike;
	onstrike = offstrike;
	offstrike = temp;
}
void newbatsman(batsman *team1, batsmannode *on) {
	char name[16];
	printf("enter name of batsman :\n");
	scanf("%[^\n]", name);
	on =  send_batsman(team1, name);
	taking_guard(on);
}	
void changebowler(bowler *team2, bowlernode *bowling) {
	bowlernode *newbowler;
	printf("enter name of bowler:\n");
	scanf("%[^\n]", name);
	newbowler = searchbowler(team2, name);
	if(newbowler == bowling){
		printf("change bowler\n");
		changebowler(team2, bowling);
	}
	else if(newbowler)
		bowling = newbowler;
	else {
		bowling = give_bowl(team2, name);
		shining_bowl(bowling);
	}
}	
void wicket(batsman *team1, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, team *overall) {
	printf("how batsman got out?\n");
	printf("bowled (b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t)\n");
	char ch, ci;	
	char *e, *f, *b, *d, *c;	
	ch = getchar();
	switch (ch) {
		case 'c' :
			bowling->wickets++;
			overall->wickets++;
			c = (char *)malloc((sizeof(char)) * 4);
			c = " c ";
			f = (char *)malloc((sizeof(char)) * 16);
			b = (char *)malloc((sizeof(char)) * 4);
			b = " b ";
			printf("enter name of catcher\n");
			scanf("%[^\n]", f); 
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) +strlen(onstrike->name) + 9 + strlen(f))));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, c);
			strcat(overall->lastwicket, f);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			free(b);
			free(f);
			free(c);
			newbatsman(team1, onstrike);
			break;
		case 'b' :
			bowling->wickets++;
			overall->wickets++;
			b = (char *)malloc((sizeof(char)) * 4);
			b = " b ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			free(b);
			newbatsman(team1, onstrike);
			break;
		case 'l' :
			bowling->wickets++;
			overall->wickets++;
			b = (char *)malloc((sizeof(char)) * 4);
			b = " l ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			free(b);
			newbatsman(team1, onstrike);
			break;
		case 't' :
			bowling->wickets++;
			overall->wickets++;
			d = (char *)malloc((sizeof(char)) * 5);
			d = " ht ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, d);
			strcat(overall->lastwicket, bowling->name);
			newbatsman(team1, onstrike);
			break;
		case 'h' :
			e = (char *)malloc((sizeof(char)) * 16);
			overall->lastwicket = (char *)malloc(sizeof(char) * (strlen(onstrike->name) + strlen(e) + 1));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, e);
			free(e);
			newbatsman(team1, onstrike);
			break;
		case 'r' :
			overall->wickets++;
			f = (char *)malloc((sizeof(char)) * 16);
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(f) + strlen(onstrike->name) + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, f);
			strcat(overall->lastwicket, bowling->name);
			free(f);
			printf("is new batsman on strike ? y/n ");
			ci = getchar();
			if(ci == 'y')
				newbatsman(team1, onstrike);
			else
				newbatsman(team1, offstrike);
			break;
	}
}				 
void add_runs_with_extra(bowler *team2, batsmannode *onstrike, bowlernode *bowling, team *overall) {
	if((ab[0] == 'n') && runs > 1)	
		onstrike->runs += runs - 1;
	bowling->runs += runs;
	if(ab[0] == 'e')
		onstrike->balls++;
	onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
	if((runs == 5) && (ab[0] == 'n'))
		onstrike->four++;
	else if((runs == 7) && (ab[0] == 'n'))  
		onstrike->six++;
	else if(runs == 2 || runs == 4 || runs == 6)
		changestrike(onstrike, offstrike);
	if(ab[0] == 'e') {
		bowling->overs += 0.1;
		bowling->balls++;
	}
	if(bowling->wickets)
		bowling->strikerate = (bowling->balls) / (bowling->wickets);
	bowling->economy = (bowling->runs) / (bowling->overs);
	overall->overs += 0.1;
	if(((bowling->balls) % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		changebowler(team2, bowling);
		changestrike(onstrike, offstrike);
	}
	overall->totalruns += runs;
	overall->runrate = overall->totalruns / overall->overs;
	overall->partnership = overall->partnership + runs;
	overall->extras += runs;
	bowling->extras += runs;
	runs = -1;
	ab = NULL;
}	
void add_runs_with_no_extra(bowler *team2, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, team *overall) {
	onstrike->runs += runs;
	bowling->runs += runs;
	onstrike->balls++;
	onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
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
	bowling->economy = (bowling->runs) / (bowling->overs);
	overall->overs += 0.1;
	if((bowling->balls % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		changebowler(team2, bowling);
		changestrike(onstrike, offstrike);
	}
	overall->totalruns += runs;
	overall->runrate = overall->totalruns / overall->overs;
	overall->partnership = overall->partnership + runs;
	runs = -1;
}		 
void input(char *a) {
	int i = 0;
	int j = 0;
	int k = 0;
	if(ab)
		free(ab);
	ab = (char *)malloc(sizeof(char) * 2);
	while(a[i] != 0) {
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
			else 
				wrong = 1;
		}
	}
	ab[j] = '\0';
}			
void update() {
	char a[4];
	team overall;
	start(&overall);
	batsman team1;
	bowler team2;
	in_the_ground(&team1);
	warming_up(&team2);
	matchinfo info;
	printf("enter name of batsman on stike:\n");
	scanf("%[^\n]", name);
	onstrike = send_batsman(&team1, name);
	printf("enter name of batsman off strike:\n");
	scanf("%[^\n]", name);
	offstrike = send_batsman(&team1, name);
	taking_guard(onstrike);
	taking_guard(offstrike);
	bowlernode *bowling;
	printf("enter name of bowler:\n");		
	scanf("%[^\n]", name);	
	bowling = give_bowl(&team2, name);
	shining_bowl(bowling);
	printf("enter runs made , wicket(w), wide(y), noball(n), extra(e)");
	while(overall.overs != info.overs) {     	
		scanf("%[^\n]", a);
		input(a);
		if(wrong) {
			printf("INVALIND INPUT:\n");
			wrong = 0;
		}
		else if(ab == NULL)
			add_runs_with_no_extra(&team2, onstrike, offstrike, bowling, &overall);
		else {
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e')
				add_runs_with_extra(&team2, onstrike, bowling, &overall);
			else
				wicket(&team1, onstrike, offstrike, bowling, &overall);
		}			
	}
}
		
			
