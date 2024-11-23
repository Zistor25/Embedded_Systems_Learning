
#include <stdio.h>

#define LEN 10

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}


int Max(int array[], int len)
{
    int max = array[0]-1;
    for (int i=0; i<len; i++)
    {
        if (array[i]>max)
                max = array[i];
    }
    return max;
}

int MaxPos(int array[], int len)
{
    int max = array[0]-1, pos = 0;
    for (int i=0; i<len; i++)
    {
        if (array[i]>max)
        {
            max = array[i];
            pos = i+1;
        }
    }
    return pos;
}

int Min(int array[], int len)
{
    int min = array[0]+1;
    for (int i=0; i<len; i++)
    {
        if (array[i]<min)
                min = array[i];
    }
    return min;
}

int MinPos(int array[], int len)
{
    int min = array[0]+1, pos = 0;
    for (int i=0; i<len; i++)
    {
        if (array[i]<min)
        {
            min = array[i];
            pos = i+1;
        }
    }
    return pos;
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    printf("%d %d %d %d\n",MaxPos(array,LEN), Max(array,LEN), MinPos(array,LEN), Min(array,LEN));
    return 0;
}

