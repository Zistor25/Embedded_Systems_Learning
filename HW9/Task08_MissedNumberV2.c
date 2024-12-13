
#include <stdio.h>

int input_array(int array[])
{
    int num;
    int len=0;
    while(scanf("%d", &num)==1 && num!=0)
        array[len++]=num;
    return len;
}

void sort_array(int size, int array[])
{
    for (int i = 1; i < size; i++)
    {
        for (int j=i; j>0 && array[j-1]>array[j]; j--)
        {
            int tmp = array[j-1];
            array[j-1] = array[j];
            array[j] = tmp;
        }
    }
}

void print_missed(int size, int array[])
{
    for (int i=1; i<size; i++)
    {
        if((array[i]-1) != array[i-1])
        {
            printf("%d", array[i]-1);
            break;
        }
    }
}

int main(int argc, char **argv)
{
    int array[1000];
    int len = input_array(array);
    sort_array(len, array);
    print_missed(len, array);
    return 0;
}

