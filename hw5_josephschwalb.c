/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) calloc(stack->capacity * sizeof(char), sizeof(char));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}


int check_string(char *char_arr, struct Stack *stack){
  int idx, base_val = 0;
  char *tmp_arr = char_arr, *string;
  if (char_arr != NULL){
    while ((char_arr = strchr(char_arr, '{')) != NULL){
      char_arr++;
      push(stack, '{');
      base_val++;
    }
    char_arr = tmp_arr;

    while ((char_arr = strchr(char_arr, '}')) != NULL){
      char_arr++;
      pop(stack);
      base_val--;
    }
  }
  return base_val;
}


int get_linecount(FILE *file){
  int linecount = 0;
  char *tok, buff[500];
  while (fgets(buff, 500, file) != NULL){
    tok = strtok(buff, "\n");
    linecount++;
  }
  fclose(file);
  return linecount;
}

void read_file(FILE *file, struct Stack* stack){
  char *arr;
  arr = (char*)calloc(50000, sizeof(char));
  int linecount = 0, check_val, counter = 0;
  char buff[500], *tok;
  while (fgets(buff, 500, file) != NULL){
    tok = strtok(buff, "\n");
    check_val = check_string(tok, stack);
    if (check_val != 0){
      if (check_val > 0){
        printf("There are too many { in line %d\n", (linecount + 1));
      }
      else
        printf("There are too many } in line %d\n", (linecount + 1));
    }
    linecount++;
  }
  printf("End of file.\n");
  fclose(file);
}

// Driver program to test above functions
int main()
{
    char filename[500];
    printf("Please enter a filename: \n");
    scanf("%s", filename);
    printf("filename=%s\n", filename);

    struct Stack* stack = createStack(100);
    FILE *file = fopen(filename, "r");
    if (file == NULL){
      printf("NULL\n");
    }

    int linecount = get_linecount(file);

    file = fopen("hw3_josephschwalb.c", "r");
    read_file(file, stack);




    return 0;
}
