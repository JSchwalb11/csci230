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


void free_list(struct node* head){
  if (head->next != NULL){
    free_list(head->next);
  }
  free(head);
}
