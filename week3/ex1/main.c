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

int fFunction (int x){
    x=x+1;
    return x;
}

int gFunction (int x){
    x=3*x+1;
    return x;
}

int hFunction (int x){
    x=(x*x)-x+42;
    return x;
}

int recursion (int x, char* f){
    while (sizeof(f)!=0){

    }    
}
int main (int argc, char** argv){
    char *f=malloc(5*sizeof(char*));
    scanf("%hhd",f);
    printf("%hhd\n",f[0]);
    return 0; 
}
