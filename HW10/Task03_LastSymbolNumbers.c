#include <stdio.h>
 
const int line_width = 1000;
 
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

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i=0; i<count-1; i++){
        if (line[count-1]==line[i]){
            fprintf(file, "%d ", i);
            printf("%d ", i);
        }
    }  
    fclose(file);     
    return 0;
}

