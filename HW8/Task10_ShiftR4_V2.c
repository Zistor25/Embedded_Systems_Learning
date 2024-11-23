
#include <stdio.h>

#define LEN 12
#define SHIFT 4

void Input(int array[], int length)
{
    for (int i=0; i<length; i++)
    {
        scanf("%d", &array[i]);
    }
}

void ShiftR(int array[], int length, int shift)
{
    int tmp[shift];
    for (int i=0; i<=shift-1; i++)
    {
        tmp[i] = array[length-shift+i];
    }
    for (int j=length-1; j>=0; j--)
    {
        if (j<=shift-1)
        {
            array[j] = tmp[j];
        }
        else
        {
            array[j] = array[j-shift];
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
    ShiftR(array, LEN, SHIFT);
    Print(array,LEN);
    return 0;
}
