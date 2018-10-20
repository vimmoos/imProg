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



void appendIValue(Hist *h ,int value){
    int exist = -1;
    if(h->cursor >= h->size) reAllocIntArray(h);
    for(int i=0;i<h->cursor;i++){
        if(h->digits[i] == value ) exist = i ;
    }
    if(exist != -1 ) h->frequency[exist] += 1; 
    else{
        h->digits[h->cursor] = value;
        h->frequency[h->cursor] = 1 ;
        h->cursor += 1 ;
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
void merge(int arr[],int freq[], int l, int m, int r){ 
    int i, j, index; 
    int lenA = m - l + 1; 
    int lenB =  r - m; 
    int L[lenA], R[lenB],L1[lenA],R1[lenB];
    for (i = 0; i < lenA; i++){
        L[i] = arr[l + i];
        L1[i] = freq[l + i]; 
    }
    for (j = 0; j < lenB; j++){
        R[j] = arr[m + 1+ j];
        R1[j] = freq[m + 1+ j]; 
    } 
    i = j = 0; 
    index = l; 
    while (i < lenA && j < lenB) { 
        if (L[i] <= R[j]){ 
            arr[index] = L[i];
            freq[index] = L1[i]; 
            i++; 
        }else{ 
            arr[index] = R[j]; 
            freq[index] = R1[j]; 
            j++; 
        } 
        index++; 
    } 
    while (i < lenA){ 
        arr[index] = L[i]; 
        freq[index] = L1[i]; 
        i++; 
        index++; 
    } 
    while (j < lenB){ 
        arr[index] = R[j]; 
        freq[index] = R1[j]; 
        j++; 
        index++; 
    } 
} 

void mergeSort(int arr[],int freq[], int l, int r){ 
    if (l < r){ 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr,freq, l, m); 
        mergeSort(arr,freq, m+1, r); 
  
        merge(arr,freq, l, m, r); 
    } 
} 


int main (int argc, char** argv){
    Hist h = collectInput();
    mergeSort(h.digits,h.frequency,0,h.cursor-1);
    for (int i = 0 ; i < h.cursor;i++){
        printf("%d: %d\n",h.digits[i],h.frequency[i]);
    }
    return 0; 
}