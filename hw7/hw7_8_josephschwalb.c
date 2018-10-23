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
  FILE* poem = fopen("hw8data.txt", "r");
  FILE* codex = fopen("hw8codex.txt", "r");
  struct node* poem_head = read_poem(poem);
  fclose(poem);
  struct codex* codex_head = read_codex(codex);
  fclose(codex);
  struct node* out_l = assemble(poem_head, codex_head);
  print_list(out_l);
  free_list(poem_head);
  free_clist(codex_head);
  free_list(out_l);
}
