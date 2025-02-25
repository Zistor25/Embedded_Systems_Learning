
#include <stdio.h>

#define LEN 10

int main(int argc, char **argv)
{
	char c;
	int stack_arr[LEN] = {0};
	int counter = 0;
	while((c = getchar()) != '.')
	{
		if (c >= '0' && c <= '9')
		{
			stack_arr[counter] = 10 * stack_arr[counter] + c - '0';
		}
		if (c == ' ')
		{
			counter++;
		}
		if (c == '+')
		{
			stack_arr[counter-2] = stack_arr[counter-2] + stack_arr[counter-1];
			stack_arr[counter-1] = 0;
			counter = counter - 2;
		}
		if (c == '-')
		{
			stack_arr[counter-2] = stack_arr[counter-2] - stack_arr[counter-1];
			stack_arr[counter-1] = 0;
			counter = counter - 2;
		} 
		if (c == '*')
		{
			stack_arr[counter-2] = stack_arr[counter-2] * stack_arr[counter-1];
			stack_arr[counter-1] = 0;
			counter = counter - 2;
		}
		if (c == '/')
		{
			stack_arr[counter-2] = stack_arr[counter-2] / stack_arr[counter-1];
			stack_arr[counter-1] = 0;
			counter = counter - 2; 
		}
	}
	printf("%d", stack_arr[0]);
	return 0;
}

