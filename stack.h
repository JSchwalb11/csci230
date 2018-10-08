#ifndef stack
#define stack

typedef struct Stack
{
    int top;
    unsigned capacity;
    char* array;
} stack;

struct Stack* createStack(unsigned capacity);

int isFull(struct Stack* stack);

int isEmpty(struct Stack* stack);

void push(struct Stack* stack, int item);

char pop(struct Stack* stack);

#endif
