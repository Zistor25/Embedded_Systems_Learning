
#include <stdio.h>

#define SIZE 20

void input_array(int array[], int size)
{
    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void sort_even_odd(int size, int array[])
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i]%2)
            {
                continue;
            }
            else
            {
                for (int j = i; j>0 && (array[j-1]%2) && j<size; j--)
                {
                    int tmp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = tmp;
                }
            }
    }
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
}

int main(int argc, char **argv)
{
    int array[SIZE];
    input_array(array, SIZE);
    sort_even_odd(SIZE, array);
    print_array(array, SIZE);
    return 0;
}

