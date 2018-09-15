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


int sqroot(int k){
    int x=1;
    while (x*x<k) x++;
    return x*x==k ? x : 0;
}

int divider (int b,int c, int n, int a){
    while (c<=b/c && c<=(a/b)/c){
        if (b%c==0 && (a/b)/c!=b/c && sqroot(b)!=c && sqroot(a)!=b) n++;
        if ((a/b)%c==0 && (a/b)/c!=b/c && sqroot(b)!=c && sqroot(a)!=b) n++;
        c++;
    }
    // for (int x=b;x<=a/x;x++){
    //     if(a%x==0) {
    //         c++;
    //     // if((d/a)%x==0 && (d/a)/x!=a/x) c++;
    //         if (sqroot(a/x)!=0) c++;
    //         if (sqroot(x)!=0 && sqroot(x)!=sqroot(a) ) c++;
 
    //     }
        
    // }
    return n;
}

int recursion (int a,int b,int c,int n){

    
    for(int x=b;x<=a/x;x++){
        if ((a%x==0)) {
            n++;
            n = divider(x,c,n,a);
             if (sqroot(a/x)!=0) n++;
                        
        }
    }
    
    return n;
}


int main (int argc, char** argv){
    int k , b=2 , c=2 , n=1;
    scanf("%d",&k);
    int q = recursion(k,b,c,n);
    printf("%d\n",  q);
    return 0; 
}
