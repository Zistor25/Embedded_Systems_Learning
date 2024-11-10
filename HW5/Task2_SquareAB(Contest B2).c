
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t numberStart, numberFinish;
	scanf("%" SCNu32 " %" SCNu32 , &numberStart, &numberFinish);
	
	for(int i=numberStart; i<(numberFinish+1); i++)
	{
		uint32_t square = i*i;
		printf("%" PRIu32 " ", square);
	}
	return 0;
}

