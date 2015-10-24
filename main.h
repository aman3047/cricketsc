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
}batsman
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
typedef struct list {
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
	float runrate;
	int WASPscore;
	int wickets;
}team;
void in_the_ground(batsman *bat);
batsmannode *send_batsman(batsman *bat, char *name);
void taking_guard(batsmannode *bat);
void warming_up(bowler *bowl);
void opennewfile(char *s);
bowlernode *give_bowl(bowler *bowl, char *name);
void searchfile(char *s);
void shining_bowl(bowlernode *bowl);


	

     
