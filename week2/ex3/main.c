/* JSON 
{
    'author':'massimilianoFalzari'
    'studentNumber':'S3459101'
    'date':'September2018'
    'gitRepo':'imperativeProgramming' 
} 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// this function calculate the numbers of triplets
// but it's too slow with this logic 
int ntriplets (int a,int n,int even){
    for (int k=1;k<=a/2;k=k+even){
        if(a%k==0){
            int x=1;
            while (x<=k && x<=INT_MAX/k){
                if(a/k==x*(a/(x*k)) && x>=a/(k*x)){
                    n++;
                } 
                x=x+even;
            }
        }
        if(a%32==0 && k==a/32 ) {
            k=a/2;
            n=n+16;
        }
    }
    return n;
}

int main (int argc, char** argv){
    int a, n=1;
    scanf("%d",&a);
    //see whether the input number is even or not 
    //if it's an odd number the ntriplets function check just odd numbers 
    //the problem is when the input is a large even number because the function check too many numbers.
    int even= a%2==0? 1:2;
    printf("%d\n", ntriplets(a,n,even));
    return 0; 
}
