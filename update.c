#include <stdio.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <ctype.h>
int runs = -1;
char *ab = NULL;
int wrong = 0;
char name[16];
<<<<<<< HEAD
int dot = 0;
batsmannode *onstrike, *offstrike;
bowlernode *bowling;
=======
batsmannode *onstrike, *offstrike;
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
int scorepredict(team *overall, matchinfo *info) {
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
void changestrike() {
=======

void changestrike(batsmannode *onstrike, batsmannode *offstrike) {
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
	batsmannode *temp;
	temp = onstrike;
	onstrike = offstrike;
	offstrike = temp;
}
<<<<<<< HEAD
void newbatsman(batsman *team1, char ci) {
	char name[16];
	batsmannode *on;
	printf("enter name of batsman :\n");
	scanf("%[^\n]", name);
	if(ci == 'c' || ci == 'r') {
		printf("is new batsman on strike ? y/n ");
		ci = getchar();
		if(ci == 'y')
			on = onstrike = send_batsman(team1, name);
		else
			on = offstrike = send_batsman(team1, name);
	}
	else
		on = onstrike = send_batsman(team1, name);
	taking_guard(on);
}	
void changebowler(bowler *team2) {
=======
void newbatsman(batsman *team1, batsmannode *on) {
	char name[16];
	printf("enter name of batsman :\n");
	scanf("%[^\n]", name);
	on =  send_batsman(team1, name);
	taking_guard(on);
}	
void changebowler(bowler *team2, bowlernode *bowling) {
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
	bowlernode *newbowler;
	printf("enter name of bowler:\n");
	scanf("%[^\n]", name);
	newbowler = searchbowler(team2, name);
	if(newbowler == bowling){
		printf("change bowler\n");
<<<<<<< HEAD
		changebowler(team2);
=======
		changebowler(team2, bowling);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
	}
	else if(newbowler)
		bowling = newbowler;
	else {
		bowling = give_bowl(team2, name);
		shining_bowl(bowling);
	}
}	
<<<<<<< HEAD
void wicket(batsman *team1, team *overall) {
	printf("how batsman got out?\n");
	printf("bowled(b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t), time out(o), \n");
	char ch;	
	char *e, *f, *b, *d, *c, *p;	
=======
void wicket(batsman *team1, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, team *overall) {
	printf("how batsman got out?\n");
	printf("bowled (b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t)\n");
	char ch, ci;	
	char *e, *f, *b, *d, *c;	
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9 + strlen(f))));
=======
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) +strlen(onstrike->name) + 9 + strlen(f))));
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, c);
			strcat(overall->lastwicket, f);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			free(b);
			free(f);
			free(c);
<<<<<<< HEAD
			newbatsman(team1, 'c');
=======
			newbatsman(team1, onstrike);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
			newbatsman(team1, 'b');
=======
			newbatsman(team1, onstrike);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
			newbatsman(team1, 'l');
=======
			newbatsman(team1, onstrike);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
			newbatsman(team1, 't');
			break;
		case 'h' :
			e = (char *)malloc((sizeof(char)) * 16);
			e = " retired hurt ";
=======
			newbatsman(team1, onstrike);
			break;
		case 'h' :
			e = (char *)malloc((sizeof(char)) * 16);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
			overall->lastwicket = (char *)malloc(sizeof(char) * (strlen(onstrike->name) + strlen(e) + 1));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, e);
			free(e);
<<<<<<< HEAD
			newbatsman(team1, 'h');
=======
			newbatsman(team1, onstrike);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
			break;
		case 'r' :
			overall->wickets++;
			f = (char *)malloc((sizeof(char)) * 16);
<<<<<<< HEAD
			f = " run out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(f) + strlen(onstrike->name) + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, f);
			free(f);
			newbatsman(team1, 'r');
			break;
		case 'o' :
			overall->wickets++;
			p = (char *)malloc((sizeof(char) * 16));
			p = " time out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(p) + strlen(onstrike->name) + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, p);
			free(p);
			newbatsman(team1, 'r');
			break;
	}
}				 
void add_runs_with_extra(bowler *team2, team *overall) {
	if((ab[0] == 'n') && runs > 1)	
		onstrike->runs += runs - 1;
	bowling->runs += runs;
	if(runs == 0)
		dot++;
=======
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
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
		changebowler(team2);
		changestrike();
=======
		changebowler(team2, bowling);
		changestrike(onstrike, offstrike);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
	}
	overall->totalruns += runs;
	overall->runrate = overall->totalruns / overall->overs;
	overall->partnership = overall->partnership + runs;
	overall->extras += runs;
	bowling->extras += runs;
<<<<<<< HEAD
	if(overall->innings == 2) {
		overall->target = overall->target - overall->totalruns;
		overall->reqrate = overall->target / (50 - overall->overs);
	}
	runs = -1;
	ab = NULL;
}	
void add_runs_with_no_extra(bowler *team2, team *overall) {
=======
	runs = -1;
	ab = NULL;
}	
void add_runs_with_no_extra(bowler *team2, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, team *overall) {
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
	onstrike->runs += runs;
	bowling->runs += runs;
	onstrike->balls++;
	onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
<<<<<<< HEAD
	if(runs == 0)
		dot++;
=======
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
		changebowler(team2);
		changestrike();
		if(dot == 6)
			bowling->maidens++;
		dot = 0;
	}
	if(overall->innings == 2) {
		overall->target = overall->target - overall->totalruns;
		overall->reqrate = overall->target / (50 - overall->overs);
=======
		changebowler(team2, bowling);
		changestrike(onstrike, offstrike);
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
=======
	bowlernode *bowling;
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
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
<<<<<<< HEAD
			add_runs_with_no_extra(&team2, &overall);
		else {
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e')
				add_runs_with_extra(&team2, &overall);
			else
				wicket(&team1, &overall);
		}			
	}
}		
=======
			add_runs_with_no_extra(&team2, onstrike, offstrike, bowling, &overall);
		else {
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e')
				add_runs_with_extra(&team2, onstrike, bowling, &overall);
			else
				wicket(&team1, onstrike, offstrike, bowling, &overall);
		}			
	}
}
		
			
>>>>>>> 6e73ec74f4a61b39baf15146f1b5f77027130f3b
