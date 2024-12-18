#include <stdio.h>

const int str_width = 1000;

int is_palindrom(char str[]){
    int len=0;
    while ((str[len]!='\0')){
        len++;
    }
    int count=0;
    for (int i=0; i<=(len/2-1); i++){
        if (str[i]==str[len-i-1]){
            count++;
            }
        }
        
    if (count==(len/2)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char str[str_width];
    char c;
    

    FILE *file;  

    if((file = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }
    
    int count = 0;
    while(((c = getc(file)) != EOF) && (c != '\n'))
        str[count++] = c;
    str[count] = '\0';
    
    fclose(file); 


    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }
    
    fprintf(file, "%s", is_palindrom(str) ? "YES" : "NO");

    fclose(file);     
    return 0;
}
