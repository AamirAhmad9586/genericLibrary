#ifndef __$__STACK_H
#define __$__STACK_H 12345
typedef struct __stack_node_
{
void *data;
struct __stack_node_ *next;
}StackNode;
typedef struct __stack_
{
StackNode *top;
int elementSize;
int size;
}Stack;
int isEmpty(Stack*);
void initStack(Stack*,int);
void push(Stack*,void*);
void* pop(Stack*);
#endif