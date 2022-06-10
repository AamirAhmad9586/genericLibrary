#include<stdio.h>
#include<stack.h>
#include<stdlib.h>
int main()
{
Stack *stk1,*stk2,*stk3;
stk1=(Stack*)malloc(sizeof(Stack));
stk2=(Stack*)malloc(sizeof(Stack));
stk3=(Stack*)malloc(sizeof(Stack));
initStack(stk1,sizeof(int));
initStack(stk2,sizeof(char));
initStack(stk3,sizeof(int));

int *x=(int*)malloc(sizeof(int));
char *y=(char*)malloc(sizeof(char));

*x=10;
push(stk1,x);
*x=20;
push(stk1,x);
*x=30;
push(stk1,x);
x=pop(stk1);
printf("%d\n",*x);

*y='A';
push(stk2,y);
*y='B';
push(stk2,y);
*y='C';
push(stk2,y);
*y='D';
push(stk2,y);
y=pop(stk2);
printf("%c\n",*y);

*x=100;
push(stk3,x);
*x=200;
push(stk3,x);
*x=300;
push(stk3,x);
*x=400;
push(stk3,x);
x=pop(stk3);
printf("%d\n",*x);

*x=50;
push(stk1,x);
*y='E';
push(stk2,y);
*x=1000;
push(stk3,x);

printf("Printing data of stk1\n");
while(!isEmpty(stk1))
{
x=pop(stk1);
printf("%d\n",*x);
}
pop(stk1);
printf("----------------\n");

printf("Printing data of stk2\n");
while(!isEmpty(stk2))
{
y=pop(stk2);
printf("%c\n",*y);
}
pop(stk2);
printf("----------------\n");

printf("Printing data of stk3\n");
while(!isEmpty(stk3))
{
x=pop(stk3);
printf("%d\n",*x);
}
pop(stk3);
printf("----------------\n");

free(x);
free(y);
free(stk1);
free(stk2);
free(stk3);
return 0;
}