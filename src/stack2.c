#ifndef __$__STACK2_C
#define __$__STACK2_C 12345
#include<stack2.h>
#include<stdlib.h>
#include<string.h>
void initStack(Stack *stack,int elementSize,int *successFul,int *error)
{
if(successFul) *successFul=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
if(successFul) *successFul=SUCCESS;
}
int isEmpty(Stack *stack,int *successFul,int *error)
{
if(successFul) *successFul=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL)
{
if(error) *error=NULL_VALUE;
return 1;
}
if(successFul) *successFul=SUCCESS;
return stack->size==0;
}
void push(Stack *stack,void *data,int *successFul,int *error)
{
if(successFul) *successFul=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
if(data==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
StackNode *node=(StackNode*)malloc(sizeof(StackNode));
if(node==NULL)
{
if(error) *error=UNBL_MEM_ALLOC;
return;
}
node->data=(void*)malloc(stack->elementSize);
if(node->data==NULL)
{
if(error) *error=UNBL_MEM_ALLOC;
free(node);
return;
}
memcpy(node->data,data,stack->elementSize);
node->next=stack->top;
stack->top=node;
stack->size++;
if(successFul) *successFul=SUCCESS;
}
void pop(Stack *stack,void *data,int *successFul,int *error)
{
if(successFul) *successFul=FAILED;
if(error) *error=NO_ERROR;
if(stack==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
if(data==NULL)
{
if(error) *error=NULL_VALUE;
return;
}
if(stack->top==NULL)
{
if(error) *error=EMPTY_STACK;
return;
}
StackNode *node=stack->top;
stack->top=stack->top->next;
memcpy(data,node->data,stack->elementSize);
free(node->data);
free(node);
stack->size--;
if(successFul) *successFul=SUCCESS;
}
#endif