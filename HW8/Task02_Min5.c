
#include <stdio.h>

#define LEN 5

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}


int Min(int array[], int len)
{
    int min = array[0];
    for (int i=0; i<len; i++)
    {
        if (array[i]<min)
            min = array[i];
    }
    return min;
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    printf("%d\n", Min(array,LEN));
    return 0;
}

