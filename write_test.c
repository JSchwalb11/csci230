/*
 *  Author: zentut.com
 *  Description: C Write text file demo
 */

#include <stdio.h>

#define LEN 256
int main ()
{
   FILE * fp;
   int i;
   /* open the file for writing*/
   fp = fopen ("write_test.data","w");

   /* write 10 lines of text into the file stream*/
   for(i = 0; i < 10;i++){
       fprintf (fp, "This is line %d\n",i + 1);
   }

   /* close the file*/
   fclose (fp);
   return 0;
}
