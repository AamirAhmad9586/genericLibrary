#include<stdio.h>
#include<heap.h>
int myComparator(void *left,void *right)
{
int *a=(int*)left;
int *b=(int*)right;
return *a-*b;
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a Number : ");
scanf("%d",&x[y]);
}
heapSort(x,10,sizeof(int),myComparator);
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}