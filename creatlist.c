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

			
			
			
