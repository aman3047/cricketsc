#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
char *a = "%[^\n]";
void move(int x, int y) {
	printf("\033[%d;%df", y, x);
}
void printbat(batsman *bat, batsmannode *onstrike, batsmannode *offstrike) {
	batsmannode  *temp;
	temp = bat->head;
	int x = 16; 
	while(temp) {
		//move(0, x);
		if(temp == onstrike)
			printf("%s*\t", temp->name);
		else
			printf("%s\t", temp->name);
		if(temp->runs == -1) {
			printf("\n");
			continue;
		}
		printf("%s\t", temp->status);
		//move(16, x);
		printf("%d\t", temp->runs);
		//move(20, x);
		printf("%d\t", temp->balls);
		//move(24, x);
		printf("%d\t", temp->four);
		//move(28, x);
		printf("%d\t", temp->six);
		//move(32, x);
		printf("%0.2f\n", temp->strikerate);
		temp = temp->next;
		x++;
	}
} 
void printbowl(bowler *bowl, bowlernode *bowling) {
	bowlernode  *temp;
	temp = bowl->head;
	int x = 26;
	while(temp) {
		//move(0, x);
		if(temp == bowling)
			printf("%s*\t", temp->name);
		else 
			printf("%s\t", temp->name);
		//move(16, x);
		printf("%0.1f\t", temp->overs);
		//move(20, x);
		printf("%d\t", temp->runs);
		//move(24, x);
		printf("%d\t", temp->wickets);
		//move(28, x);
		printf("%d\t", temp->maidens);
		//move(32, x);
		printf("%d\t", temp->extras);
		//move(36, x);
		printf("%0.2f\t", temp->economy);
		//move(40, x);
		if(temp->strikerate)
			printf("%0.2f\n", temp->strikerate);
		else 
			printf("-\n");
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
	//move(0, 5);
	printf("series name: ");
	getchar();
	//move(13, 5);
	scanf(a, info->sname);
	//move(30, 5);
	getchar();
	printf("\ntoss: ");
	//move(37, 5); 
	scanf(a, info->toss);
	//move(0, 7);
	printf("\nvenue: ");
	//move(8, 7);
	getchar();
	scanf(a, info->venue);
	//move(25, 7);
	getchar();
	printf("\ndate: ");
	s = date();
	//move(33, 7);
	printf("%s", s);
	strcpy(info->date, s);
	//move(0,9);
	printf("\numpire1 : ");
	//move(11, 9);
	getchar();
	scanf(a, info->umpire1);
	//move(25, 9);
	printf("\numpire2 : ");
	//move(36, 9);
	getchar();
	scanf(a, info->umpire2);
	printf("\novers : ");
	getchar();
	scanf("%d", &(info->overs));
	printf("\n");
	getchar();
	free(s);
}
void printinfo(matchinfo *info) {
	//move(0, 5);
	printf("series name: ");
	//move(13, 5);
	printf("%s", info->sname);
	//move(30, 5);
	printf("\ntoss: ");
	//move(37, 5); 
	printf("%s", info->toss);
	//move(0, 7);
	printf("\nvenue: ");
	//move(8, 7);
	printf("%s", info->venue);
	//move(25, 7);
	printf("\ndate: ");
	//move(33, 7);
	printf("%s",info->date);
	//move(0,9);
	printf("\numpire1 : ");
	//move(11, 9);
	printf("%s", info->umpire1);
	//move(25, 9);
	printf("\numpire2 : ");
	//move(36, 9);
	printf("%s", info->umpire2);
	printf("\novers : ");
	printf("%d", (info->overs));
	printf("\n");
} 			 			
void display(batsman *team1, bowler *team2, team *overall, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling) {
	//move(0,15);
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
	printbat(team1, onstrike, offstrike);
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
	printbowl(team2, bowling);
	printf("totalruns\n");
	printf("%d/%d (%0.1f)\n",overall->totalruns, overall->wickets, overall->overs);
	printf("partnership\n");
	printf("%d\n",overall->partnership);
	if(overall->lastwicket) {
		printf("lastwicket\n");
		printf("%s\n",overall->lastwicket);
	}
	printf("extras\n");
	printf("%d\n",overall->extras);
	printf("innings\n");
	printf("%d\n",overall->innings);
	if(overall->innings == 2) {
		printf("reqrate\n");
		printf("%0.2f\n",overall->reqrate);
		printf("target\n");
		printf("%d\n",overall->target);
		printf("winning percentage\n");
		printf("%d\n",overall->pscore);	
	}
	else {		
		printf("projected score\n");
		printf("%d\n",overall->pscore);
	}
	printf("runrate\n");
	printf("%0.2f\n",overall->runrate);
}
