#include <stdio.h>
#include <string.h>

void print_didgit(char s[])
{
    int size = strlen(s);
    int array[10]={0};
    for(int i=0; i<size; i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            int didgit = s[i] - 48;
            array[didgit]++;
        }
    }
    for(int i=0;i<=9;i++)
    {   
        if(array[i]!=0)
        {
            printf("%d %d\n", i, array[i]);
        }
    }
}


int main()
{
    char s[5];
    scanf("%s", s);
    print_didgit(s);
    return 0;
}
 
