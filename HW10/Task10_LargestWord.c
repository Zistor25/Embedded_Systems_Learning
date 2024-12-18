#include <stdio.h>
#include <string.h>

const int line_width = 1000;

int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_width];
char line_tmp[line_width];
char c;

FILE *file;  

    if((file = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }

    int count=0;
    int count_tmp=0;
    int i=0;
    int j=0;
    while(((c = getc(file)) != EOF) && (c != '\n')){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            line_tmp[i]=c;
            count_tmp++;
            i++;
        }
        else{
            if(count_tmp>count){
                for(j=0;j<count_tmp;j++){
                    line[j]=line_tmp[j];
                }
                count=count_tmp;
                i=0;
                count_tmp=0;
            }
            else{
                i=0;
                count_tmp=0;
            }
        }
    }
    
    //костыль, если в файле содежится только одно слово
    if(count_tmp>0 && count==0){
        for(j=0;j<count_tmp;j++){
            line[j]=line_tmp[j];
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

