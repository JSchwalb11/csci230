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
void read_file(FILE *file, struct words *arg_arr){
  int linecount;
  char buff[50], *tok, *tmp_str;
  struct words *arr;
  arr = arg_arr;

  for (linecount = 0; fgets(buff, 50, file) != NULL; linecount++){
    arr = check_array(arr, linecount);
    tok = strtok(buff, " ");
    tmp_str = parse_tok(tok);
    strcpy((arr+linecount)->word, tmp_str);
    tmp_str = NULL;
  }
  tag_cloud(arr, linecount);
  printf("End of file.\n");
  fclose(file);
}
struct node* read_poem(FILE *file){
  int linecount, idx, z;
  char buff[42], *tok, *tmp_str, *punct, *str, *line;
  struct node* head = create_node(NULL);
  struct node* tail = head;
  line = (char*) calloc (1, sizeof(char));
  strcpy(line, "\n");

  for (linecount = 0; fgets(buff, 42, file) != NULL; linecount++){
    if (linecount == 0){
      tok = strtok(buff, " \n");
      tmp_str = (char*) calloc (1, sizeof(strlen(tok)));
      strcpy(tmp_str, tok);
      head->data = tmp_str;
      tok = strtok(NULL, " \n\r");
      punct = (char*) calloc (1, sizeof(char));
      strcpy(punct, " ");
      tail = insert_last(head, punct);
    }
    else{
      tok = strtok(buff, " \n\r");
    }

    while (tok != NULL){
      str = (char*) calloc (1, sizeof(strlen(tok)));
      punct = (char*) calloc (1, sizeof(char));
      for (idx = 0; idx < strlen(tok); idx++){
        char next_ch;
        z=0;
        next_ch = *(tok+idx);
        if (ispunct(next_ch)){
          *(punct) = next_ch;
          strcat(punct, "\0");
          z=1;
          break;
        }
        *(str+idx) = next_ch;
      }
      strcat(&str[idx], "\0");
      if (z == 0){
        strcpy(punct, " ");
      }
      tail = insert_last(tail, str);
      tail = insert_last(tail, punct);
      tok = strtok(NULL, " \n\r");
    }
    tail = insert_last(tail, line);
  }
  return head;
}
struct codex* read_codex(FILE *file){
  int linecount;
  char buff[42], *tok, *word1, *word2;
  struct codex* head = create_codex(NULL, NULL);
  struct codex* tail = head;

  for (linecount = 0; fgets(buff, 42, file) != NULL; linecount++){

    tok = strtok(buff, " \n\r");
    if (linecount == 0){
      word1 = (char*) calloc (1, sizeof(strlen(tok)));
      strcpy(word1, tok);
      tok = strtok(NULL, " \n\r");
      word2 = (char*) calloc (1, sizeof(strlen(tok)));
      strcpy(word2, tok);
      tok = strtok(NULL, " \n\r");
      head->word1 = word1;
      head->word2 = word2;
    }

    while (tok != NULL){
      word1 = (char*) calloc (1, sizeof(strlen(tok)));
      strcpy(word1, tok);
      tok = strtok(NULL, " \n\r");
      word2 = (char*) calloc (1, sizeof(strlen(tok)));
      strcpy(word2, tok);
      tok = strtok(NULL, " \n\r");
      tail = insertc_last(tail, word1, word2);
      tok = strtok(NULL, " \n\r");
    }
  }
  return head;
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
