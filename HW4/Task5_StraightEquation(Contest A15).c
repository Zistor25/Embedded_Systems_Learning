/*
 * Task5_StraightEquation.c
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
	int X1, Y1, X2, Y2;
	float k, b, deltaY, deltaX;
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	deltaY = (Y2-Y1);
	deltaX = (X2-X1);
	k = deltaY / deltaX;
	b = Y1 - k*X1;
	printf("%.2f %.2f", k, b);
	return 0;
}
