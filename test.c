#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
int i, tmp_int;
float tmp_flt;
char buff[255], *tok, tmp_str;
FILE *fptr;

fptr = fopen("hw2.data", "r");

if (fptr == NULL){
    printf("Error opening file...\n");
}

while (fgets(buff, 255, fptr) != NULL){
    tok = strtok(buff, " \n");

    while (tok != NULL){
        /*
        strcpy(tmp_str, tok);
        printf("%s\n", tmp_str);
        */
        tmp_flt = atof(tok);
        printf("%f\n", tmp_flt);
        /*
        tmp_flt = atof(tok);
        printf("%d\n", tmp_int);

        strcpy(tmp_str, tok);
        printf("%s\n", tmp_str);
        */
    }        
        /*         

            printf("%s\n", tok);
            tok=strtok(NULL," \n");
            printf("%d\n", atof(tok));
            tok=strtok(NULL," \n");
            printf("%d\n", atof(tok));
            tok=strtok(NULL," \n");
            printf("%s\n", tok);
                        
        }
        printf("done");
*/
}
}
