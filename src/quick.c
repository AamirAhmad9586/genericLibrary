#ifndef __$__QUICK_SORT_C
#define __$__QUICK_SORT_C 12345
#include<quick.h>
#include<stack.h>
#include<stdlib.h>
#include<string.h>
void quickSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
int lb,ub,pp;
Stack *stk=(Stack*)malloc(sizeof(Stack));
initStack(stk,sizeof(LBUB));
LBUB *lbub=(LBUB*)malloc(sizeof(LBUB));
lbub->lb=0;
lbub->ub=collectionSize-1;
push(stk,lbub);
while(!isEmpty(stk))
{
lbub=(LBUB*)pop(stk);
lb=lbub->lb;
ub=lbub->ub;
pp=findPartitionPoint(ptr,lb,ub,elementSize,pointerToFunction);
if(lb<(pp-1))
{
lbub->lb=lb;
lbub->ub=pp-1;
push(stk,lbub);
}
if((pp+1)<ub)
{
lbub->lb=pp+1;
lbub->ub=ub;
push(stk,lbub);
}
}
free(lbub);
free(stk);
}
int findPartitionPoint(void *ptr,int lb,int ub,int elementSize,int (*pointerToFunction)(void*,void*))
{
int e,f;
void *a,*b,*c;
c=(void*)malloc(elementSize);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && pointerToFunction((ptr+(e*elementSize)),(ptr+(lb*elementSize)))<=0) e++;
while(pointerToFunction((ptr+(f*elementSize)),(ptr+(lb*elementSize)))>0) f--;
if(e<f)
{
a=ptr+(e*elementSize);
b=ptr+(f*elementSize);
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
}
else
{
a=ptr+(lb*elementSize);
b=ptr+(f*elementSize);
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
}
}
free(c);
return f;
}
#endif