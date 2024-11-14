#include <stdio.h>

int  power (int  number, int  p)
{
	int nP;
	if (p==0)
	nP = 1;
else
	nP = number;

for(int i=1; i<p; i++)
	{
		nP *= number;
	}
	return nP;
}

int numberInP (int n, int p)
{
	int numberInP = 0;
	
	for (int i=0; n != 0; i++)
	{
		numberInP += power(10,i)*(n%p);
		n = (n/p);
	}
	return numberInP;
}

int main(int argc, char **argv)
{
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d", numberInP(n, p));
	return 0;
}

