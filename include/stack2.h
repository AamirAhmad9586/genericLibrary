#ifndef __$__STACK2_H
#define __$__STACK2_H 12345
#define SUCCESS 1
#define FAILED 0
#define NO_ERROR 0
#define NULL_VALUE 1
#define UNBL_MEM_ALLOC 2
#define EMPTY_STACK 3
typedef struct __stack_node_
{
void *data;
struct __stack_node_ *next;
}StackNode;
typedef struct __stack_
{
StackNode *top;
int size;
int elementSize;
}Stack;
void initStack(Stack*,int,int*,int*);
int isEmpty(Stack*,int*,int*);
void push(Stack*,void*,int*,int*);
void pop(Stack*,void*,int*,int*);
#endif