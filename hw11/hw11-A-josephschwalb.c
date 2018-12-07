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

int compare (const void * a, const void * b){
  struct node* stuffA = (struct node*)a;
  struct node* stuffB = (struct node*)b;

  if ((stuffA->data - stuffB->data) > 0)
        return -1;
  else if ((stuffA->data - stuffB->data) < 0)
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
    free(arr);
  }
  return tmp_arr;
}
int* check_int_array(int* arr, int idx){
  int* tmp_arr;
  tmp_arr = arr;

  if ((idx % MAX_SIZE) < 1){
    tmp_arr = (int*)calloc((MAX_SIZE*((idx/MAX_SIZE)+1)), sizeof(int));
    memcpy(tmp_arr, arr, (idx*sizeof(int)));
  }
  return tmp_arr;
}
struct node* check_list(struct node* arr, int idx){
  struct node* tmp_arr;
  tmp_arr = arr;

  if ((idx % MAX_SIZE) < 1){
    tmp_arr = (struct node*)calloc((MAX_SIZE*((idx/MAX_SIZE)+1)), sizeof(struct node));
    memcpy(tmp_arr, arr, (idx*sizeof(struct node)));
  }
  return tmp_arr;
}
/*
void insert_at(struct node* loc, char* val){
  struct node* _new = create_node(val);
  _new->next = loc->next;
  loc->next = _new;
}
*/
void insert_b_t(struct node* loc, int val){
  char* int_str = (char*) calloc (50, sizeof(char));
  sprintf(int_str, "%d", val);
  if (atoi(loc->data) >= val){
    if (!loc->left){
      loc->left = create_node(int_str);
    }
    else{
      insert_b_t(loc->left, val);
    }
  }
  else{
    if (!loc->right){
      loc->right = create_node(int_str);
    }
    else{
      insert_b_t(loc->right, val);
    }
  }
}
struct node* b_tree(int* arr){
  int idx;
  char* int_str = (char*) calloc (50, sizeof(char));
  sprintf(int_str, "%d", arr[0]);
  struct node* root = create_node(int_str);
  //printf("init_ root->data : %s\n", int_str);
  for (idx = 1; *(arr+idx) != 0; idx++){
    insert_b_t(root, arr[idx]);
  }
  return root;
}
