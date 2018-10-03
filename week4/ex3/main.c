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

void *safeCalloc (int sz){
    void *p= calloc(sz,sizeof(int));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

int *intCalloc (int n){
    return safeCalloc(sizeof(int)*n);
}

int recursion(int n,int i,int *p){
    if(i<n) return i;
    if(p[i]==0){
        for(int j=1;j<=n;j++){
            if(j%2 == 0) p[i]-= j*recursion(n,i-j,p);
            else p[i]+= j*recursion(n,i-j,p);
        }
    }
    return p[i];
}

int main (int argc, char** argv){
    int n,i;
    scanf("%d %d",&n,&i);
    int *p= intCalloc(i);
    printf("%d\n",recursion(n,i,p));
    return 0; 
}
