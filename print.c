#include <stdio.h>
#include <time.h>
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
printinfo(matchinfo *info){
	printf("series name\n");
	scanf("%[^\n]", info->sname);
	printf("toss \n");
	scanf("%[^\n]", info->toss);
	printf("venue \n");
	scanf("%[^\n]", info->venue);
	printf("date :");
	s = date();
	strlen(info->date, s);
	printf("umpire 1 : \n");
	scanf("%[^\n]", info->umpire1);
	printf("umpire 2 : \n");
	scanf("%[^\n]", info->umpire2);
} 			
void display(batsman *team1, bowler *team2, matchinfo *info, team *overall) {
	printinfo(info);
	move(0,5);
	printf("Name of batsman");
	move(16, 5);
	printf("r");
	move(20, 5);
	printf("b");
	move(24, 5);
	printf("4s");
	move(28, 5);
	printf("6s");
	move(32, 5);
	printf("st");
	printbat(team1);
	move(0, 20);
	printf("Name of bowler");
	move(16, 20);
	printf("o");
	move(20, 20);
	printf("r");
	move(24, 20);
	printf("w");
	move(28, 20);
	printf("m");
	move(32, 20);
	printf("e");
	move(36, 20);
	printf("eco");
	move(40, 20);
	printf("st");
	printbat(team2);
}