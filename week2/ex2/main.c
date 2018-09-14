/* JSON 
{
    'author':'massimilianoFalzari'
    'studentNumber':'S3459101'
    'date':'September2018'
    'gitRepo':'imperativeProgramming' 
    'language':'C'
} 
*/ 
#include <stdio.h>
#include <stdlib.h>


// this integer function calculate the GCD
int gcd (int a,int b){
    int r;
    while (a != 0) {
        r = b%a;
        b = a;
        a = r;
    }
    return b;
}


// this integer function calculate the LCM
int lcm (int a, int b) {
    return  (a*b)/(gcd(a,b));
}


// this integer function just do the recursion
int recursion (int a,int b) {
    if(b>1 && a*b>0) {
        int result = lcm (a,b);
        return recursion(result,b-1);
    }else{
        return a;
    }     
}
// the main function just scan and print the value
int main (int argc, char** argv){
    int k;
    scanf("%d",&k);
    printf("%d\n", k==1 ? 1 : recursion (k,k-1));
    return 0; 
}
