#ifndef __$__HEAP_SORT_C
#define __$__HEAP_SORT_C 12345
#include<heap.h>
#include<stdlib.h>
#include<string.h>
void heapSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
int ci,ri,lci,rci,swi,e,g,y;
void *a,*b,*c;
c=(void*)malloc(elementSize);
int lb,ub;
lb=0;
ub=collectionSize-1;
y=1;
while(y<=ub)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
a=ptr+(ci*elementSize);
b=ptr+(ri*elementSize);
if(pointerToFunction(a,b)>0)
{
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
ci=ri;
}
else break;
}
y++;
}
y=ub;
while(y>0)
{
b=ptr+(y*elementSize);
memcpy(c,ptr,elementSize);
memcpy(ptr,b,elementSize);
memcpy(b,c,elementSize);
y--;
ri=0;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else if(pointerToFunction((ptr+(lci*elementSize)),(ptr+(rci*elementSize)))>0) swi=lci;
else swi=rci;
a=ptr+(ri*elementSize);
b=ptr+(swi*elementSize);
if(pointerToFunction(b,a)>0)
{
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
ri=swi;
}
else break;
}
}
free(c);
}
#endif