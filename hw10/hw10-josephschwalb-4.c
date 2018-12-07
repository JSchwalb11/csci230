/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "hw10-A-josephschwalb.h"
//#include "hw10-B-josephschwalb.h"
//#include "hw10-C-josephschwalb.h"
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

void main(int argc, char *argv[]){
  //printf("test1\n");
  //
 // Declare the function pointers:


 //
 // Open the dynamic library
    void* lib_hw10 = dlopen("./hw10-lib-josephschwalb.so",  RTLD_LAZY | RTLD_GLOBAL);

    if (!lib_hw10) {
     //
     // Apparently, the library could not be opened
        fprintf(stderr, "Could not open hw10-lib-josephschwalb.so\n");
        exit(1);
    }

    int* (*fptr_read_int_file)(FILE*);
    struct node* (*fptr_b_tree)(int*);
    struct node* (*fptr_create_list)(struct node*, struct node*);
    void (*fptr_in_order)(struct node*);
    void (*fptr_post_order)(struct node*);
    void  (*fptr_print_list)(struct node*);
    void  (*fptr_free_list)(struct node*);

    FILE* file = fopen("hw9.data", "r");
    if (!file){
      printf("!file\n");
    }

    fptr_read_int_file = getFunctionPointer(lib_hw10, "read_int_file");
    fptr_b_tree = getFunctionPointer(lib_hw10, "b_tree");
    fptr_create_list = getFunctionPointer(lib_hw10, "create_list");
    fptr_in_order = getFunctionPointer(lib_hw10, "in_order");
    fptr_post_order = getFunctionPointer(lib_hw10, "post_order");
    fptr_print_list = getFunctionPointer(lib_hw10, "print_list");
    fptr_free_list = getFunctionPointer(lib_hw10, "free_list");


    int* int_arr = fptr_read_int_file(file);
    printf("Before Sort:\n");
    for (int idx = 0; int_arr[idx] != 0; idx++){
      printf("%d\n", int_arr[idx]);
    }
    struct node* root = fptr_b_tree(int_arr);
    if (!root){
      printf("!root\n");
    }
    struct node* head = fptr_create_list(NULL, root);
    if (!root){
      printf("!root\n");
    }
    else if (!head){
      printf("!head\n");
    }
    printf("\nSorted:\n");
    fptr_in_order(root);
    printf("\nBackwards:\n");
    fptr_post_order(root);
    printf("\nLinked List:\n");
    fptr_print_list(head);
    fptr_free_list(head);

    printf("Success\n");

}
