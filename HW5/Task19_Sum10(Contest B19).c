

#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t number;
	scanf("%" SCNu32, &number);	
	
	uint32_t sum=0;
	for( ; number>0; number /= 10)
	{
		sum += number%10;;
	}
		(sum==10) ? printf("YES") : printf("NO");
	return 0;
}

