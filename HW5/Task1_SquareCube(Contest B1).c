

#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t number;
	scanf("%" SCNu32, &number);
	for(int i=1; i<(number+1); i++)
	{
		uint32_t square = i*i;
		uint32_t cube = i*i*i;
		printf("%" PRIu32 " %" PRIu32 " %" PRIu32 "\n", i, square, cube);
	}
	return 0;
}

