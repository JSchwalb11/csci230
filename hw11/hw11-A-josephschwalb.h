#ifndef HW11_A_JOSEPHSCHWALB_H
#define HW11_A_JOSEPHSCHWALB_H

/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#define MAX_SIZE 11

typedef struct words{
  int count;
  char word[51];
}words;

typedef struct node{
  char* data;
  struct node* next;
  struct node* left;
  struct node* right;
}node;

typedef struct codex{
  char *word1;
  char *word2;
  struct codex *next;
}codex;

int compare (const void * a, const void * b);
struct words* check_array(struct words* arr, int idx);
int* check_int_array(int* arr, int idx);
struct node* check_list(struct node* arr, int idx);
struct node* create_node(char* data);
void insert_b_t(struct node* loc, int val);
struct node* b_tree(int* arr);

#endif
