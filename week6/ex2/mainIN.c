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

typedef struct Hist{
    int *frequency;
    int *digits;
    int size;
    int cursor;
}Hist;


int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    p = realloc(p, new_size * sizeof *p);
    if ( p == NULL ) {
        printf("error cannot realloc %d",size);
        exit(EXIT_FAILURE);
    }   
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


void reAllocIntArray(Hist *h){
    h->size *= 2;
    h->digits = reAllocIntPointer(h->digits,h->size);
    h->frequency = reAllocIntPointer(h->frequency,h->size);
    return;
}

// void findNShift(int length, int arr[], int value) {
//     int i = 0;
//     while ((i < length) && (arr[i] <= value))  i++;
//     for (int j = length; j > i; j--) {
//         arr[j] = arr[j-1];

//     }
//     return;
// }
int findNShift(Hist *h, int value) {
    int i = 0;
    while ((i < h->cursor) && (h->digits[i] <= value))  i++;
    for (int j = h->size; j > i; j--) {
        h->digits[j] = h->digits[j-1];
        h->frequency[j] = h->frequency[j-1];
    }
    return i;
}

void appendIValue(Hist *h ,int value){
    int exist = -1;
    if(h->cursor >= h->size) reAllocIntArray(h);
    for(int i=0;i<h->cursor;i++){
        if(h->digits[i] == value ) exist = i ;
    }
    if(exist != -1 ) h->frequency[exist] += 1; 
    else{
        if(value > h->digits[h->cursor-1]){
            h->digits[h->cursor] = value;
            h->frequency[h->cursor] = 1 ;
            h->cursor += 1 ;
        }else{
            int idx = findNShift(h,value);
            h->digits[idx] = value;
            h->frequency[idx] = 1 ;
            h->cursor += 1 ;
        }
    }
    return;
}



Hist makeH(){
    Hist h;
    h.cursor = 0 ;
    h.size = 1;
    h.digits = intAlloc(h.size);
    h.frequency = intAlloc(h.size);
    return h;
}
void freeH(Hist h ){
    free(h.digits);
    free(h.frequency);
    return;
}

Hist collectInput(){
    int n;
    Hist h  = makeH();
    scanf("%d",&n);
    do{ 
        appendIValue(&h,n);
        scanf("%d",&n);
    }while( n != 0);
    return h;
}



int main (int argc, char** argv){
    Hist h = collectInput();
    for (int i = 0 ; i < h.cursor;i++){
        printf("%d: %d\n",h.digits[i],h.frequency[i]);
    }
    return 0; 
}