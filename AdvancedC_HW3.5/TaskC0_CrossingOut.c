
#include <stdio.h>
#include <string.h>

#define LEN 100


int main(int argc, char **argv)
{
    
    char str[LEN];
    scanf("%s", str);
    int len = strlen(str)-1;
    int uniq_num_counter = 0;
    int number_arr[900] = {0};
    
    for(int i = 0; i <= len-2; i++)
    {
        if (str[i] == '0')
        {
			continue;
		}
		
        for(int j = i+1; j <= len-1; j++)
        {
            for(int k = j+1; k <= len; k++)
            {
                int number = (str[i] - '0')*100 + (str[j] - '0')*10 + (str[k] - '0');
                number[number_arr - 100] = 1;
            }
        }
    }
    for(int i = 0; i < 900; i++)
    {
        uniq_num_counter += number_arr[i];
    }
    printf("%d", uniq_num_counter);
    
    return 0;
}
