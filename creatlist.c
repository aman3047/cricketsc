/*****************************************************************************
 * Copyright (C) AMAN TADVI amanftadvi@yahoo.co.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void in_the_ground(batsman *bat) { /*init function for batsmans' list*/
	bat->head = NULL;
	bat->tail = NULL;
	bat->count = 0;
}
batsmannode *send_batsman(batsman *bat, char *name) {/* insertion fuction for batsmans' list*/
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
void taking_guard(batsmannode *bat) {/* sets all values of batsman to zero*/
	bat->runs = 0;
	bat->balls = 0;
	bat->strikerate = 0;
	strcpy(bat->status, " batting ");
	bat->four = 0;
	bat->six = 0;
}
void did_not_bat(batsmannode *bat) { /*sets all values to -1 if batsman didn't bat*/ 
	bat->runs = -1;
	bat->balls = -1;
	bat->strikerate = -1;
	bat->four = -1;
	bat->six = -1;
}	
void warming_up(bowler *bowl) { /*init function for bowlers' list*/
	bowl->head = NULL;
	bowl->tail = NULL;
	bowl->count = 0;
}
bowlernode *give_bowl(bowler *bowl, char *name) { /* insertion fuction for bowlers' list*/
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
void shining_bowl(bowlernode *bowl) {	/* sets all values of bowler to zero*/
	bowl->overs = 0;
	bowl->balls = 0;
	bowl->maidens = 0;
	bowl->runs = 0;
	bowl->extras = 0;
	bowl->wickets = 0;
	bowl->economy = 0;
	bowl->strikerate = 0;
}
void start(team *overall) { /* initializes all values to zero*/
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
