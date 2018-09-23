#include "stdio.h"
#include <omp.h>


int intSumDivisorParallel (int init,int guard,int incr,int number){
    int thread_id,glob_sum, priv_sum;
    glob_sum = 0;
    // parallelize this chunk of code
    #pragma omp parallel private(priv_sum, thread_id)
    {
        priv_sum = 0;
        thread_id = omp_get_thread_num();

        // parallelize this for loop
        #pragma omp for
        for(int i=init;i<=guard;i+=incr){
           if(number%i==0)  priv_sum+=i ;
        }
       
        // make this a "critical" code section
        #pragma omp critical
        {
            // printf("Thread %d is adding its iterations (%d) to sum (%d), ",
            //        thread_id, priv_sum, glob_sum);
            glob_sum += priv_sum;
            // printf(" total nloops is now %d.\n", glob_sum);
        }
    }
    return glob_sum;
}

int main(int argc, char *argv[]){
    int x;
    scanf("%d",&x);
    printf("Total # loop iterations is %d\n",
           intSumDivisorParallel(1,x/2,1,x));
    return 0;
}