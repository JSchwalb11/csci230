#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
  char c, *test_case_string, *string;
  int idx;

  string = (char*)calloc(10, sizeof(char));
  test_case_string = (char*)calloc(2,sizeof(char));
  //char_arr = (char*)calloc(10, sizeof(char));
  //int_arr = (int*)calloc(3000, sizeof(int));
  //&*int_arr[idx]

  //test_case_string = "test";

  if (string == NULL){
    printf("Error allocating memory for string\n");
  }

  if (test_case_string == NULL){
    printf("Error allocating memory for test_case_string\n");
  }

  for (idx = 0; c != '\n'; idx++){
    c = getchar();
    //strcpy(&(*string[idx]), c);
    string[idx]=c;

  }
  printf("String: %s\n", string);
  //(while(c != '\n'){
    //test_case_string = (char*)calloc(2,sizeof(char));
    //printf("Enter char: \n");
    //c = getchar();

    //strncat(string, c, 1);
    //c = getchar();

    //putchar(string);
    //printf("C: %c\n", c);
    //printf("string: %s\n", string);
    //c = getchar();

    /*
    if (c == '\r'){
      printf("Enter character detected...\n");
    }
    */

    /*
    if (strcmp(c, NULL) == 0){
      printf("C: NULL");
    }
    */
    //printf("*C: %c\n", *c);

    /*
    if (strcmp(*c, "\r") == 0 || strcmp(*c, "\n") == 0){
      strcpy(test_case_string, "\0");
      break;
    }
    //strcat(string, &c);
    //putchar(&c);
    //strcat(test_case_string, c);
    */



  //printf("%s\n", test_case_string);
  //printf("String: %s\n", string);
  //printf("It worked so far...\n");
  /*
  while(strcmp(test_case_string))
  printf("enter character: \n");

  c = getchar();

  printf("Char entered: ");
  putchar(c);
  */
  return 0;
}
