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
void afterwicket(batsman *team1, bowler *team2, team *overall, matchinfo *info) {
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
		display(team1, team2, overall, onstrike, offstrike, bowling);
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
		display(team1, team2, overall, onstrike, offstrike, bowling);
	}

}	
void wicket(batsman *team1, bowler *team2, team *overall, matchinfo *info) {
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
			printf("enter name of catcher\n");
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
		display(team1, team2, overall, onstrike, offstrike, bowling);
		if(overall->balls != (info->overs * 6)) {
			changebowler(team2);
			changestrike();
		}
	}
	else
		display(team1, team2, overall, onstrike, offstrike, bowling);
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
		display(team1, team2, overall, onstrike, offstrike, bowling);
		if(overall->balls != (info->overs * 6)) {
			changebowler(team2);
			changestrike();
		}
	}
	else
		display(team1, team2, overall, onstrike, offstrike, bowling);
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
			else {
				wrong = 1;
				return;
			}
		}
	}
	ab[j] = '\0';
	printf("input : %s\n", ab);
	printf("%c\n", ab[0]);
	printf("%d\n", runs);
}			
void update(team *overall, batsman *team1, bowler *team2, matchinfo *info) {
	char a[4];
	char *e = "%s";
	int v;
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
	printf("enter name of bowler:\n");		
	scanf(e, name);	
	bowling = give_bowl(team2, name);
	shining_bowl(bowling);
	while((overall->balls != (info->overs * 6)) && (overall->wickets != 10)) {
		printf("%d\n", overall->innings);
		printf("%d\n", overall->target);     	
		printf("enter runs made , wicket(w), wide(y), noball(n), extra(e) end inning(esc)");		
		scanf("%s", a);
		if(a[0] == 27)
			break;
		input(a);
		printf("%d", wrong);
		if(wrong) {
			printf("INVALIND INPUT:\n");
			wrong = 0;
			continue;
		}
		else if(ab[0] == '\0')
			add_runs_with_no_extra(team1, team2, overall, info);
		else {			
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e') {
				printf("yahoo\n");
				add_runs_with_extra(team1, team2, overall, info);
			}
			else {
				printf("bowled(b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t), time out(o)");
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
		printf("enter names of remaining players");
		v = overall->wickets;
		while(v != (9 - overall->wickets)) {
			scanf("%s", name);
			offstrike = send_batsman(team1, name);
			did_not_bat(offstrike);
			v++;
		}
	}
	if(overall->innings == 2) {
		printf("enter result\n");
		getchar();
		scanf("%[^\n]", overall->result);
	}
	if(overall->innings ==  1) {
		overall->innings = 2;
		overall->target = overall->totalruns + 1;
	}
}		
