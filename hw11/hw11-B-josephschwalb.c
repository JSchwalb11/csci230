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


struct node* insert(struct node* head, char* val){
  //printf("test_insert\n");
  struct node* _new = create_node(val);
  _new->next = head;
  return _new;
}
struct node* insert_at(struct node* head, char* key, char* val){
  struct node* _new = create_node(val), *current, *previous;
  current = head;
  previous = NULL;

  while (strcmp(key, current->data) != 0){
    if (current->next){
      previous = current;
      current = current->next;
    }
    else{
      printf("key: %s not found\n", key);
      return head;
    }
  }
  previous->next = _new;
  _new->next = current;
  return head;
}
struct node* sort_ll(struct node* head){
  struct node *current, *previous, *tmp, *previous_h;
  void *tmp_ptr;
  int i = 0, j = 0;
  tmp = create_node("");
  while (head->next){
    current = head;
    previous = NULL;
    previous_h = NULL;
    while (current->next){
      if (strcmp(head->data, current->data) == 1){
        /*
        printf("--before swap--\n");
        printf("head <%x> <%s>\n", head, head->data);
        printf("current <%x> <%s>\n", current, current->data);
        */

        tmp_ptr = current->data;
        current->data = head->data;
        head->data = tmp_ptr;
        /*
        printf("--after swap--\n");
        printf("head <%x> <%s>\n", head, head->data);
        printf("current <%x> <%s>\n", current, current->data);
        printf("i: %d\n", i);
        */
      }
      i+=1;
      previous = current;
      current = traverse_node_l(current);
    }
    //printf("j: %d\n", j);
    j+=1;
    previous_h = head;
    head = traverse_node_l(head);
  }
}
struct node* create_node(char* data){
  struct node* tmp;
  tmp = (struct node*) calloc (1, sizeof(struct node));
  tmp->data = data;
  return tmp;
}
struct node* del_node(struct node* head, char* val){
  struct node *current, *previous, *tmp;
  current = head;
  previous = NULL;
  while (strcmp(val, current->data) != 0){
    //("current->data : %s\n", current->data);
    if (current->next){
      previous = current;
      current = current->next;
    }
    else{
      printf("Name: %s not found\n", val);
      return head;
    }
  }

  //printf("val: %s found\n", val);
  //printf("Deleted: %s\n", val);
  previous->next = current->next;
  free(current);
  return head;
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
