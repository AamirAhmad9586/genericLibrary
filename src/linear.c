#ifndef __$__LINEAR_SORT_C
#define __$__LINEAR_SORT_C 12345
#include<stdlib.h>
#include<string.h>
#include<linear.h>
void linearSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
void *a,*b,*c;
c=(void*)malloc(elementSize);
int e,f;
e=0;
while(e<=(collectionSize-2))
{
f=e+1;
while(f<=(collectionSize-1))
{
a=ptr+(e*elementSize);
b=ptr+(f*elementSize);
if(pointerToFunction(b,a)<0)
{
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
}
f++;
}
e++;
}
free(c);
}
#endif