
#include <stdio.h>
#include <string.h>

#define LEN 2005

int main(int argc, char **argv)
{
	char str1[LEN];
	char str2[LEN];
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int min_len = (len1 <= len2) ? len1 : len2;
	char *ptr1;
	char *ptr2;
	int counter1 = 0;
	int counter2 = 0;
	for (int i = 1; i <= min_len; i++)
	{
		ptr1 = &str1[0];
		ptr2 = &str2[len2 - i-1];
		int res1 = memcmp(ptr1, ptr2, i);
		
		if(res1 == 0)
		{
			counter1 = i+1;
		}
		
		ptr1 = &str1[len1 - i-1];
		ptr2 = &str2[0];
		int res2 = memcmp(ptr1, ptr2, i);
		
		if(res2 == 0)
		{
			counter2 = i+1;
		}
	}
	
	printf("%d %d\n", counter1, counter2);
	
	return 0;
}

