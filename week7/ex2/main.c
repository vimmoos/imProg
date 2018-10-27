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

typedef struct FloatingP{
    int firstM;
    int cursor;
    int *out;
    int size;
    int endM;
    int re;
}FP;

void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

void reAllocIntPointer(FP *fp){
    fp->size *= 2;
    size_t new_size = fp->size;
    fp->out = realloc(fp->out, new_size * sizeof(int));
    if (fp->out == NULL ) exit(EXIT_FAILURE);
    return;
}

int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

FP makeFP(int n){
    FP fp;
    fp.cursor = 0;
    fp.firstM = -1;
    fp.endM   = 0;
    fp.size   = 1;
    fp.re     = 10;
    fp.out    = intAlloc(fp.size);  
    return fp;
}


void rDivision(FP *fp,int n){
    if(fp->cursor >= fp->size) reAllocIntPointer(fp);        
    fp->out[fp->cursor] = fp->re / n;
    fp->cursor          += 1;
    fp->re              = (fp->re % n) * 10;
    isNotIn(fp);
    return;
} 



void recDecFra(FP *fp, int n){
    if( fp->cursor == -1 || fp->re==0) return ;
    rDivision(fp,n);
    recDecFra(fp,n); 
    return;
}

void freeFP(FP fp){
    free(fp.out);
    return;
}

void printSol(FP fp){
    printf("0,");
    if(fp.re == 0 ){
        for(int i = 0 ; i < fp.cursor ; i++) printf("%d",fp.out[i]);
        printf("[%d]",fp.re);
    }else{
        for(int i = 0 ; i < fp.firstM ; i++) printf("%d",fp.out[i]);
        printf("[");
        for(int i = fp.firstM ; i < fp.endM ; i++) printf("%d",fp.out[i]);
        printf("]");
    }
    return;
}


void decimalFraction(int n){
    FP fp = makeFP(n);
    recDecFra(&fp,n);
    printSol(fp);
    freeFP(fp);
    return;
}


int main (int argc, char** argv){
    int n;
    scanf("%d",&n);
    decimalFraction(n);
    return 0; 
}
