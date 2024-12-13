
#include <stdio.h>

#define SIZE 5

void input_array(int size, int array[])
{
    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }
}


int find_max_array(int size, int a[])
{
    int max = a[0];
    for (int i=1; i<size; i++)
    {
        if (a[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}



int main(int argc, char **argv)
{
    int a[SIZE];
    input_array(SIZE, a);
    printf ("%d", find_max_array(SIZE, a));
    return 0;
}

