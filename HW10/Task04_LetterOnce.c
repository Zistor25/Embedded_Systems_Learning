#include <stdio.h>
#include <string.h>

const int str_width = 100;
 
int main(void)
{
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char str1[str_width];
    char str2[str_width];
    char answers[str_width];

    FILE *file;  

    if((file = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    file = fopen(input_fn, "r");
    fscanf(file, "%[a-z] %[a-z]", str1, str2);
    
    int count;
    int index = 0;
    for(int i=0;i<strlen(str1);i++){
        count =0;
        
        for (int j=0;j<strlen(str1);j++){
            if(str1[i]==str1[j])
                count++;
            }
            if(count!=1)
                continue;
        
        for (int j=0;j<strlen(str2);j++){
            if(str1[i]==str2[j])
                count++;
            }
            if(count!=2)
                continue;

        answers[index++] = str1[i];
        answers[index++] = ' ';
        }
        answers[index++] = '\0';

    fclose (file);

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }   
    fprintf(file, "%s", answers);

    fclose(file);     
    return 0;
}
