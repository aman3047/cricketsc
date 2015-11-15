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
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int main() {
	char c;
	char *s;
	s = (char *)malloc((sizeof(char)) * 16);
	c = menu();
	switch(c) {
		case '1' :
			printf(ANSI_COLOR_MAGENTA "enter title\n" ANSI_COLOR_RESET); /*starts new score sheet*/
			scanf("%s", s); 
			openfile(s);
			free(s);
			break;
		case '2' :
			printf(ANSI_COLOR_MAGENTA "scoresheet name\n" ANSI_COLOR_RESET); /*opens previous saved scoresheet*/
			scanf("%s", s);
			searchfile(s);
			free(s);
			break;
		case '3' :
			exit(1);
	}
	return 0;
}

		
