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
#include <math.h>
#include "../../lib/utils.h"
// this function return the sum of all divisor of n 
int divisorOfN (int n){
    int sum=0;
    for (int i=n/2;i>=1;i--){
        sum = n%i==0 ? sum+i : sum;  
    }
    return sum;
} 
//just scan and print yes if the sum of the divisor is equal to the reverse input number
int main (int argc, char** argv){
    int x;
    scanf("%d",&x);
    printf("%s\n",Revertnumber(x)==divisorOfN(x) ? "YES" : "NO");
    return 0; 
}
