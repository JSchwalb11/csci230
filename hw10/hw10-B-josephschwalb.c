/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hw10-A-josephschwalb.h"
#include "hw10-B-josephschwalb.h"
#include "hw10-C-josephschwalb.h"


struct node* insert(struct node* head, char* val){
  struct node* _new = create_node(val);
  _new->next = head;
  return _new;
}
struct node* create_node(char* data){
  struct node* tmp;
  tmp = (struct node*) calloc (1, sizeof(struct node));
  tmp->data = data;
  return tmp;
}
void print_list(struct node* head){
  if(head){
    print_list(traverse_node_l(head));
    printf("%s\n", head->data);
  }
}
struct node* traverse_node_l(struct node* loc){
    return loc->next;
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
