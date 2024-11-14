#include <stdio.h>

int sum(int x)
{
	int s = 0;
	for (int i = 1; i<x+1; i++)
	{
		s += i;
	}	
	return s;
}


int main(int argc, char **argv)
{
	int x;
	scanf("%d", &x);
	printf("%d", sum(x));
	return 0;
}
