typedef struct batsman {
	char name[16];
	int runs;
	int balls;
	float strikerate;
	int four;
	int six;
	struct batsman *next;
}batsmannode;
typedef struct list {
	batsmannode *head, *tail;
	int count;
}batsman;
typedef struct bowler {
	char name[16];
	float overs;
	int balls;
	int maidens;
	int runs;
	int extras;
	int wickets;
	float economy;
	float strikerate;
	struct bowler *next;
}bowlernode;
typedef struct listb {
	bowlernode *head, *tail;
	int count;
}bowler;
typedef struct matchinfo {
	char sname[32];
	char toss[8];
	char venue[16];
	char date[16];
	char umpire1[16];
	char umpire2[16];
	int overs;
}matchinfo;
typedef struct team {
	int totalruns;
	float overs;
	int partnership;
	char *lastwicket;
	int extras;
	int innings;
	float reqrate;
	int target;
	float runrate;
	int pscore;
	int wickets;
}team;
void in_the_ground(batsman *bat);
batsmannode *send_batsman(batsman *bat, char *name);
void taking_guard(batsmannode *bat);
void warming_up(bowler *bowl);
bowlernode *give_bowl(bowler *bowl, char *name);
void shining_bowl(bowlernode *bowl);
void start(team *overall);
void write(char *s, team *overall, batsman *team1, bowler *team2, matchinfo *info);
void openfile(char *s);
void searchfile(char *s);
void update(team *overall, batsman *team1, bowler *team2, matchinfo *info);
void add_runs_with_no_extra(bowler *team2, team *overall);
void add_runs_with_extra(bowler *team2, team *overall);
void wicket(batsman *team1, team *overall);
void changebowler(bowler *team2);
void newbatsman(batsman *team1, char ci);
void changestrike();
int scorepredict(team *overall, matchinfo *info);
bowlernode *searchbowler(bowler *bowl, char *name);
void display(batsman *team1, bowler *team2, team *overall);
void printinfo(matchinfo *info);

 

	

     
