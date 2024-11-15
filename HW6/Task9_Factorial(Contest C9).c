
#include <stdio.h>

int  factorial (int number)
{
	int f=1;
	for(int i=1; i<number+1; i++)
	{
	f *= i;
	}
	return f;
}


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	printf("%d", factorial(number));
	return 0;
}

