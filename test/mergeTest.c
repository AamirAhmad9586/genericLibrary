#include<stdio.h>
#include<merge.h>
#include<stdlib.h>
#include<string.h>
int myComparator(void *a,void *b)
{
int *e=(int*)a;
int *f=(int*)b;
return *e-*f;
}
int main()
{
int x[10];
for(int y=0;y<=9;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}
mergeSort(x,10,sizeof(int),myComparator);
for(int y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}