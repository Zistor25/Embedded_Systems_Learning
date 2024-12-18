#include <stdio.h>
 
const int line_width = 256;
 
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
    printf("%s", line);

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }   


    for (int i = 0; i < 3; i++){
        if (i)
            fprintf(file, ", ");
        fprintf(file, "%s", line);
    }  
    fprintf(file, " %d", count);
    fclose(file);     
    return 0;
}

