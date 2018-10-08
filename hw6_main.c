/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#include "read_file.h"

void main(int argc, char *argv[]){
  struct words *arr;
  int test = 0, *int_arr;
  arr = (struct words*)calloc(MAX_SIZE, sizeof(struct words));
/*
  int_arr = (int*)calloc(MAX_SIZE, sizeof(int));
  for (test = 0; test < 10000; test++){
    *(int_arr + test) = test;
    printf("*(int_arr + test) = %d\n",*(int_arr + test));
    int_arr = check_int_array(int_arr, test);
  }
*/
  if (arr == NULL){
    printf("arr==NULL\n");
  }
  //printf("sizeof(struct words)= %ld\n", sizeof(struct words));
  FILE *file = fopen(argv[1], "r");
  if (file == NULL){
    printf("File is null\n");
  }
  read_file(file, arr);
  printf("Done.\n");
}
