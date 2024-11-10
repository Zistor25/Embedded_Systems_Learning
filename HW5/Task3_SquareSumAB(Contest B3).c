
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t numberStart, numberFinish, squareSum;
    scanf("%" SCNu32 " %" SCNu32, &numberStart, &numberFinish);

	for(int i=numberStart; i<(numberFinish+1); i++)
	{
		uint32_t square = i*i;
		squareSum += square;
	}
	printf("%" PRIu32, squareSum);

    return 0;
}

