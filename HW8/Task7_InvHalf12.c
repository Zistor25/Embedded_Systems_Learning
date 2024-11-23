
#include <stdio.h>

#define LEN 10
#define DIVIDER 2

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}

void RevPos(int array[], int length, int divider)
{
    for (int i=0; i<divider; i++)
    {
        for (int j=length/divider; j>0; j--)
        {
            int pos = i*length/divider+j-1;
            printf("%d ", array[pos]);
        }
    }
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    RevPos(array, LEN, DIVIDER);
    return 0;
}

