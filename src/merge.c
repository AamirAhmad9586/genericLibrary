#ifndef __$__MERGE_SORT_C
#define __$__MERGE_SORT_C 12345
#include<merge.h>
#include<stack.h>
#include<stdlib.h>
#include<string.h>
void mergeSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
int lb,ub,a,b,mid,lb1,ub1,lb2,ub2,i1,i2,i3;
int tmpSize;
void *tmp;

Stack *stk1=(Stack*)malloc(sizeof(Stack));
Stack *stk2=(Stack*)malloc(sizeof(Stack));
initStack(stk1,sizeof(LBUB));
initStack(stk2,sizeof(LBUB));

lb=0;
ub=collectionSize-1;

LBUB *lbub=(LBUB*)malloc(sizeof(LBUB));
lbub->lb=lb;
lbub->ub=ub;
push(stk1,lbub);
while(!isEmpty(stk1))
{
lbub=(LBUB*)pop(stk1);
push(stk2,lbub);
a=lbub->lb;
b=lbub->ub;
mid=(a+b)/2;
if(a<mid)
{
lbub->lb=a;
lbub->ub=mid;
push(stk1,lbub);
}
if((mid+1)<b)
{
lbub->lb=mid+1;
lbub->ub=b;
push(stk1,lbub);
}
}
while(!isEmpty(stk2))
{
lbub=(LBUB*)pop(stk2);
a=lbub->lb;
b=lbub->ub;
mid=(a+b)/2;
lb1=a;
ub1=mid;
lb2=mid+1;
ub2=b;
i1=lb1;
i2=lb2;
i3=0;
tmpSize=ub1-lb1+1+ub2-lb2+1;
tmp=(void*)malloc(elementSize*tmpSize);
while(i1<=ub1 && i2<=ub2)
{
if(pointerToFunction((ptr+(i1*elementSize)),(ptr+(i2*elementSize)))<0)
{
memcpy((tmp+(i3*elementSize)),(ptr+(i1*elementSize)),elementSize);
i1++;
}
else
{
memcpy((tmp+(i3*elementSize)),(ptr+(i2*elementSize)),elementSize);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy((tmp+(i3*elementSize)),(ptr+(i1*elementSize)),elementSize);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy((tmp+(i3*elementSize)),(ptr+(i2*elementSize)),elementSize);
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
memcpy((ptr+(i1*elementSize)),(tmp+(i3*elementSize)),elementSize);
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
memcpy((ptr+(i2*elementSize)),(tmp+(i3*elementSize)),elementSize);
i2++;
i3++;
}
free(tmp);
}
free(lbub);
free(stk1);
free(stk2);
}
#endif