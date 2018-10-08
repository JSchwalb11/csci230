#ifndef ARRAY_H
#define ARRAY_H

/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/
#define MAX_SIZE 10

typedef struct words{
  int count;
  char word[51];
};
int compare (const void * a, const void * b);
struct words* check_array(struct words* arr, int idx);
struct words* tag_cloud(struct words* arr, const int size);

#endif
