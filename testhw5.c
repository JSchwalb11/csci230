#include <stdio.h>

#define NELEM(x) (sizeof(x) / sizeof((x)[0]))

int main(){
  printf("test");
  char *arr = (char*)calloc(10,sizeof(char));
  printf("NELEM(arr)=\n", NELEM(*arr));
  return 0;
}
