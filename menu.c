char menu() {
	char ch;
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
	ch = getchar();
	return ch;
}
