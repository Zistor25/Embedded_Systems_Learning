
#include <stdio.h>

#define LEN 10

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}


int Max2(int array[], int len)
{
    int max1 = -125, pos = 0;
    for (int i=0; i<len; i++)
    {
        if (array[i]>max1)
        {
            max1 = array[i];
            pos = i;
        }
    }
    int max2 = -126;
    for (int i=0; i<len; i++)
    {
        if (i==pos)
        {
            continue;
        }
            
        else if (array[i]>max2)
        {
            max2 = array[i];
        }
    }
    return max1+max2;
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    printf("%d\n",Max2(array,LEN));
    return 0;
}

