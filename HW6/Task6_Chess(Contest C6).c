#include <stdio.h>
#include <inttypes.h>

uint64_t chess(uint64_t cell)
{
	uint64_t corn = 1;
	for (int i = 1; i<cell; i++)
	{
		corn *= 2;
	}	
	return corn;
}


int main(void)
{
	uint64_t cell = 1;
	scanf("%" SCNu64, &cell);
	printf("%" PRIu64, chess(cell));
	return 0;
}

