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
batsmannode *onstrike, *offstrike;
bowlernode *bowling;
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
	batsmannode *temp;
	temp = onstrike;
	onstrike = offstrike;
	offstrike = temp;
}
void newbatsman(batsman *team1, char ci) {
	char name[16];
	char a;
	batsmannode *on;
	printf("enter name of new batsman :\n");
	scanf("%s", name);
	printf("ci = %c\n", ci);
	if((ci == 'c') || (ci == 'r')) {
		printf("is new batsman on strike ? y/n ");
		getchar();
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
void changebowler(bowler *team2) {
	bowlernode *newbowler;
	printf("enter name of bowler:\n");
	scanf("%s", name);
	newbowler = searchbowler(team2, name);
	if(newbowler == bowling){
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
void wicket(batsman *team1, bowler *team2, team *overall, matchinfo *info) {
	char *e, *f, *b, *d, *c, *p;
	char ch;
	getchar();
	ch = getchar();	
	switch(ch) {
		case 'c' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			overall->overs += 0.1;
			c = (char *)malloc((sizeof(char)) * 4);
			c = " c ";
			f = (char *)malloc((sizeof(char)) * 16);
			b = (char *)malloc((sizeof(char)) * 4);
			b = " b ";
			printf("enter name of catcher\n");
			scanf("%s", f); 
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9 + strlen(f))));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, c);
			strcat(overall->lastwicket, f);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			free(f);
			bowling->overs += 0.1;
			bowling->balls++;
			newbatsman(team1, 'c');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		case 'b' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			overall->overs += 0.1;
			b = (char *)malloc((sizeof(char)) * 4);
			b = " b ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			bowling->overs += 0.1;
			bowling->balls++;
			newbatsman(team1, 'b');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		case 'l' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			overall->overs += 0.1;
			b = (char *)malloc((sizeof(char)) * 4);
			b = " l ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			bowling->overs += 0.1;
			bowling->balls++;
			newbatsman(team1, 'l');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		case 't' :
			bowling->wickets++;
			overall->wickets++;
			onstrike->balls++;
			overall->overs += 0.1;
			d = (char *)malloc((sizeof(char)) * 5);
			d = " ht ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, d);
			strcat(overall->lastwicket, bowling->name);
			bowling->overs += 0.1;
			bowling->balls++;
			newbatsman(team1, 't');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		case 'h' :
			overall->overs += 0.1;
			e = (char *)malloc((sizeof(char)) * 16);
			e = " retired hurt ";
			overall->lastwicket = (char *)malloc(sizeof(char) * (strlen(onstrike->name) + strlen(e) + 1));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, e);
			bowling->overs += 0.1;
			bowling->balls++;
			onstrike->balls++;
			newbatsman(team1, 'h');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		case 'r' :
			overall->overs += 0.1;
			overall->wickets++;
			onstrike->balls++;
			f = (char *)malloc((sizeof(char)) * 16);
			f = " run out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(f) + strlen(onstrike->name) + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, f);
			bowling->overs += 0.1;
			bowling->balls++;
			newbatsman(team1, 'r');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		case 'o' :
			overall->overs += 0.1;
			overall->wickets++;
			onstrike->balls++;
			p = (char *)malloc((sizeof(char) * 16));
			p = " time out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(p) + strlen(onstrike->name) + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, p);
			bowling->overs += 0.1;
			bowling->balls++;
			newbatsman(team1, 'r');
			if(((bowling->balls) % 6) == 0) {
				bowling->overs += 0.4;
				overall->overs += 0.4;
				display(team1, team2, overall);
				if(overall->overs != info->overs) {
					changebowler(team2);
					changestrike();
				}
			}
			else
				display(team1, team2, overall);
			break;
		default :
			printf("invalid input\n");
	}
}				 
void add_runs_with_extra(batsman *team1, bowler *team2, team *overall, matchinfo *info) {
	if((ab[0] == 'n') && runs > 1)	
		onstrike->runs += runs - 1;
	bowling->runs += runs;
	if(runs == 0)
		dot++;
	if(ab[0] == 'e') {
		overall->overs += 0.1;
		onstrike->balls++;
	}
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
	overall->totalruns += runs;
	overall->runrate = overall->totalruns / overall->overs;
	overall->partnership = overall->partnership + runs;
	overall->extras += runs;
	bowling->extras += runs;
	if(overall->innings == 2) {
		overall->target = overall->target - overall->totalruns;
		overall->reqrate = overall->target / (50 - overall->overs);
	}
	runs = -1;
	ab = NULL;
	if(((bowling->balls) % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		display(team1, team2, overall);
		if(overall->overs != info->overs) {
			changebowler(team2);
			changestrike();
		}
	}
	else
		display(team1, team2, overall);
}	
void add_runs_with_no_extra(batsman *team1, bowler *team2, team *overall, matchinfo *info) {
	onstrike->runs += runs;
	bowling->runs += runs;
	onstrike->balls++;
	onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
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
	bowling->economy = (bowling->runs) / (bowling->overs);
	overall->overs += 0.1;
	if(overall->innings == 2) {
		overall->target = overall->target - overall->totalruns;
		overall->reqrate = overall->target / (50 - overall->overs);
	}
	overall->totalruns += runs;
	overall->runrate = overall->totalruns / overall->overs;
	overall->partnership = overall->partnership + runs;
	runs = -1;
	if((bowling->balls % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		changestrike();
		if(dot == 6)
			bowling->maidens++;
		dot = 0;
		display(team1, team2, overall);
		if(overall->overs != info->overs)
			changebowler(team2);
	}
	else
		display(team1, team2, overall);
}		 
void input(char *a) {
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
			else 
				wrong = 1;
		}
	}
	ab[j] = '\0';
}			
void update(team *overall, batsman *team1, bowler *team2, matchinfo *info) {
	char a[4];
	char *e = "%s";
	start(overall);
	in_the_ground(team1);
	warming_up(team2);
	printf("enter name of batsman on stike:\n");
	scanf(e, name);
	onstrike = send_batsman(team1, name);
	printf("enter name of batsman off strike:\n");
	scanf(e, name);
	offstrike = send_batsman(team1, name);
	taking_guard(onstrike);
	taking_guard(offstrike);
	printbat(team1);
	printbowl(team2);
	printf("enter name of bowler:\n");		
	scanf(e, name);	
	bowling = give_bowl(team2, name);
	shining_bowl(bowling);
	while((overall->overs != info->overs) && (overall->wickets != 10)) {     	
		printf("enter runs made , wicket(w), wide(y), noball(n), extra(e)");		
		scanf("%s", a);
		input(a);
		printf("%d", runs);
		if(wrong) {
			printf("INVALIND INPUT:\n");
			wrong = 0;
		}
		else if(ab[0] == '\0')
			add_runs_with_no_extra(team1, team2, overall, info);
		else {
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e')
				add_runs_with_extra(team1, team2, overall, info);
			else {
				printf("bowled(b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t), time out(o)");
				wicket(team1, team2, overall, info);			
			}
		}			
	}
}		
