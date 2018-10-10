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

typedef struct RedTO{
    int operations;
    int value;
}RedTO;

RedTO makeRed(int n){
    RedTO r;
    r.operations = 0;
    r.value = n;
    return r;
}


void bestMove(RedTO *r){
    if((r->value-1)/2 == 1){
        r->value -= 1;
        return;
    } 
    if((r->value+1)/2 == 1) {
        r->value += 1;
        return;
    }
    if(((r->value-1)/2)%2==0) r->value -= 1;
    else r->value += 1; 
    return;
}

void reduction(RedTO *r){
    while(r->value != 1){
        if(r->value % 2 == 0) r->value /= 2; 
        else bestMove(r);
        r->operations += 1;
    }
    return;
}

int main (int argc, char** argv){
    int n;
    scanf("%d",&n);
    RedTO r = makeRed(n);
    reduction(&r);
    printf("%d\n",r.operations);
    return 0; 
}
