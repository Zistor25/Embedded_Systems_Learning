
#include <stdio.h>

#define SIZE 10

void input_array(int size, int array[])
{
    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }
}


int is_two_same(int size, int a[])
{
    int flag = 0;
    
    for (int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if (a[i]==a[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag==1)
            break;
    }

    if (flag==1)
        printf("YES");

    else
        printf("NO");
        
    return flag;
}


int main(int argc, char **argv)
{
    int a[SIZE];
    input_array(SIZE, a);
    is_two_same(SIZE, a);
    return 0;
}

