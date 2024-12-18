#include <stdio.h>

const int line_width = 10000;
 
int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
char c;

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
    
    int lower_letter = 0;
    int capital_letter = 0;
    
    for(int i=0;i<count;i++){
        if(line[i]>='a' && line[i]<='z')
            lower_letter++;
        if(line[i]>='A' && line[i]<='Z')
            capital_letter++;
        }

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }   

    fprintf(file, "%d %d", lower_letter, capital_letter);
    fclose(file);
    return 0;
}

