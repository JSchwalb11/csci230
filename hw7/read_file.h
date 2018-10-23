#ifndef READ_FILE_H
#define READ_FILE_H

/*
Joseph Schwalb
CSCI 230
MWF 0900-0950
*/

char* parse_tok(char* tok);
void read_file(FILE *file, struct words *arg_arr);
struct node* read_poem(FILE *file);
struct codex* read_codex(FILE *file);
#endif
