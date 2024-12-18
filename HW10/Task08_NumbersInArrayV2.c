#include <stdio.h>
#include <string.h>

const int line_width = 1000;

int str_to_int(char str[], int array[]){
    int i=0;
    int j=0;
    array[0]=0;
    while(str[i]!='\0'){
        if(str[i]!=' '){
            array[j] = 10*array[j]+str[i]-'0';
        }
        else {
            j++;
            array[j] = 0;
        }
        i++;
    }
    return j;
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

int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
char numbers[line_width];
char c;
int num[line_width];

FILE *file;  

    if((file = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }

    int count = 0;
    while(((c = getc(file)) != EOF) && (c != '\n'))
        line[count++] = c;
    line[count] = '\0';

    fclose(file); 
    
    int j=0;
    for(int i=0;i<count;i++){
        if(line[i]>='0' && line[i]<='9'){
            numbers[j++] = line[i];
            if(line[i+1] < '0' || line[i+1] > '9'){
                numbers[j++] = ' ';
                }//j++;
        }
    }
    
    if(j){
        numbers[j++] = '\0';
        }

    int len = str_to_int(numbers, num);
    sort_array(len, num);

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }   

    for (int i=0;i<len;i++){
        fprintf(file,"%d ",num[i]);
    }

    fclose(file);
    return 0;
}

