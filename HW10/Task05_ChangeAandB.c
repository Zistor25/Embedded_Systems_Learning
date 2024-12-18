#include <stdio.h>

const int str_width = 1000;
 
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

    for(int i=0;i<count;i++){
        if(str[i]=='a'){
            str[i]='b';
            continue;
        }
        
        if(str[i]=='b'){
            str[i]='a';
            continue;
        }
        
        if(str[i]=='A'){
            str[i]='B';
            continue;
        }
        
        if(str[i]=='B'){
            str[i]='A';
            continue;
        }
    }
    
//    printf("%s", str);
    

    if((file = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }   
    fprintf(file, "%s", str);

    fclose(file);     
    return 0;
}
