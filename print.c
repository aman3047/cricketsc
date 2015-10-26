#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
void move(int x, int y) {
	printf("\033[%d;%df", y, x);
	fflush(stdout);
}
void printbat(batsman *bat) {
	batsmannode  *temp;
	temp = bat->head;
	while(temp) {
		move()
		printf("%s", temp->name);
		printf("%d", temp->runs);
		printf("%d", temp->balls);
		printf("%d", temp->four);
		printf("%d", temp->six);
		printf("%f", temp->strikerate);
		printf("\n");
		temp = temp->next;
	}
} 
void printbowl(bowler *bowl) {
	bowlernode  *temp;
	temp = bowl->head;
	while(temp) {
		printf("%s", temp->name);
		printf("%f", temp->overs);
		printf("%d", temp->runs);
		printf("%d", temp->wicket);
		printf("%d", temp->maidens);
		printf("%d", temp->extras);
		printf("%f", temp->economy);
		printf("%f", temp->strikerate);
		printf("\n");
		temp = temp->next;
	}
}
char *date(){
	struct tm *tm_now;
	time_t now;	
	char b[16];
	char *r;
	r = (char *)malloc((sizeof(char)) * 16)
	now = time (NULL);
	tm_now = localtime(&now);
	strftime(b, sizeof b, "%a %d %m %Y", tm_now);
	strcpy(r, b);
	return r;
}
void printinfo(matchinfo *info){
	char *s;
	s = (char *)malloc((sizeof(char)) * 16);
	move(0, 5)
	printf("series name: ");
	move(13, 5);
	scanf("%[^\n]", info->sname);
	move(30, 5);
	printf("toss: ");
	move(37, 5); 
	scanf("%[^\n]", info->toss);
	move(0, 7);
	printf("venue: ");
	move(8, 7);
	scanf("%[^\n]", info->venue);
	move(25, 7);
	printf("date: ");
	s = date();
	move(33, 7);
	printf("%s", s);
	strcpy(info->date, s);
	move(0,9);
	printf("umpire1 : ");
	move(11, 9);
	scanf("%[^\n]", info->umpire1);
	move(25, 9)
	printf("umpire2 : ");
	move(36, 9);
	scanf("%[^\n]", info->umpire2);
	free(s);
} 			
void display(batsman *team1, bowler *team2, matchinfo *info, team *overall) {
	move(0,15);
	printf("Name of batsman");
	move(16, 15);
	printf("r");
	move(20, 15);
	printf("b");
	move(24, 15);
	printf("4s");
	move(28, 15);
	printf("6s");
	move(32, 15);
	printf("st");
	printbat(team1);
	move(0, 25);
	printf("Name of bowler");
	move(16, 25);
	printf("o");
	move(20, 25);
	printf("r");
	move(24, 25);
	printf("w");
	move(28, 25);
	printf("m");
	move(32, 25);
	printf("e");
	move(36, 25);
	printf("eco");
	move(40, 25);
	printf("st");
	printbat(team2);
}
