char menu() {
	char ch;
<<<<<<< HEAD
	WINDOW *d;
	initscr();
   	refresh();
	start_color();
	init_pair(1,COLOR_BLACK, COLOR_GREEN);
	move(5, 35);
	printw("MENU");
	move(7, 25);
	printw("1. NEW SCORECARD");
	move(9, 25);
	printw("2. OPEN SCORECARD");
	move(11, 25);
	printw("3. BYE");
	bkgd(COLOR_PAIR(1));
	refresh();
	getch();
        delwin(d);
    	endwin();
=======
	printf("\n\t\t\t\tMENU\t\t\t\n");
	printf("\n   \t1. NEW SCORECARD \t\t\n");
	printf("\n   \t1. OPEN SCORECARD \t\t\n");
	printf("\n   \t1. BYE \t\t\n");
>>>>>>> 45159530d3b52700a5c3f9a5bd89be6775fcd8c5
	ch = getchar();
	return ch;
}
