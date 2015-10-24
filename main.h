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
}batsman
typedef struct bowler {
	char name[16];
	float overs;
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
}bowler
typedef struct matchinfo {
	char sname[32];
	char toss[8];
	char venue[16];
	char date[16];
	char umpire1[16];
	char umpire2[16];
	float overs;
}matchinfo;
typedef struct team {
	int totalruns;
	float overs;
	int partnership;
	char lastwicket[16];
	int extras;
	int WASPscore;
}team;
void createbatsmanlist();
void createbowlerlist();
char menu();
void print();
void runsscored(batsman *a, bowler *b);
void opennewfile(char *s);
void savefile(char *s);
void searchfile(char *s);


	

     
