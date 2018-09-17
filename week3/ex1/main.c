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
#include "../../lib/arrLib.h"

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

int recursion(int x , char *c,int i){
    switch (c[i]){
        case 'f':
            x=fFunction(x);
            i++;
            x=recursion(x,c,i);
            break;
        case 'g':
            x=gFunction(x);
            i++;
            x=recursion(x,c,i);
            break;
        case 'h':
            x=hFunction(x);
            i++;
            x=recursion(x,c,i);
            break;
        case '=':
            break;
        default:
        printf("default");
            break;
    }
    return x;
}

int main (int argc, char** argv){
    int x,i=0;
    scanf("%d ",&x);
    char *c=charAlloc(10);
    do{
        c[i] = getchar();
        i++;
    } while( c[i-1] != '=');        
    printf("%d",recursion(x,c,0));
    free(c);
    return 0; 
}
