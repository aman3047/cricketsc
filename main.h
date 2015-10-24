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
<<<<<<< HEAD
	int count;
=======
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
}batsman
typedef struct bowler {
	char name[16];
	float overs;
<<<<<<< HEAD
	int balls;
=======
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
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
<<<<<<< HEAD
	int count;
}bowler;
=======
}bowler
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
typedef struct matchinfo {
	char sname[32];
	char toss[8];
	char venue[16];
	char date[16];
	char umpire1[16];
	char umpire2[16];
<<<<<<< HEAD
	int overs;
=======
	float overs;
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
}matchinfo;
typedef struct team {
	int totalruns;
	float overs;
	int partnership;
<<<<<<< HEAD
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
=======
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
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5


	

     
