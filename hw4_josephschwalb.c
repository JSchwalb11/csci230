/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10
int check_array(char *arr, int idx){if ((idx % MAX_SIZE) < 1){char *tmp_arr;tmp_arr = (char*)calloc((MAX_SIZE*((idx/MAX_SIZE)+1)), sizeof(char));if (tmp_arr == NULL){printf("Error allocating space for tmp_arr");exit(0);}memcpy(tmp_arr, arr, idx);*arr = *tmp_arr;}return *arr;}int main(){char *string, c;int idx, j;string = (char*)calloc(10, sizeof(char));if (string == NULL){printf("Error allocating memory for string...\n");exit(0);}printf("Enter Characters: ");for (idx = 0; c != '\n'; idx++){char buffer;c = getchar();if (c == '\n'){break;}*string = check_array(string, idx);strncat(string, &c, 1);}char output[idx];strcpy(output, string);printf("\nHW 4 output: %s\n", output);return 0;}
