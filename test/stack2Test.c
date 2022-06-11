#include<stdio.h>
#include<stack2.h>
int main()
{
Stack stk;
int successFul,error;
initStack(&stk,sizeof(int),&successFul,&error);
if(successFul==FAILED)
{
printf("Error code : %d\n",error);
return 0;
}
int num=10;
push(&stk,&num,&successFul,&error);
num=20;
push(&stk,&num,&successFul,&error);
num=30;
push(&stk,&num,&successFul,&error);
num=40;
push(&stk,&num,&successFul,&error);
num=50;
push(&stk,&num,&successFul,&error);
num=60;
push(&stk,&num,&successFul,&error);
while(!isEmpty(&stk,&successFul,&error))
{
pop(&stk,&num,&successFul,&error);
printf("%d\n",num);
}
return 0;
}