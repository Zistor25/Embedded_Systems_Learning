
#include <stdio.h>

#define LEN 10

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}


int SumPos(int array[], int len)
{
    int sum = 0;
    for (int i=0; i<len; i++)
    {
        if (array[i]>=0)
        {
            sum += array[i];
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    printf("%d\n", SumPos(array,LEN));
    return 0;
}

