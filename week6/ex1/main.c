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

typedef struct MajorityV{
    int *digits;
    int *frequency;
    int cursor;
    int size;
    int lenI;
}MajorityV;

int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}


void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}



int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

void reAllocIntArray(MajorityV *mv){
    mv->size *= 2;
    mv->digits = reAllocIntPointer(mv->digits,mv->size);
    mv->frequency = reAllocIntPointer(mv->frequency,mv->size);
    return;
}

void appendIValue(MajorityV *mv ,int value){
    int exist = -1;
    if(mv->cursor >= mv->size) reAllocIntArray(mv);
    for(int i=0;i<mv->cursor;i++){
        if(mv->digits[i] == value ) exist = i ;
       
    }
    if(exist != -1 ){
        mv->frequency[exist] += 1;
        
    }else{
        
        mv->digits[mv->cursor] = value;
        mv->frequency[mv->cursor] = 1 ;
        mv->cursor += 1 ;
    }
    return;
}


MajorityV makeMaj(){
    MajorityV mV;
    mV.cursor = 0;
    mV.lenI = 0;
    mV.size = 1;
    mV.digits = intAlloc(mV.size);
    mV.frequency = intAlloc(mV.size);
    return mV;
}


void freeMaj(MajorityV mv){
    free(mv.digits);
    free(mv.frequency);
    return;
}

MajorityV collectInput(){
    int n;
    MajorityV mv = makeMaj();
    scanf("%d",&n);
    do{
        mv.lenI += 1; 
        appendIValue(&mv,n);
        scanf("%d",&n);
    }while( n != 0);
    return mv;
}

void genMajority(MajorityV *mv,int maxV, int minV){
    if(minV == 2 )printf("majority: ");
    else printf("runner-up: ");
    for(int i=0;i<mv->cursor;i++){
        if(mv->frequency[i] * minV > mv->lenI && mv->frequency[i] * maxV < mv->lenI) {
            printf("%d\n",mv->digits[i]);
            if(minV == 2 ) genMajority(mv,2,4);
            return;
        }
    }
    printf("NONE\n");
    return;
}

void structManager(){
    MajorityV mv = collectInput();
    genMajority(&mv,1,2);
    freeMaj(mv);
    return;
}

int main (int argc, char** argv){
    structManager();
    return 0; 
}
