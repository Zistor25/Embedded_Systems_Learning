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

    int j = 0;
    while(((c = getc(file)) != EOF) && (c != '\n')){
        int count = 1;
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            for(int i=0;i<j;i++){
                (c==line[i]) ? count++ : count;
            }
            if (count ==1)
                    line[j++] = c;
        }
    }
    line[j++] = '\0';
 
    fclose(file); 

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }   

    fprintf(file,"%s ",line);

    fclose(file);
    return 0;
}

