#include <stdio.h>
void printbat(batsman *bat) {
	batsmannode  *temp;
	temp = bat->head;
	while(temp) {
		printf("%[^
]", temp->name);
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
		printf("%[^\n]", temp->name);
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
	printf("Name of batsman\t\tr\tb\tf\ts\tst\n");
	printbat(team1);
	printf("Name of batsman\t\to\tr\tw\tm\te\teco\tst\n");
	printbat(team2);
}
