/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hw11-A-josephschwalb.h"
#include "hw11-B-josephschwalb.h"
#include "hw11-C-josephschwalb.h"
#include "read_file.h"
#include <ctype.h>

char* parse_tok(char* tok){
  char* str; int idx;
  str = (char *) calloc (51,sizeof(char));
  //for (idx = 0; idx < (strlen(tok) - 2); idx++){
  for (idx = 0; idx < strlen(tok); idx++){
    char next_ch;
    next_ch = *(tok+idx);
    if (ispunct(next_ch)){
      break;
    }
    *(str+idx) = next_ch;
  }
  //strcat(&str[strlen(tok)-2], "\0");
  strcat(&str[strlen(tok)], "\0");
  return str;
}
int* read_int_file(FILE* file){
  int linecount, *int_arr;
  char buff[50], *tok;
  //struct node* head = create_node(NULL);
  //struct node* tail = head;

  int_arr = (int*) calloc (1,sizeof(int));
  for (linecount = 0; fgets(buff, sizeof(buff), file) != NULL; linecount++){
    tok = strtok(buff, " \n\r");
    int_arr = check_int_array(int_arr, linecount);
    *(int_arr + linecount) = atoi(tok);
    //printf("*(int_arr + linecount) : %d\n", *(int_arr + linecount));
  }
  fclose(file);
  return int_arr;
}
