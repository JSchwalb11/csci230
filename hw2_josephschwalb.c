/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stuff{
    char string[15];
    float some_float;
    int some_int;
    char color[15];
};

//We must include a global variable because the compare function cannot
//recieve the option as a parameter
int sort_option;

//The compare function used by qsort
int compare (const void * a, const void * b)
{
    //1 = float / desc
    //2 = float / asc
    //3 = int / desc
    //4 = int / asc
    
    struct stuff *stuffA = (struct stuff *)a;
    struct stuff *stuffB = (struct stuff *)b;   
  
    if (sort_option == 1){    
        float diff = ( stuffB->some_float - stuffA->some_float );
        return diff>0? 1 : diff<0?-1 : 0;
    }
    
    if (sort_option == 2){
        float diff = ( stuffA->some_float - stuffB->some_float );
        return diff>0? 1 : diff<0?-1 : 0;
    }
    
    if (sort_option == 3){
        return ( stuffB->some_int - stuffA->some_int );
    }       
      
    if (sort_option == 4){
        return ( stuffA->some_int - stuffB->some_int );
    }
}

void print_array(struct stuff array[], const int count){
    int i;
    for (i = 0; i < count; i++){
        printf("%s %f %d %s", array[i].string, array[i].some_float, array[i].some_int, array[i].color);
    }
}


void main()
{
    struct stuff array[100];    
    FILE *fptr;
    char *tok, buff[2550];
    int count, choice;
    
    
    printf("Opening the file: %s\n", "hw2.data");       
    fptr = fopen("hw2.data", "r");

    //Check if file exists    
    if (fptr == NULL){
        printf("Error opening file...\n");
        exit(0);
    }
    
    count = 0;
    
    //Read one line at a time...
    while (fgets(buff, 2550, fptr) != NULL){
        //Tokenize the buffer
        tok = strtok(buff, " ");
        
        //Iterate through tokens & assign appropriate fields
        strcpy(array[count].string, tok);
        tok=strtok(NULL," ");
        array[count].some_float = atof(tok);
        tok=strtok(NULL," ");
        array[count].some_int = atof(tok);
        tok=strtok(NULL," ");
        strcpy(array[count].color, tok);

        count++;
    }
           
    do{
        printf("1. Sort data by the float value & print high to low\n");
        printf("2. Sort data by the float value & print low to high\n"); 
        printf("3. Sort data by the int value & print high to low\n");
        printf("4. Sort data by the int value & print low to high\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
    
        if (choice == 1){
            sort_option = choice; //Setting the option for the compare function
            qsort (array, count, sizeof(struct stuff), compare);
            print_array(array, count);
        }
        
        if (choice == 2){
            sort_option = choice; //Setting the option for the compare function
            qsort (array, count, sizeof(struct stuff), compare);
            print_array(array, count);
        }

        if (choice == 3){
            sort_option = choice; //Setting the option for the compare function
            qsort (array, count, sizeof(struct stuff), compare);
            print_array(array, count);
        }
        
        if (choice == 4){
            sort_option = choice; //Setting the option for the compare function
            qsort (array, count, sizeof(struct stuff), compare);
            print_array(array, count);
        }
        
        //Checking for valid input
        if (choice > 5 || choice < 1){
            printf("Enter a number between 1,5\n");
            scanf("%d", &choice);
        }
    }
    
    while (choice != 5);       
    
    printf("Quitting\n");
    exit(1);
}
