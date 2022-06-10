#ifndef __$__STACK_C
#define __$__STACK_C 12345
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack.h>
int isEmpty(Stack *stk)
{
return stk->size==0;
}
void initStack(Stack *stk,int elementSize)
{
stk->top=NULL;
stk->size=0;
stk->elementSize=elementSize;
}
void push(Stack *stk,void *data)
{
StackNode *node=(StackNode*)malloc(sizeof(StackNode));
node->data=(void*)malloc(stk->elementSize);
memcpy(node->data,data,stk->elementSize);
node->next=stk->top;
stk->top=node;
stk->size++;
}
void* pop(Stack *stk)
{
if(isEmpty(stk))
{
printf("stack is empty\n");
return NULL;
}
void *data=stk->top->data;
StackNode *node=stk->top;
stk->top=stk->top->next;
stk->size--;
free(node);
return data;
}
#endif