
#include <stdio.h>

int fX(int x)
{
	int f;
	
	if (x>=-2 && x<2)
		f = x*x;
		
		else if (x>=2)
			f = x*x + 4*x + 5;

				else
				f = 4;
	return f;
}


int main(void)
{
	int x = 1, max = -100;
	
	while (x !=0)
	{
		scanf("%d", &x);
		if (x!=0)
			fX(x)>max ? max = fX(x) : max;
	}
	printf("%d", max);
	return 0;
}
