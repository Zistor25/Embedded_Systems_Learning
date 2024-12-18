#include <stdio.h>
 
const int line_width = 54;
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];

int num;
FILE *file;  

    if((file = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    file = fopen(input_fn, "r");
    fscanf(file, "%d", &num);

    fclose (file);
    printf ("%d\n", num);
    
    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }
    
    int count;
    char c = 'A';
    char digit = '0';
    for(count=0; count<num; count++){
        line[count]=c++;
        (digit!='8') ? (digit=digit+2) : (digit='2');
        count++;
        line[count]=digit;
    }
    line[count] = '\0';

    fprintf(file, "%s", line);
    fclose(file); 

    return 0;
}

