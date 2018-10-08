/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"

struct words* check_array(struct words* arr, int idx){
  struct words *tmp_arr;
  tmp_arr = arr;

  if ((idx % MAX_SIZE) < 1){
    tmp_arr = (struct words*)calloc((MAX_SIZE*((idx/MAX_SIZE)+1)), sizeof(struct words));
    printf("memory taken <size allocated for tmp_arr> = %ld\n", ((MAX_SIZE*((idx/MAX_SIZE)+1)) * sizeof(struct words)));
    //printf("(idx/MAX_SIZE)+1 = %d\n", (idx/MAX_SIZE) + 1);
    //printf("tmp_arr / sizeof(struct words) = %ld\n", (tmp_arr / sizeof(struct words)));
    if (tmp_arr == NULL){
      printf("Error allocating space for tmp_arr");
    }
    //printf("Made new array\n");

    memcpy(tmp_arr, arr, idx);

  }
  return tmp_arr;
}
