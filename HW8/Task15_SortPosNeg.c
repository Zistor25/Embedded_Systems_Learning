
#include <stdio.h>

#define LEN 10

void Input(int array[], int length)
{
    for (int i=0; i<length; i++)
    {
        scanf("%d", &array[i]);
    }
}

void SortPosNeg(int array[], int length)
{
    int ArrayPosNeg[length];
    int j=-1;
    
    for (int i=0; i<=length-1; i++)//запись в промежуточный массив положительных элементов
    {
        if (array[i]>0)
        {
            j++;
            ArrayPosNeg[j] = array[i];
        }
        else
            continue;
    }
    
        for (int i=0; i<=length-1; i++)//запись в промежуточный массив отрицательных элементов
    {
        if (array[i]<0)
        {
            j++;
            ArrayPosNeg[j] = array[i];
        }
        else
            continue;
    }
    for (int i=0; i<=j; i++)
    {
        printf("%d ",ArrayPosNeg[i]);
    }
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    SortPosNeg(array, LEN);
    return 0;
}
