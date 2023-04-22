#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdio.h>
#include<string.h>

int* prime_numbers_finder_1(int* n,int A,int B)
{

 if(A>B)
   {
      int C=A;
      A=B;
      B=C;
   }
    int* P =(int*)malloc(sizeof(int)*(B-A+1));
   printf("A,B=%d,%d",A,B);

   *n=0;
  for(int X=A;X<=B;X++)
{



   int prime=1;
  for(int j=2;j<=floor(sqrt(X));j++)
   {
     if(X%j==0)
       prime=0;
   }
  if(prime>0)
  {
    P[*n]=X;
    *n=*n+1;


  }


}
return P;
}
int* prime_numbers_finder_2(int* n,int A,int B)
{

 if(A>B)
   {
      int C=A;
      A=B;
      B=C;
   }
    int* P =(int*)malloc(sizeof(int)*(B-A+1));

   *n=0;
   if(A%2==0)
    A=A+1;
  for(int X=A;X<=B;X+=2)
{

   int prime=1;
   if(X==2)
    {P[*n]=X;
    *n=*n+1;
    }
   else
 if(X%2==0)
       prime=0;

  for(int j=3;j<=floor(sqrt(X));j+=2)
   {
     if(X%j==0)
       prime=0;
   }
  if(prime>0)
  {
    P[*n]=X;
    *n=*n+1;


  }
  }


return P;


}



void prime_number_main_loop(int A,int B)
{

clock_t start_time=clock();
int n=0;
int* ps=prime_numbers_finder_2(&n, A,B);
clock_t end_time=clock();


double  c_time_used = ((double) (end_time- start_time))/CLOCKS_PER_SEC;


float time_used=1000*c_time_used;

printf("array of primes between %d,%d:",A,B);
for(int i=0;i<n;i++)
{
printf("%d ",ps[i]);
}
printf("\n time taken  in millis:%lf",time_used );



}
/*Questions:

   what is the type of variables A, B, X, P? A,B,X int , P nt*
   what C functions do we use for computing the execution time? clock()
   what C header must be included for computing floor(sqrt(X))? math.h
*/





double entropy_of_random_sequence(long long n)
{
long long N=n;
double T=8*N;

 char* S=(char*)malloc(N);
//Pas 1generate sequence
for(long long i=0;i<N/4;i++)
{
int n=rand();
S[i]=n%256;
S[i+1]=(n>>8)%256;
S[i+2]=(n>>16)%256;
S[i+3]=(n>>16)/256;

}
//Pas 2 find Z and O
long long int O=0,Z=0;
for(long long  i=0;i<(N/4)*4;i++)
{
//printf("i=%lld\n",i);
char c=S[i];
while(c!=0)
{
if(c%2==0)
Z++;
else
O++;

c=c/2;
}


}
//Pas 3
//log2(x)=log(x)/log(2)
float log2=log(2);
double E= - (O/T)*log(O/T)/log2 - (Z/T)*log(Z/T)/log2;

return E;



}
/*
Questions:
what is the type of variables S, N, O, Z, T, E? S =char* (string of bytes) ,N = long long int, O,Z long long int,T,E-dopuble
what are the standard C functions for using the PRNG and what header must be incuded? rand(), header:stdlib.h
what C functions do we use for computing the execution time? clock()
how do we allocate memory for the sequence? (static / dynamic allocation) static as array S[nr_bytes] ,dynamically :(char*)malloc(nr_bytes)
what is the largest sequence that we can allocate statically? iy depends of the stack size , in linux can be found with the command ulimit -a
for my memory:
what is the largest sequence that we can allocate dynamically? 16711568 bytes with malloc?
how do we compute log2(X), as the “math.h” library only supports log(X) and ln(X) ? log2(x)=log(x)/log(2) log2(x)=ln(x)/ln(2)
*/


double Pi_by_integration(int N)
{
double PI=0;
for(int i=0;i<N;i++)
PI+=  (4.0 / (1 + ((i + 0.5)/N)*(((i + 0.5)/N))));
PI=PI/N;
return PI;
}

double PI_by_Monte_Carlo(int N)
{
float M=0;
for(int i=0;i<N;i++)
{
float x= ((float)rand())/RAND_MAX;
float y=((float)rand())/RAND_MAX;

int rad=sqrt(x*x+y*y);
if(rad<1)
 M++;
}
printf("M=%f",M);
double PI=4.0*M/N;
return PI;
}






int main(int argc, char *argv[] )
{

if(argc>1)
{

  int problem=atoi(argv[1]);
 if(problem==1)
{
  int A=atoi(argv[2]);
  int B=atoi(argv[3]);
  prime_number_main_loop(A,B);
}
else
 if(problem==2)
{
  srand ((unsigned int) time (NULL));
  long long  N=atoll(argv[2]);
  clock_t start_time=clock();
  double entropy=entropy_of_random_sequence(N);
  clock_t end_time=clock();
  double  c_time_used = ((double) (end_time- start_time))/CLOCKS_PER_SEC;
  float time_used=1000*c_time_used;



  printf("entropy of the sequence of %lld bytes is:%lf\n",N,entropy);
  printf("\n time taken  in millis:%lf",time_used );

}
else
if(problem==3)
{
 int  N=atoi(argv[2]);
 clock_t start_time=clock();
  double PI=Pi_by_integration(N);
  clock_t end_time=clock();
  double  c_time_used = ((double) (end_time- start_time))/CLOCKS_PER_SEC;
  float time_used=1000*c_time_used;



  printf("for N=%d PI is %.30lf",N,PI);
  printf("\n time taken  in millis:%lf",time_used );
}
else
if(problem==4)
{
 int  N=atoi(argv[2]);
 clock_t start_time=clock();
  double PI=PI_by_Monte_Carlo(N);
  clock_t end_time=clock();
  double  c_time_used = ((double) (end_time- start_time))/CLOCKS_PER_SEC;
  float time_used=1000*c_time_used;



  printf("for N=%d PI is %.30lf",N,PI);
  printf("\n time taken  in millis:%lf",time_used );
}




}




}
