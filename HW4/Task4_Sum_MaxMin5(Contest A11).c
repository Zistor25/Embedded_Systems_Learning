/*
 * Task4_Sum_MaxMin5.c
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

int main(void)
{
	int a, b, c, d, e, max, min;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	a>b ? (max = a, min = b) : (max = b, min = a);
	if (c>max) {
		max = c;
	}
	if (d>max) {
		max = d;
	}
	if (e>max) {
		max = e;
	}
	if (c<min) {
		min = c;
	}
	if (d<min) {
		min = d;
	}
	if (e<min) {
		min = e;
	}
	printf("%d", (max+min));
	return 0;
}


