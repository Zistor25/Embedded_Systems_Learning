/*
 * Task10_Month.c
 * 
 * Copyright 2024 ZistorPC <ZistorPC@DESKTOP-Q9IBJV9>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>

int main(int argc, char **argv)
{
	int m;
	scanf("%d", &m);
	if (m>=3 && m<=5) {
		printf("spring");
	}
	else if (m>=6 && m<=8) {
		printf("summer");
	}
	else if (m>=9 && m<=11) {
		printf("autumn");
	}
	else
	printf("winter");

	return 0;
}
