
#include <stdio.h>

#define LEN 10

void Input(int array[], int length)
{
    for (int i=0; i<length; i++)
    {
        scanf("%d", &array[i]);
    }
}

void ShiftR(int array[], int length)
{
    int tmp = array[length-1];
    for (int i=length-1; i>=0; i--)
    {
        if (i==0)
        {
            array[i] = tmp;
        }
        else
        {
            array[i] = array[i-1];
        }
    }
}

void Print(int array[],int length)
{
    int i;
    for (i=0; i<length; i++)
    {
        printf("%d ",array[i]);
    }
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    ShiftR(array, LEN);
    Print(array,LEN);
    return 0;
}
