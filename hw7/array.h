#ifndef ARRAY_H
#define ARRAY_H

/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#define MAX_SIZE 10

typedef struct words{
  int count;
  char word[51];
}words;

typedef struct node{
  char* data;
  struct node* next;
}node;

typedef struct codex{
  char *word1;
  char *word2;
  struct codex *next;
}codex;

int compare (const void * a, const void * b);
struct words* check_array(struct words* arr, int idx);
struct words* tag_cloud(struct words* arr, const int size);
struct node* check_list(struct node* arr, int idx);
struct node* insert(struct node* head, char* val);
struct node* insert_last(struct node* loc, char* val);
struct codex* insertc_last(struct codex* loc, char* val1, char* val2);
struct codex* create_codex(char* val1, char* val2);
struct node* create_node(char* data);
struct node* del_node(struct node* head, int idx);
int isEmpty(struct node* head);
void print_list(struct node* head);
void print_clist(struct codex* head);
void free_list(struct node* head);
void free_clist(struct codex* head);
struct node* traverse_node_l(struct node* head);
struct codex* traverse_codex_l(struct codex* head);
struct node* assemble(struct node* node_l, struct codex* codex_l);






#endif
