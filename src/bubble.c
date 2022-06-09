#ifndef __$__BUBBLE_SORT_C
#define __$__BUBBLE_SORT_C 12345
#include<stdlib.h>
#include<string.h>
#include<bubble.h>
void bubbleSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
void *a,*b,*c;
c=(void*)malloc(collectionSize);
int e,f,m;
m=collectionSize-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(e*elementSize);
b=ptr+(f*elementSize);
if(pointerToFunction(b,a)<0)
{
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
}
e++;
f++;
}
m--;
}
free(c);
}
#endif