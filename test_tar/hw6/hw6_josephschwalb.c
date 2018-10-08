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
  FILE *file = fopen(argv[1], "r");
  arr = (struct words*)calloc(MAX_SIZE, sizeof(struct words));
  read_file(file, arr);
}
