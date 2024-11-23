
#include <stdio.h>

#define LEN 10

void Input(int array[], int length)
{
    for (int i=0; i<length; i++)
    {
        scanf("%d", &array[i]);
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

void SwapArr(int *array,int i,int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

 void BubbleSort(int* array,int length)
{
    int noSwap;
    for (int i=0; i<length; i++)
    {
        noSwap = 1;
        for (int j=length-1; j>i; j--)
        {
            if((array[j-1]%10)>(array[j]%10))
            {
                SwapArr(array,j-1,j);
                noSwap = 0;
            }
        }if(noSwap)
            break;
    }
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    BubbleSort(array, LEN);
    Print(array,LEN);
    return 0;
}
