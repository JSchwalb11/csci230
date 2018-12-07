#ifndef HW11_B_JOSEPHSCHWALB_H
#define HW11_B_JOSEPHSCHWALB_H

/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/

struct node* insert(struct node* head, char* val);
struct node* insert_at(struct node* head, char* key, char* val);
struct node* create_node(char* data);
void print_list(struct node* head);
struct node* traverse_node_l(struct node* head);
void in_order(struct node* root);
void post_order(struct node* root);
struct node* create_list(struct node* head, struct node* loc);
struct node* del_node(struct node* head, char* val);
struct node* sort_ll(struct node* head);

#endif
