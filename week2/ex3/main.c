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

int recursion (int a,int n){
    for (int k=2;k<=a/2;k++){
        if(a%k==0 ){
            int x=1;
            while (x<=k && x<=INT_MAX/k){
                if(a/k==x*(a/(x*k)) && x>=a/(k*x)) n++;
                x++;
            }
            // for (int x*x=a/k ; x<=k && x*k>0;x++){
            //     if(a/(x*k)<=x && a==x*k*(a/(x*k))) n++;
            // }
        }
        if(a%16==0 && k==a/16 ) {
            k=a/2;
            n=n+8;
        }
    }
    return n;
}

int main (int argc, char** argv){
    int R , n=1;
    scanf("%d",&R);
    printf("%d\n", recursion(R,n));
    return 0; 
}
