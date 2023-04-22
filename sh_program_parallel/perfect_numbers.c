#include<stdlib.h>
#include<math.h>
#include<stdio.h>
int perfect_number(int X)
{

int sum=1;
for(int i=2;i<X;i++)
{
if(X%i==0)
sum+=i;
}

if(sum==X)
return 1;
return 0;
}






void perfect_numbers(int A,int B)
{

if(A>B)
{
B=A+B;
A=B-A;
B=B-A;

}
printf("A,B,%d,%d\n",A,B);
for(int i=A;i<=B;i++)
if(perfect_number(i))
{
printf("%d\n",i);
}

}



int main(int argc,char*argv[])
{


int A=atoi(argv[1]);
int B=atoi(argv[2]);
perfect_numbers(A,B);



}
