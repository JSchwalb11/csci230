#include "hw5_func.h"
#include "stack.h"

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
