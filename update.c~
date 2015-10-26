int runs = -1;
char *ab = NULL;
int wrong = 0;
char name[16];
team overall;
start(&overall);
batsman team1;
bowler team2;
in_the_ground(&team1);
warming_up(&team2);
batsmannode *onstrike, *offstrike;
void update() {
	int over;
	char a[4];
	printf("enter name of batsman on stike:\n");
	gets(name);
	onstrike = send_batsman(&team1, name);
	printf("enter name of batsman off strike:\n");
	gets(name);
	offstrike = send_batsman(&team1, name);
	taking_guard(onstrike);
	taking_guard(offstrike);
	bowlernode *bowling;
	printf("enter name of bowler:\n");		
	gets(name);	
	bowling = give_bowl(&team2, name);
	shining_bowl(bowling);
	printf("enter runs made , wicket(w), wide(y), noball(n), extra(e)");
	while(overs != matchinfo.overs) {     	
		gets(a);
		input(a);
		if(wrong) {
			printf("INVALIND INPUT:\n");
			wrong = 0;
		}
		else if(ab == NULL)
			add_runs_with_no_extra(onstrike, offstrike, bowling, &overall);
		else {
			if(ab[0] == 'y' || ab[0] == 'n' || ab[0] == 'e')
				add_runs_with_extra(onstrike, bowling, &overall);
			else
				wicket(onstrike, bowling, &overall);
		}			
}
void wicket(batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, team *overall) {
	printf("how batsman got out?\n");
	printf("bowled (b), caught(c), lbw(l), run out(r), retired hurt(h), heatwicket(t)\n");
	char ch, c;	
	char *a;
	char f[16];
	a = (char *)malloc(sizeof(char) * (strlen(onstrike->name) + 1));	
	getchar(ch);
	switch (ch) {
		case 'c' :
			bowling->wickets++;
			overall->wickets++;
			char c[4] = " c ";
			char b[4] = " b ";
			printf("enter name of catcher\n");
			gets(f); 
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) +strlen(onstrike->name) + 9 + strlen(f))));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, c);
			strcat(overall->lastwicket, f);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			newbatsman(onstrike);
			break;
		case 'b' :
			bowling->wickets++;
			overall->wickets++;
			char b[4] = " b ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			newbatsman(onstrike);
			break;
		case 'l' :
			bowling->wickets++;
			overall->wickets++;
			char b[4] = " l ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			newbatsman(onstrike);
			break;
		case 't' :
			bowling->wickets++;
			overall->wickets++;
			char b[5] = " ht ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(bowling->name) + strlen(onstrike->name) + 9)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			newbatsman(onstrike);
			break;
		case 'h' :
			char b[16] = " retired hurt ";
			overall->lastwicket = (char *)malloc(sizeof(char) * (strlen(onstrike->name) + strlen(b) + 1));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			newbatsman(onstrike);
			break;
		case 'r' :
			overall->wickets++;
			char b[16] = " run out ";
			overall->lastwicket = (char *)malloc(sizeof(char) * ((strlen(b) + strlen(onstrike->name) + 1)));
			strcpy(overall->lastwicket, onstrike->name);
			strcat(overall->lastwicket, b);
			strcat(overall->lastwicket, bowling->name);
			printf("is new batsman on strike ? y/n ");
			getch(c);
			if(c == y)
				newbatsman(onstrike);
			else
				newbatsman(offstrike);
			break;
}
void newbatsman(batsmannode *on) {
	char name[16];
	printf("enter name of batsman :\n");
	gets(name);
	on =  send_batsman(&team1, name);
	taking_guard(on);
}				 
void add_runs_with_extra(batsmannode *onstrike, bowlernode *bowling, team *overall) {
	if((ab[0] == 'n') && runs > 1)	
		onstrike->runs += runs - 1;
	bowling->runs += runs;
	if(ab[0] == 'e')
		onstrike->balls++;
	onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
	if((runs == 5) && (ab[0] == 'n'))
		onstrike->fours++;
	else if((runs == 7) && (ab[0] == 'n'))  
		onstrike->six++;
	else if(runs == 2 || runs == 4 || runs == 6)
		changestrike(onstrike, offstrike);
	if(ab[0] == 'e') {
		bowling->overs += 0.1;
		bowling->balls++;
	}
	if(bowling->wickets)
		bowling->strikerate = (bowling->balls) / (bowling->wickets);
	bowling->economy = (bowling->runs) / (bowling->overs);
	overall->overs += 0.1
	if(((bowling->balls) % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		changebowler(bowling);
		changestrike(onstrike, offstrike);
	}
	overall->runs += runs;
	overall->runrate = overall->runs / overall->balls;
	overall->partnership = overall->partnership + runs;
	overall->extras += runs;
	bowling->extras += runs;
	runs = -1;
	ab = NULL;
}	
void add_runs_with_no_extra(batsmannode *onstrike, bowlernode *bowling, team *overall) {
	onstrike->runs += runs;
	bowling->runs += runs;
	onstrike->balls++;
	onstrike->strikerate = ((onstrike->runs) / (onstrike->balls)) * 100;
	if(runs == 4)
		onstrike->fours++;
	else if(runs == 6)  
		onstrike->six++;
	else if(runs == 1 || runs == 3 || runs == 5)
		changestrike(onstrike, offstrike);
	bowling->overs += 0.1;
	bowling->balls++;
	if(bowling->wickets)
		bowling->strikerate = (bowling->balls) / (bowling->wickets);
	bowling->economy = (bowling->runs) / (bowling->overs);
	overall->overs += 0.1
	if((bowling->balls % 6) == 0) {
		bowling->overs += 0.4;
		overall->overs += 0.4;
		changebowler(bowling);
		changestrike(onstrike, offstrike);
	}
	overall->runs += runs;
	overall->runrate = overall->runs / overall->balls;
	overall->partnership = overall->partnership + runs;
	runs = -1;
}
void changebowler(bowlernode *bowling) {
	bowlernode *newbowler;
	printf("enter name of bowler:\n");
	gets(name);
	newbowler = searchbowler(&team2, name);
	if(newbowler == bowling){
		printf("change bowler\n");
		changebowler(bowling);
	}
	else if(newbowler)
		bowling = newbowler;
	else {
		bowling = give_bowl(&team2, name);
		shining_bowl(bowling);
	}
}		 
void changestrike(batsmannode *onstrike, batsmannode *offstrike) {
	batsmannode *temp;
	temp = onstrike;
	onstrike = offstrike;
	offstrike = temp;
}		
void input(char *a) {
	int i = 0;
	int j = 0;
	int k = 0;
	if(ab)
		free(ab);
	ab = (char *)malloc(sizeof(char) * 2);
	while(a[i] != 0) {
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
			else 
				wrong = 1;
		}
	}
	ab[j] = '\0';
}			
		
			
