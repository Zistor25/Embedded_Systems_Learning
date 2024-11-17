
#include <stdio.h>

int  sum_parity (int number)
{
	int sum = 0;
	for( ; number>0;)
	{
		sum += number%10;
		number /= 10;
	}
	return sum%2 == 0;
}


#include <stdio.h>

int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	printf(sum_parity(number)==1 ? "YES" : "NO");
	return 0;
}

