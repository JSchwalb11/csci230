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
  FILE* file = fopen("hw9.data", "r");
  int* int_arr = read_int_file(file);
  int idx;

  printf("Before Sort:\n");
  for (idx = 0; int_arr[idx] != 0; idx++){
    printf("%d\n", int_arr[idx]);
  }

  struct node* root = b_tree(int_arr);
  struct node* head = create_list(NULL, root);

  printf("\nSorted:\n");
  in_order(root);
  printf("\nBackwards:\n");
  post_order(root);
  printf("\nLinked List:\n");
  print_list(head);

  free_list(head);
}
