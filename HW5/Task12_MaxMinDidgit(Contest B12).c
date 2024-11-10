
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t number, max=0, min=9;
	scanf("%" SCNu32, &number);	
	
	for ( ; number>0; number /= 10)
	{
		if (max < number%10) max = number%10;
		if (min > number%10) min = number%10;
	}	
	printf("%" PRIu32 " %" PRIu32, min, max);
	
	return 0;
}
