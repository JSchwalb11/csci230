#ifndef READ_FILE_H
#define READ_FILE_H

/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/

char* parse_tok(char* tok, struct words* arr);
void read_file(FILE *file, struct words *arg_arr);

#endif
