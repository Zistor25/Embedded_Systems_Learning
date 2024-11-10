
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	uint32_t number;
	scanf("%" SCNu32, &number);	
	
	int x = 1;
	for ( ; number>0 && x>0; number /= 10)
	{
		x = x && ((number%10) > ((number/10)%10));
	}	
	(x>0) ? printf("YES") : printf("NO");
	
	return 0;
}
