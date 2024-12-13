
#include <stdio.h>

#define SIZE 10

void input_array(int size, int array[])
{
    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int compression(int a[], int b[], int N)
{
    int length_b = 0;
    int current = 0;
    int previous = 0;
    int counter=0;
    for (int i=0; i<N; i++)
    {
        current = a[i];
        if (a[i]==previous)
        {
            counter++;
            previous = current;
        }
        else
        {
            b[length_b++] = counter;
            previous = current;
            counter = 1;
        }
    }
    b[length_b++] = counter;
    return length_b;
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
    int a[SIZE];
    int b[SIZE] = {0};
    input_array(SIZE, a);
    compression(a, b, SIZE);
    print_array(b, (compression(a, b, SIZE)));
    
    return 0;
}

