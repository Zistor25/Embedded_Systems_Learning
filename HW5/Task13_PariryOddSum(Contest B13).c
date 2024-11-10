
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t number, parity=0, odd=0;
	scanf("%" SCNu32, &number);	
	
	for ( ; number>0; number /= 10)
	{
		parity += !(number%2);
		odd += (number%2);
	}
	printf("%" PRIu32 " %" PRIu32, parity, odd);
	
	return 0;
}
