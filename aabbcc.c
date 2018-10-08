#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *file = fopen("words.txt", "w");
   if (file == NULL){
     printf("error opening words.txt");
     exit(0);
   }

   // printf() displays the string inside quotation
   printf("Worked!\n");
   return 0;
}
