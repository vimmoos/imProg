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

int divisorOfN (int n){
    int sum=0;
    for (int i=n/2;i>=1;i--){
        sum = n%i==0 ? sum+i : sum;  
    }
    return sum;
} 

int main (int argc, char** argv){
    int x;
    scanf("%d",&x);
    int sum = divisorOfN(x);
    printf("%s\n",Revertnumber(x)==sum ? "YES" : "NO");
    return 0; 
}
