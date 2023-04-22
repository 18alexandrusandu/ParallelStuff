

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 1999309L





#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<math.h>
#include<time.h>/* for simplicity the no.of processesis defined here,But a better idea is to read it from the command line */
#define PROCESSES 4

int isPrime(int n){

if (n <= 1)
return 0;
if (n <= 3)
return 1;
// This is checked so that we can skip
// middle five numbers in below loop
if (n % 2 == 0 || n % 3 == 0)
return 0;

for (int i = 5; i * i <= n; i++)
if (n % i == 0)
return 0;

return 1;
}
// Function to check if the number is circular
// prime or not.
int checkCircular(int N)
{
// Count digits.
int count = 0, temp = N;
while (temp) {
count++;
temp /= 10;
}

int num = N;

while (isPrime(num)) {
// Following three lines generate the next
// circular permutation of a number. We move
// last digit to first position.
int rem = num % 10;
int div = num / 10;
num = (pow(10, count - 1)) * rem + div;
// If all the permutations are checked and
// we obtain original number exit from loop.
if (num == N)
return 1;
}
return 0;
}


void do_work(int id,int start,int end,int nr_processes)
{

//printf("Hello there, from process %d!  search from %d to %d with step:%d\n", id,start,end,nr_threads);
for(int i=start;i<=end;i+=2*nr_processes)

if(checkCircular(i))
{
printf("thread %d : %d ,",id,i);

}
}

   struct timespec start, finish, delta;


double sub_timespec(const struct timespec *time1, const struct timespec *time0) {
  return (time1->tv_sec - time0->tv_sec)
      + (time1->tv_nsec - time0->tv_nsec) / 1000000000.0;
}


int main(){
int i, pid;

/* Take initial time here *//* Use clock_gettime(). Do NOT use clock() */


int B=200000;;
int A=11;
FILE* f=fopen("times.csv","w+");


for(int p=1;p<=16;p++)

{

 clock_gettime(CLOCK_REALTIME, &start);


for(i=0;i<p;i++){
pid = fork();
if(pid < 0)/* some error occurred –fork failed */
{
printf("Error");
exit(-1)
;}
if(pid == 0) /* child process code */
{
do_work(i,A+2*i,B,p);
exit(0)
;}/* do not place anywait()call here*/}/* wait for all processes to finish their execution */

for(i=0; i<p;i++)
wait(NULL);


clock_gettime(CLOCK_REALTIME, &finish);
double diff=sub_timespec(&finish, &start)*1000;

  printf(" \nfor p=%d time execution:%lf ms\n",p,diff);
  if(f)
  fprintf(f,"%d , %lf\n",p,diff);

}


fclose(f);





/* Take final time here *//* Use clock_gettime(). Do NOT use clock() *//* Compute the execution time*/

}/* this function is executed by each process */

