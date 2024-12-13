
#include <stdio.h>

#define SIZE 1000

int input_string(char* array)
{
    char c;
    int i = 0;
    while((c = getchar())!='.')
    {
        array[i++] = c;
    }
    return i;
}

int len_number(int n)//количество символов char в числе int
{
    int i = 1;
    while (n>9)
    {
        n = n/10;
        i++;
    }
    return i;
}

void int_to_char(int index, int len, int n, char array[])//преобразование из int в массив char
{
    for (int i=index+len-1; i>=index; i--)
    {
        array[i] = (n%10)+'0';
        n = n/10;
    }
}

int pack_string(int size, char c[], char b[])
{
    int counter = 1;
    int i = 1;
    int j = 0;
    while (i<size)
    {
        if (c[i]==c[i-1])
        {
            counter++;
        }
        else
        {
            b[j] = c[i-1];
            j++;
            //преобразование char в int
            int len = len_number(counter);
            int_to_char(j, len, counter, b);
            
            j=j+len;
            counter = 1;
        }
        i++;
    }
    return j;
}

void print_array(int size, char a[])
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c", a[i]);
    }
}


int main(int argc, char **argv)
{
    char c[SIZE]={'0'};
    input_string(c);
    char b[SIZE];
    int len = pack_string(SIZE, c, b);
    print_array(len, b);
    return 0;
}

