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

int recursion (int a,int b,int c,int n){
    b++;
    if((b<a/(b))){
        if ((a%b==0)) {
            n++;
            n = divider(a/b,&c,n)
        }
        return a%b==0 ? recursion(a/b,b,c,n) : recursion(a,b,c,n);
    }
    return n;
}


int divider (int a,int *b, int c ){
    b++;
    if((*b<a/(*b))){
        if ((a%*b==0)) c++; 
        return a%*b==0 ? divider(a/(*b),&b,c) : divider(a,&b,c);
    }
    return c; 
    
}


int main (int argc, char** argv){
    int k , b=1 , c=1 , n=1;
    scanf("%d",&k);
    printf("%d\n", k==1 ? 1 : recursion(k,b,c,n));
    return 0; 
}
