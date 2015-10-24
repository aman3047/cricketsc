#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void in_the_ground(batsman *bat) {
	bat->head = NULL;
	bat->tail = NULL;
	bat->count = 0;
}
batsmannode *send_batsman(batsman *bat, char *name) {
	batsmannode  *temp;
	temp = (batsmannode *)malloc(sizeof(batsman));
	strcpy(temp->name, name);
	if(bat->count == 0) {
		bat->head = temp;
		bat->tail = temp;
		temp->next = NULL;
		bat->count++;
	}
	else {
		bat->tail->next = temp;			
		bat->tail = temp;
		temp->next = NULL;
		bat->count++;
	}
	return bat->head;
}
void taking_guard(batsmannode *bat) {
	bat->runs = 0;
	bat->balls = 0;
	bat->strikerate = 0;
	bat->four = 0;
	bat->six = 0;
}
void warming_up(bowler *bowl) {
	bowl->head = NULL;
	bowl->tail = NULL;
	bowl->count = 0;
}
bowlernode *give_bowl(bowler *bowl, char *name) {
	bowlernode  *temp;
	temp = (bowlernode *)malloc(sizeof(bowler));
	strcpy(temp->name, name);
	if(bowl->count == 0) {
		bowl->head = temp;
		bowl->tail = temp;
		temp->next = NULL;
		bowl->count++;
	}
	else {
		bowl->tail->next = temp; 			
		bowl->tail = temp;
		temp->next = NULL;
		bowl->count++;		
	}
	return bowl->head;
}
void shining_bowl(bowlernode *bowl) {
	bowl->overs = 0;
	bowl->balls = 0;
	bowl->maidens = 0;
	bowl->runs = 0;
	bowl->extras = 0;
	bowl->wickets = 0;
	bowl->economy = 0;
	bowl->strikerate = 0;
}
void start(team *overall) {
	overall->totalruns = 0;
	overall->overs = 0;
	overall->partnership = 0;
	overall->lastwicket = NULL;
	overall->extras = 0;
	overall->innings = 1;
	overall->WASPscore = 0;
	overall->runrate = 0;
}
	
			
			
			
