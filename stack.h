#ifndef STACK_H
#define STACK_H
#define DEFAULT 10
#define STRLIM 100
#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
    size_t len;
    size_t capac;
    char **args;
} stack;

int mlen(char *);
void copy(char *, char *);

stack *new(void); //creates new stack
void del(stack *); //frees and deletes stack
void push(stack *, char *); //push to end of stack
char *pop(stack *); //pop from end of stack
void pstack(stack *); //print stack
void insert(stack *, int, char *); //inserts at index;e
char *mremove(stack *, int); //removes at index;
void set(stack *, int, char *);         
char **split(char *, char); //splits by delimiter
#endif
