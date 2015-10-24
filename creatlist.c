<<<<<<< HEAD
void in_the_ground(batsman *bat) {
	bat->head = NULL;
	bat->tail = NULL;
	bat->count = 0;
}
batsmannode *send_batsman(batsman *bat, char *name) {
	batsmannode  *temp;
	temp = (batsman *)malloc(sizeof(batsman));
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
	temp = (bowler *)malloc(sizeof(bowler));
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
start(team *overall) {
	totalruns = 0;
	overs = 0;
	partnership = 0;
	lastwicket = NULL;
	extras = 0;
	innings = 1;
	WASPscore = 0;
	runrate = 0;
}
	
=======
void createbatsmanlist() {
	int i;
	char name[16];
	batsmannode  *temp, *p;
	for(i = 0; i < 11; i++) {
		temp = (batsman *)malloc(sizeof(batsman));
		strcpy(temp->name, name);
		if(i = 0) {
			batsman->head = temp;
			batsman->tail = temp;
			temp->next = NULL;
			p = temp;
		}
		else {
			p->next = temp;			
			batsman->tail = temp;
			temp->next = NULL;
			p = temp;
		}
	}
}
void createbowlerlist() {
	int i;
	char name[16];
	bowlernode  *temp, *P;
	for(i = 0; i < 11; i++) {
		temp = (bowler *)malloc(sizeof(bowler));
		strcpy(temp->name, name);
		if(i = 0) {
			bowler->head = temp;
			bowler->tail = temp;
			temp->next = NULL;
			p = temp;
		}
		else {
			p->next = temp; 			
			bowler->tail = temp;
			temp->next = NULL;
			p = temp;
		}
	}
}

>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
			
			
			
