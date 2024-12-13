
#include <stdio.h>

#define SIZE 20

void input_array(int array[], int size)
{
    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
}

void sort_array(int size, int array[])
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j>0 && array[j-1]>array[j]; j--)
        {
            int tmp = array[j-1];
            array[j-1] = array[j];
            array[j] = tmp;
        }
    }
}


int main(int argc, char **argv)
{
    int array[SIZE];
    input_array(array, SIZE);
    sort_array(SIZE, array);
    print_array(array, SIZE);
    return 0;
}

