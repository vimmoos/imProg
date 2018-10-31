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
// define a struct for this problem which will have an int pointer of frequency,
// an int pointer of digits (link to the *frequency in order to have a sparse histogram (with only meaning values))
// an int cursor (this cursor will be the cursor of the *frequency and the *digits)
// an int size and an int lenI (the lenght of the input)
typedef struct MajorityV{
    int *digits;
    int *frequency;
    int cursor;
    int size;
    int lenI;
}MajorityV;
// dynamic reallocation
int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}

// classic safeMalloc 
void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}
//safeMalloc and int *
int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}
// realloc the two int * 
void reAllocIntArray(MajorityV *mv){
    mv->size *= 2;
    mv->digits = reAllocIntPointer(mv->digits,mv->size);
    mv->frequency = reAllocIntPointer(mv->frequency,mv->size);
    return;
}
// appending value logic 
void appendIValue(MajorityV *mv ,int value){
    // set a variable at -1
    int exist = -1;
    // check if reallocing is needed 
    if(mv->cursor >= mv->size) reAllocIntArray(mv);
    // check if we already append this value 
    for(int i=0;i<mv->cursor;i++){
        if(mv->digits[i] == value ) exist = i ;
       
    }
    // if we already append it just increase the frequency
    if(exist != -1 )mv->frequency[exist] += 1;
    else{
        // else append it and initialize the frequency 
        mv->digits[mv->cursor] = value;
        mv->frequency[mv->cursor] = 1 ;
        mv->cursor += 1 ;
    }
    return;
}

// initialize a Maj struct 
MajorityV makeMaj(){
    MajorityV mV;
    mV.cursor = 0;
    mV.lenI = 0;
    mV.size = 1;
    mV.digits = intAlloc(mV.size);
    mV.frequency = intAlloc(mV.size);
    return mV;
}

// free all the int * 
void freeMaj(MajorityV mv){
    free(mv.digits);
    free(mv.frequency);
    return;
}
//collecting input logic 
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
// function to calculate a majority and a runner up but with small fix can calculate recorsively  all type 
// of percentuale you want for now calculate only if there is someone who have more than 50% and if there is someone who 
// have more the 25% but less than 50% 
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
// manage all the operation for this problem 
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
