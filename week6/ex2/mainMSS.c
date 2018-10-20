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

typedef struct DioP{
    int value;
    int frequency;
}DioP;

typedef struct Hist{
    DioP *d;
    int size;
    int cursor;
}Hist;

DioP *reAllocStructPointer(DioP *p,int size){
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



DioP *structAlloc (int n){
    return safeMalloc(sizeof(DioP)*n);
}


void reAllocStructArray(Hist *h){
    h->size *= 2;
    h->d = reAllocStructPointer(h->d,h->size);
    return;
}



Hist makeH(){
    Hist h;
    h.cursor = 0 ;
    h.size = 1;
    h.d = structAlloc(h.size);
    return h;
}
void freeH(Hist h ){
    free(h.d);
    return;
}
void appendIValue(Hist *h ,int value){
    int exist = -1;
    if(h->cursor >= h->size) reAllocStructArray(h);
    for(int i=0;i<h->cursor;i++){
        if(h->d[i].value == value ) exist = i ;
    }
    if(exist != -1 ) h->d[exist].frequency += 1; 
    else{
        h->d[h->cursor].value = value;
        h->d[h->cursor].frequency = 1 ;
        h->cursor += 1 ;
    }
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
void merge(DioP arr[], int l, int m, int r){ 
    int i, j, index; 
    int lenA = m - l + 1; 
    int lenB =  r - m; 
    DioP L[lenA], R[lenB];
    for (i = 0; i < lenA; i++){
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < lenB; j++){
        R[j] = arr[m + 1+ j];
    } 
    i = j = 0; 
    index = l; 
    while (i < lenA && j < lenB) { 
        if (L[i].value <= R[j].value){ 
            arr[index] = L[i]; 
            i++; 
        }else{ 
            arr[index] = R[j];
            j++; 
        } 
        index++; 
    } 
    while (i < lenA){ 
        arr[index] = L[i]; 
        i++; 
        index++; 
    } 
    while (j < lenB){ 
        arr[index] = R[j]; 
        j++; 
        index++; 
    } 
} 

void mergeSort(DioP arr[], int l, int r){ 
    if (l < r){ 
        int m = l+(r-l)/2;  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 



int main (int argc, char** argv){
    Hist h = collectInput();
    mergeSort(h.d,0,h.cursor-1);
    for (int i = 0 ; i < h.cursor;i++){
        printf("%d: %d\n",h.d[i].value,h.d[i].frequency);
    }
    return 0; 
}