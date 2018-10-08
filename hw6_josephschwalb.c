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
  if(!argv[1]){
    printf("Please re-run with a text file as an argument.\n");
    exit(0);
  }
  int test = 0, *int_arr;
  FILE *file = fopen(argv[1], "r");
  arr = (struct words*)calloc(MAX_SIZE, sizeof(struct words));
  read_file(file, arr);
}
