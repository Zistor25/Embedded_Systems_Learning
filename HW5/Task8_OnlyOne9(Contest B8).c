

#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t number;
	scanf("%" SCNu32, &number);	
	
	int x = 0;
	for ( ; number>0; number /= 10)
	{
		x += (number%10) == 9;
	}	
	(x==1) ? printf("YES") : printf("NO");
	
	return 0;
}

