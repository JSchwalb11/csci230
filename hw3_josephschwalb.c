/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
TODO: change array[linecount] to allocate memory, then put the tokens into the struct obj.
Sort array with qsort
write sorted array to file
*/

int linecount; //Declare global linecount

struct word{
    char string[50];
};

struct fptr{
  FILE *file;
  char filename[15];
};

int compare (const void * a, const void * b)
{
    struct word *stuffA = (struct word *)a;
    struct word *stuffB = (struct word *)b;
    return strcmp(stuffA->string, stuffB->string);
}

int main(){

  char *tok;
  char buff[50];
  struct fptr files[4];
  linecount = 0;
  int idx;
  strcpy(files[0].filename, "american0.txt");
  strcpy(files[1].filename, "american1.txt");
  strcpy(files[2].filename, "american2.txt");
  strcpy(files[3].filename, "words.txt");

  for (idx = 0; idx <= 3; idx++){
    if (idx == 3){
      files[idx].file = fopen(files[idx].filename, "w");
    }
    else
      files[idx].file = fopen(files[idx].filename, "r");

    if (files[idx].file == NULL){
      printf("Error opening file: %s\n", files[idx].filename);
      exit(0);
    }

  }



  for (idx = 0; idx < 3; idx++){
    //Read only the first three files
    printf("Reading from file: %s\n", files[idx].filename);
    while (fgets(buff, 50, files[idx].file) != NULL){
      tok = strtok(buff, " ");
      fprintf(files[3].file, "%s", tok);
      //printf("%s\n", tok);
      tok=strtok(NULL," ");
      linecount++;
    }
    fclose(files[idx].file);
  }
  fclose(files[3].file);

  int *memory_init, *memory_test;
  char *array = (char*)calloc(linecount * 50, sizeof(char));
  memory_init = array;
  files[3].file = fopen(files[3].filename, "r");

  while (fgets(buff, 50, files[3].file) != NULL){
    tok = strtok(buff, " ");
    strcpy(array, tok);
    //printf("%s\n", array[idx].string);
    tok=strtok(NULL," ");
    //printf("test: %s\n", *(&array));
    array+=50;
  }
  array = array-(linecount * 50);
  memory_test = array;
  if (memory_init == memory_test){
    printf("Memory pointers are equal\n");
  }
  else
    printf("Not equal\n");

  fclose(files[3].file);



  //printf("Before sort: \n");

  /*
  for (idx = 0; idx < linecount; idx++){
    printf("%s\n", array[idx].string);
  }
  */

  qsort (array, linecount, sizeof(struct word), compare);
  /*
  printf("After sort: \n");
  for (idx = 0; idx < linecount; idx++){
    printf("%s", array[idx].string);
  }
  */

  files[3].file = fopen(files[3].filename, "w");
  printf("linecount * 50 = : %d\n", linecount * 50);
  for (idx = 0; idx < (linecount * 50); idx+=50){
    fprintf(files[3].file, "%s", array+idx);
  }
  printf("Wrote sorted strings to file: %s\n", files[3].filename);

  fclose(files[3].file);

  return 0;
}
