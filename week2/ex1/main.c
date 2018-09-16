/* JSON 
{
    "author":"massimilianoFalzari"
    "studentNumber":"S3459101"
    "date":"September2018"
    "gitRepo":"imperativeProgramming"
    "language":"C" 
} 
*/ 
#include <stdio.h>
#include <stdlib.h>
// this int func calculate the integer square root  of a number 
int sqroot(int k){
    int x=1;
    while (x*x<k) x++;
    return x*x==k ? x : 0;
}
// this int func verify whether k is a square free number or not 
int sqfree(int k){
    int x=1;
    while (x<k/2 && k!= 0){
        if ((x*x)%k==0 && x!=1) return x;
        x++;
    }
    return  k==0 || (x*x)%k==0 ? 0 : 1 ;
}

//the main just print the solution 

int main (int argc, char** argv){
    int k;
    scanf("%d",&k);
    printf("%d is%s a squareful number.\n",k,sqfree(sqroot(k))==1 ? "":" not"); 
    return 0; 
}
