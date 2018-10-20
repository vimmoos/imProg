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
// this program use WHAMsort 
typedef struct Hist{
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
    return;
}



void appendIValue(Hist *h ,int value){
    if(h->cursor >= h->size) reAllocIntArray(h);
    h->digits[h->cursor] = value;
    h->cursor +=1 ;
    return;
}



Hist makeH(){
    Hist h;
    h.cursor = 0 ;
    h.size = 1;
    h.digits = intAlloc(h.size);
    return h;
}
void freeH(Hist h ){
    free(h.digits);
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


void merge(int b,int m,int e, int *arr,int *tmp){
    int i=0,j=0,index=b;
    int lenA = m-b  ;
    int lenB = e-m;
    for(int k = 0 ; k < e-b; k ++) tmp[k]= arr[k+b];
    while(i < lenA && j < lenB){
        if(tmp[i] <= tmp[lenA+j] ){
            arr[index] = tmp[i];
            i++;
        }else{
            arr[index] = tmp[lenA+j];
            j++;
        }
        index++;
    }
    while (i < lenA){ 
        arr[index] = tmp[i]; 
        i++; 
        index++; 
    } 
    while (j < lenB){ 
        arr[index] = tmp[lenA+j]; 
        j++; 
        index++; 
    }
    return; 
}


void recWhamsort(int p, int e, int *a, int *tmp){
    int i = p+1;
    while (i < e && a[i-1] <= a[i])  i++;
    while (i < e) { 
        int s = e < 2*i - p  ?   e   :   2*i - p;
        recWhamsort(i, s, a, tmp);
        merge(p, i, s, a, tmp);
        i = s;
    }
    return;
}

void whamsort(int len, int *a){
    int *tmp = malloc(len*sizeof(int));
    recWhamsort(0, len, a, tmp);
    free(tmp);
}

void printH(Hist h){
    int cnt = 1;
    for (int i = 1 ; i <= h.cursor;i++){
        if(h.digits[i]==h.digits[i-1]) cnt++; 
        else {
            printf("%d: %d\n",h.digits[i-1],cnt);
            cnt = 1;    
        }
    }
}


int main (int argc, char** argv){
    Hist h = collectInput();
    whamsort(h.cursor,h.digits);
    printH(h) ;
    return 0; 
}

