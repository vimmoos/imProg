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
// switch on c[i], call the right function and recall itself 
// until the char =
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
        default:
            break;
    }
    return x;
}

int main (int argc, char** argv){
    int x,i=0;
    scanf("%d ",&x);
    // safeMalloc a char pointer with size 10
    char *c=charAlloc(10);
    // then insert all the sequence of functions until the char =
    do{
        c[i] = getchar();
        i++;
    } while( c[i-1] != '=');        
    printf("%d\n",recursion(x,c,0));
    // free the pointer c 
    free(c);
    return 0; 
}
