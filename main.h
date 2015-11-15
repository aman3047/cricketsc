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

typedef struct batsman {
	char name[16];
	int runs;
	int balls;
	float strikerate;
	int four;
	int six;
	char status[32];
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
	char teama[16];
	char teamb[16];
	char fbat[16];
	char venue[16];
	char date[16];
	char umpire1[16];
	char umpire2[16];
	int overs;
}matchinfo;
typedef struct team {
	int totalruns;
	float overs;
	int balls;
	int partnership;
	char *lastwicket;
	int extras;
	int innings;
	float reqrate;
	int target;
	float runrate;
	int pscore;
	int wickets;
	char result[64];
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
void add_runs_with_no_extra(batsman *team1, bowler *team2, team *overall, matchinfo *info);
void add_runs_with_extra(batsman *team1, bowler *team2, team *overall, matchinfo *info);
void wicket(batsman *team1, bowler *team2, team *overall, matchinfo *info);
void changebowler(bowler *team2);
void newbatsman(batsman *team1, char ci);
void changestrike();
int scorepredict(team *overall, matchinfo *info);
bowlernode *searchbowler(bowler *bowl, char *name);
void display(batsman *team1, bowler *team2, team *overall, batsmannode *onstrike, batsmannode *offstrike, bowlernode *bowling, matchinfo *info);
void getinfo(matchinfo *info);
char menu();
void printbat(batsman *bat, batsmannode *onstrike, batsmannode *offstrike);
void printbowl(bowler *bowl, bowlernode *bowling);
void printinfo(matchinfo *info);
void move(int x, int y);
void did_not_bat(batsmannode *bat);
