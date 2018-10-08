/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"

int compare (const void * a, const void * b){
  struct words *stuffA = (struct words *)a;
  struct words *stuffB = (struct words *)b;

  if ((stuffA->count - stuffB->count) > 0)
        return -1;
  else if ((stuffA->count - stuffB->count) < 0)
        return 1;
  else
        return 0;
}

struct words* check_array(struct words* arr, int idx){
  struct words *tmp_arr;
  tmp_arr = arr;

  if ((idx % MAX_SIZE) < 1){
    tmp_arr = (struct words*)calloc((MAX_SIZE*((idx/MAX_SIZE)+1)), sizeof(struct words));
    memcpy(tmp_arr, arr, (idx*sizeof(struct words)));
  }
  return tmp_arr;
}

struct words* tag_cloud(struct words* arr, const int size){
  int i,j, dups;

  struct words* cloud;
  cloud = (struct words*) calloc (size, sizeof(struct words));

  for (i = 0; i < size; i++){
    dups = 0;
    for (j = i+1; j < size; j++){
      if (strcmp((arr+j)->word, "")){
        //do nothing
      }
      if (strcmp((arr+i)->word, (arr+j)->word) == 0){
        dups++;
        strcpy((arr+j)->word, "");
        (arr+j)->count = 0;
      }
    }
    (arr+i)->count += dups;
  }

  qsort (arr, size, sizeof(struct words), compare);

  for (i = 0, j = 0; i < size; i++){
    if (strcmp((arr+i)->word, "") != 0){
      strcpy((cloud+j)->word, (arr+i)->word);
      (cloud+j)->count = (arr+i)->count;
      j++;
    }
  }

  printf("Tag Cloud\n");
  for (i = 0; i < 10; i++){
    printf("%-50s\t%d\n", (cloud+i)->word, (cloud+i)->count);
  }

  return cloud;
}
