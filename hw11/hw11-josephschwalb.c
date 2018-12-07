/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "hw11-A-josephschwalb.h"
//#include "hw11-B-josephschwalb.h"
//#include "hw11-C-josephschwalb.h"
//#include "read_file.h"
#include <dlfcn.h>

void* getFunctionPointer(void* lib, const char* funcName) {
 //
 // Get the function pointer to the function
    void* fptr = dlsym(lib, funcName);
    if (!fptr) {
      fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
      return NULL;
    }
    return fptr;
}

struct node* read_op_file(FILE* file){
  //name <a|d>
  int linecount;
  char buff[50], *tok;
  char *name, *option;

  //struct node* head;
  struct node*  (*fptr_insert_node)(struct node*, char* val);
  struct node*  (*fptr_del_node)(struct node*, char* val);
  struct node*  (*fptr_create_node)(char* data);
  void (*fptr_print_list)(struct node* head);


  void* lib_hw11 = dlopen("./hw11-lib-josephschwalb.so",  RTLD_LAZY | RTLD_GLOBAL);
  if (!lib_hw11){
    printf("!lib_hw11\n");
  }

  fptr_insert_node = getFunctionPointer(lib_hw11, "insert");
  fptr_del_node = getFunctionPointer(lib_hw11, "del_node");
  fptr_create_node = getFunctionPointer(lib_hw11, "create_node");
  fptr_print_list = getFunctionPointer(lib_hw11, "print_list");

  struct node* head = NULL;

  for (linecount = 0; fgets(buff, sizeof(buff), file) != NULL; linecount++){
    name = (char*) calloc (sizeof(buff), sizeof(char));
    option = (char*) calloc (sizeof(buff), sizeof(char));
    tok = strtok(buff, " \n\r");
    strcpy(name, tok);
    if (!name){
      printf("!name\n");
    }
    option = strtok(NULL, " \n\r");
    if (!option){
      printf("!option\n");
    }
    if (strcmp(option, "a") == 0){
      head = fptr_insert_node(head, name);
      //printf("added: %s\n", name);
    }
    else if (strcmp(option, "d") == 0){
      head = fptr_del_node(head, name);
    }
    else
      printf("Unexpected option: %s <%x> for name: %s\n", option, option, name);

  }
  return head;
}

void main(int argc, char *argv[]){
 // Declare the function pointers:


 //
 // Open the dynamic library
    void* lib_hw11 = dlopen("./hw11-lib-josephschwalb.so",  RTLD_LAZY | RTLD_GLOBAL);

    if (!lib_hw11) {
     //
     // Apparently, the library could not be opened
        fprintf(stderr, "Could not open hw11-lib-josephschwalb.so\n");
        exit(1);
    }

    int* (*fptr_read_int_file)(FILE*);
    struct node* (*fptr_b_tree)(int*);
    struct node* (*fptr_create_list)(struct node*, struct node*);
    void (*fptr_in_order)(struct node*);
    void (*fptr_post_order)(struct node*);
    void  (*fptr_print_list)(struct node*);
    void  (*fptr_free_list)(struct node*);
    struct node* (*fptr_sort_ll)(struct node*);



    FILE* file = fopen("op_code.txt", "r");
    if (!file){
      printf("!file\n");
    }

    fptr_read_int_file = getFunctionPointer(lib_hw11, "read_int_file");
    fptr_b_tree = getFunctionPointer(lib_hw11, "b_tree");
    fptr_create_list = getFunctionPointer(lib_hw11, "create_list");
    fptr_in_order = getFunctionPointer(lib_hw11, "in_order");
    fptr_post_order = getFunctionPointer(lib_hw11, "post_order");
    fptr_print_list = getFunctionPointer(lib_hw11, "print_list");
    fptr_free_list = getFunctionPointer(lib_hw11, "free_list");
    fptr_sort_ll = getFunctionPointer(lib_hw11, "sort_ll");



    struct node* head = read_op_file(file);
    printf("\n\n=================Unsorted=================\n\n");
    printf("\n\n==========================================\n\n");
    fptr_print_list(head);
    //sort
    fptr_sort_ll(head);
    printf("\n\n=================Sorted=================\n\n");
    printf("\n\n========================================\n\n");
    fptr_print_list(head);
    //printf("\nSuccess\n");
    fptr_free_list(head);
    printf("\nFreed List\n");

}
