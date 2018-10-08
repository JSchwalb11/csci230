/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#include "read_file_2.h"


/*
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
*/

void read_file(FILE *file, struct words *arg_arr){
  int linecount = 0;
  char buff[50], *tok, tmp_str[51];
  struct words *arr;
  arr = arg_arr;
  while (fgets(buff, 50, file) != NULL){
    //printf("Buff before = %s\n", buff);
    //strcpy(buff,buff_tolower(buff));
    //printf("Buff after = %s\n", buff_tolower(buff));
    tok = strtok(buff, " ");
    strcpy(tmp_str, tok);
    //strcat(tmp_str, "\0");
    if (linecount < 10){
      //printf("tolower(tmp_str) = %s\n", tolower_string(tmp_str));
      //printf("tmp_str = %s\n", tmp_str);
    }
    printf("arr(hex)= %x\n", arr);
    arr = check_array(arr, linecount);
    linecount++;
  }
  printf("End of file.\n");
  fclose(file);
}
