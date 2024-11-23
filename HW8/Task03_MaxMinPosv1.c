
#include <stdio.h>

#define LEN 10

void Input(int array[], int len)
{
    for (int i=0; i<len; i++)
    {
        scanf("%d", &array[i]);
    }
}


void MaxMinPos(int array[], int len)
{
    int max = array[0]-1, min = array[0]+1;
    int answers[4] = {0, 0, 0, 0};
    for (int i=0; i<len; i++)
    {
        if (array[i]>max)
            {
                max = array[i];
                answers[0] = i+1;//номер элемента массива
                answers[1] = max;//значение максимума
            }
        if (array[i]<min)
            {
                min = array[i];
                answers[2] = i+1;//номер элемента массива
                answers[3] = min;//значение минимума
            }
    }
    printf("%d %d %d %d\n", answers[0], answers[1], answers[2], answers[3]);
    //return answers;
}

int main(int argc, char **argv)
{
    int array[LEN]={0};
    Input(array,LEN);
    MaxMinPos(array,LEN);
    return 0;
}

