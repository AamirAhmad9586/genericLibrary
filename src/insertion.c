#ifndef __$__INSERTION_SORT_C
#define __$__INSERTION_SORT_C 12345
#include<stdlib.h>
#include<string.h>
#include<insertion.h>
void insertionSort(void *ptr,int collectionSize,int elementSize,int (*pointerToFunction)(void*,void*))
{
int e,j;
void *num,*a,*b;
num=(void*)malloc(elementSize);
e=1;
while(e<=(collectionSize-1))
{
a=ptr+(e*elementSize);
memcpy(num,a,elementSize);
j=e-1;
while(j>=0 && pointerToFunction((ptr+(j*elementSize)),num)>0)
{
memcpy((ptr+((j+1)*elementSize)),(ptr+(j*elementSize)),elementSize);
j--;
}
memcpy((ptr+((j+1)*elementSize)),num,elementSize);
e++;
}
free(num);
}
#endif