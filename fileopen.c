void openfile(char *s) {
	char st[16];
<<<<<<< HEAD
	st[16] = "files/";
	strcat(s, ".txt");
	FILE *list;
	list = fopen("files/records", "a+");
	if(list == NULL) {
		perror("error :");
		return;
	}
	fseek(list,0,SEEK_END);
        fprintf(list,"%s",s);
        fprintf(list,"\n");
        fclose(list);	
	strcat(s, ".txt");
	strcat(st, s);
	FILE *file = fopen(st, "w");
	if(file == NULL) {
		perror("error :");
		return;
	}
	display();	
}
void searchfile(char *s) {
	char st[16];
	st[16] = "files/";
	strcat(s, ".txt");
	strcat(st, s);
	FILE *search;
	search = fopen(st,"r");
	if(file == NULL) {
		perror("error :");
		return;
	}
	fread(&team, sizeof(team, 1, search);
        fread(&batsman, sizeof(batsmannode, 11, search);
	fread(&bowler, sizeof(bowlernode, 11, search);
        fread(&matchinfo, sizeof(matchinfo, 1, search);
	main();
}
	
	


=======
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
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
