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
struct node* check_list(struct node* arr, int idx){
  struct node* tmp_arr;
  tmp_arr = arr;

  if ((idx % MAX_SIZE) < 1){
    tmp_arr = (struct node*)calloc((MAX_SIZE*((idx/MAX_SIZE)+1)), sizeof(struct node));
    memcpy(tmp_arr, arr, (idx*sizeof(struct node)));
  }
  return tmp_arr;
}
struct node* insert(struct node* head, char* val){
  struct node* _new = create_node(val);
  _new->next = head;
  return _new;
}
void insert_at(struct node* loc, char* val){
  struct node* _new = create_node(val);
  _new->next = loc->next;
  loc->next = _new;
}
struct node* insert_last(struct node* loc, char* val){
  struct node* _new = create_node(val);
  loc->next = _new;
  return _new;
}
struct codex* insertc_last(struct codex* loc, char* val1, char* val2){
  struct codex* _new = create_codex(val1, val2);
  loc->next = _new;
  return _new;
}
struct codex* create_codex(char* val1, char* val2){
  struct codex* tmp;
  tmp = (struct codex*) calloc (1, sizeof(struct codex));
  tmp->next = NULL;
  tmp->word1 = val1;
  tmp->word2 = val2;
  return tmp;
}
struct node* create_node(char* data){
  struct node* tmp;
  tmp = (struct node*) calloc (1, sizeof(struct node));
  tmp->data = data;
  return tmp;
}
struct node* del_node(struct node* head, char* val){
  int i;
  struct node* current, *previous;
  if (head == NULL){
    return NULL;
  }

  current = head;
  previous = NULL;

  while (strcmp(val, current->data) != 0){
    if (current->next != NULL){
      previous = current;
      current = current->next;
    }
    else
      return head;

  previous->next = current->next;
  free(current);

  return head;
}
int isEmpty(struct node* head){
  if (head == NULL){
    printf("head is null\n");
    return 1;
  }
  if (head->next == NULL){
    return 1;
  }
  return 0;
}
void print_list(struct node* head){
  if(head){
    print_list(traverse_node_l(head));
    printf("%s\n", head->data);
  }
}

void print_clist(struct codex* head){
  struct codex* current = head;

  while (current->next != NULL){
      printf("current->word1 = %s\n", current->word1);
      printf("current->word2 = %s\n", current->word2);
      current = traverse_codex_l(current);
  }
  printf("current->word1 = %s\n", current->word1);
  printf("current->word2 = %s\n", current->word2);
}
void free_list(struct node* head){
  if (head->next != NULL){
    free_list(head->next);
  }
  free(head);
}
void free_clist(struct codex* head){
  if (head->next != NULL){
    free_clist(head->next);
  }
  free(head);
}
struct node* traverse_node_l(struct node* loc){
    return loc->next;
}
struct codex* traverse_codex_l(struct codex* head){
  return head->next;
}
struct node* assemble(struct node* node_l, struct codex* codex_l){
  struct node* current_n = node_l;
  struct codex* current_c;

  while (current_n != NULL){
    current_c = codex_l;
    while (current_c != NULL){
      if (strcmp(current_n->data, current_c->word1) == 0){
        current_n->data = current_c->word2;
      }
      current_c = traverse_codex_l(current_c);
    }
    current_n = traverse_node_l(current_n);
  }
  return node_l;
}
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
void in_order(struct node* root){
  if (root){
    in_order(root->left);
    printf("%s\n", root->data);
    in_order(root->right);
  }
}
void post_order(struct node* root){
  if (root){
    in_order(root->left);
    in_order(root->right);
    printf("%s\n", root->data);
  }
}

struct node* create_list(struct node* head, struct node* loc){
  if (loc){
    head = create_list(head, loc->left);
    head = insert(head, loc->data);
    //printf("inserted : %s\n", loc->data);
    head = create_list(head, loc->right);
  }
  return head;
}
