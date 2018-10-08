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
#include <ctype.h>

char* parse_tok(char* tok, struct words* arr){
  char* str; int idx;
  str = (char *) calloc (51,sizeof(char));
  for (idx = 0; idx < (strlen(tok) - 2); idx++){
    char next_ch;
    next_ch = tolower(*(tok+idx));
    if (ispunct(next_ch)){
      break;
    }
    *(str+idx) = next_ch;
  }
  strcat(&str[strlen(tok)-2], "\0");
  return str;
}

void read_file(FILE *file, struct words *arg_arr){
  int linecount;
  char buff[50], *tok, *tmp_str;
  struct words *arr;
  arr = arg_arr;

  for (linecount = 0; fgets(buff, 50, file) != NULL; linecount++){
    arr = check_array(arr, linecount);
    tok = strtok(buff, " ");
    tmp_str = parse_tok(tok, arr);
    strcpy((arr+linecount)->word, tmp_str);
    tmp_str = NULL;
  }
  tag_cloud(arr, linecount);
  printf("End of file.\n");
  fclose(file);
}
