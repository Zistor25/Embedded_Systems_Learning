
#include <stdio.h>

#define LEN 5

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}


float Average(int array[], int len)
{
    float average, sum=0;
    for (int i=0; i<len; i++)
    {
        sum += array[i];
    }
    average = sum/len;
    return average;
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    printf("%.3f", Average(array,LEN));
    return 0;
}

