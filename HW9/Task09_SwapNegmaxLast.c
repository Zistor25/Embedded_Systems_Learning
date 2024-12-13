
#include <stdio.h>

#define SIZE 10

void input_array(int size, int a[])
{
    for (int i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void swap_negmax_last(int size, int a[])
{
    int swap = 0;
    int negmax = -1000;
    int *ptr_negmax;
    int *ptr_last;
    for (int i=0; i<size-1; i++)
    {
        if (a[i]<0 && a[i]>negmax)
        {
            swap = 1;
            negmax = a[i];
            ptr_negmax = &a[i];
        }
    }
    if (swap)
    {
        ptr_last = &a[size-1];
        int tmp = *ptr_last;
        *ptr_last = *ptr_negmax;
        *ptr_negmax = tmp;
    }
}

void print_array(int size, int a[])
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
}


int main(int argc, char **argv)
{
    int a[SIZE];
    input_array(SIZE, a);
    swap_negmax_last(SIZE, a);
    print_array(SIZE, a);
//    print_missed(len, array);
//    printf("%d ", array[1]);
    return 0;
}

