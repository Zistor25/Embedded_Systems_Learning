#include <stdio.h>

void char_to_array(int* array)
{
    char c;
    while((c = getchar())!='\n')
    {
        int didgit = c - 48;
        array[didgit]++;
    }
}

void print(int* array)
{
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
    int array[10]={0};
    char_to_array(array);
    print(array);
    return 0;
}
 
