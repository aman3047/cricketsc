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
	temp = (batsmannode *)malloc(sizeof(batsmannode));
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
	return temp;
}
void taking_guard(batsmannode *bat) {
	bat->runs = 0;
	bat->balls = 0;
	bat->strikerate = 0;
	bat->status = NULL;
	bat->four = 0;
	bat->six = 0;
}
void did_not_bat(batsmannode *bat) {
	bat->runs = -1;
	bat->balls = -1;
	bat->strikerate = -1;
	bat->status = NULL;
	bat->four = -1;
	bat->six = -1;
}	
void warming_up(bowler *bowl) {
	bowl->head = NULL;
	bowl->tail = NULL;
	bowl->count = 0;
}
bowlernode *give_bowl(bowler *bowl, char *name) {
	bowlernode  *temp;
	temp = (bowlernode *)malloc(sizeof(bowlernode));
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
	return temp;
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
	overall->pscore = 0;
	overall->runrate = 0;
	overall->reqrate = 0;
	overall->balls = 0;
	overall->wickets = 0;
}		
