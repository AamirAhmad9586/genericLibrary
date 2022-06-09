#ifndef __$__SELECTION_SORT_C
#define __$__SELECTION_SORT_C 12345
#include<stdlib.h>
#include<string.h>
#include<selection.h>
void selectionSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
void *a,*b,*c;
c=(void*)malloc(collectionSize);
int e,f,m;
e=0;
while(e<=(collectionSize-2))
{
m=e;
f=e+1;
while(f<=(collectionSize-1))
{
if(pointerToFunction(b,a)<0)
{
m=f;
}
f++;
}
a=ptr+(m*elementSize);
b=ptr+(e*elementSize);
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
e++;
}
free(c);
}
#endif