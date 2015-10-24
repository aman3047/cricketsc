void openfile(char *s) {
	char st[16];
	FILE *fp = fopen(s, "r");
	if(fp == NULL) {
		printf("error\n");
		return NULL;
	}
	printf("enter series name\n");
	scanf("%s", st);
	strcpy(matchinfo->sname, st);
	printf("who won the toss?\n");
	scanf("%s", st);
	strcpy(matchinfo->toss, st);
	printf("enter venue\n");
	scanf("%s", st);
	strcpy(matchinfo->venue, st);
	printf("enter date\n");
	scanf("%s", st);
	strcpy(matchinfo->date, st);
	printf("enter name of umpire1\n");
	scanf("%s", st);
	strcpy(matchinfo->umpire1, st);
	printf("enter name of umpire2\n");
	scanf("%s", st);
	strcpy(matchinfo->umpire2, st);
	createbatsmanlist();
	createbowlerlist();
}
