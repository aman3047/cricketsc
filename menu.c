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

#include <stdio.h>
#include"main.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
char menu() {
	char ch;
	system("clear");
	move(32, 4);
	printf("\e[40;38;5;82m CRICKET \e[30;48;5;82m WEDA \e[0m");
	move(37, 5);
	printf(ANSI_COLOR_RED "\e[1mMENU"  ANSI_COLOR_RESET);
	move(30, 7);
	printf(ANSI_COLOR_BLUE "\e[1m1. NEW SCORECARD" ANSI_COLOR_RESET);
	move(30, 9);
	printf(ANSI_COLOR_BLUE "\e[1m2. OPEN SCORECARD" ANSI_COLOR_RESET);
	move(30, 11);
	printf(ANSI_COLOR_BLUE "\e[1m3. EXIT" ANSI_COLOR_RESET);
	ch = getchar();
	system("clear");
	return ch;
}
