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

 

int Rnumber (int x){
    int Rx=0;
    while (x!= 0){
        Rx = Rx*10;
        Rx = Rx+(x%10);
        x = x/10;
    }
    return Rx;
}

int multipal (int x,int n,int X){
    for (int k=1;k*k<=X/k;k++){
        if ( X%k==0 && X/k==x) n=n+1;
    }
    return n;
}

int recursion (int a,int b){
    int x=a,n=0;
    while(x<=b){
        int X = Rnumber(x);
        n = multipal(x,n,X);
        x++;
    }
    return n;
}

int main (int argc, char** argv){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",recursion(a,b));
    return 0; 
}
