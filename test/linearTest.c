#include<stdio.h>
#include<linear.h>
int myComparator(void *a,void *b)
{
int *e=(int*)a;
int *f=(int*)b;
return *e-*f;
}
int main()
{
int x[5];
x[0]=10;
x[1]=3;
x[2]=1;
x[3]=98;
x[4]=12;
linearSort(x,5,sizeof(int),myComparator);
for(int y=0;y<5;y++) printf("%d\n",x[y]);
return 0;
}