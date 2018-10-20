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


void merge(int b,int m,int e, int *arr,int *tmp){
    int i=0,j=0,index=b;
    int lenA = m-b  ;
    int lenB = e-m;
    printf("len a %d\t len b  %d\n",lenA,lenB);
    for(int k = 0 ; k < e-b; k ++) {
        tmp[k]= arr[k+b];
        printf("array at %d  has value %d\n",k,arr[k+b]);
    }
    while(i < lenA && j < lenB){
        printf("dio quel dio porcon A %d B %d  and m === %d\n",tmp[i],tmp[lenA+j],lenA);
        if(tmp[i] <= tmp[lenA+j] ){
            arr[index] = tmp[i];
            i++;
        }else{
            arr[index] = tmp[lenA+j];
            j++;
        }
        index++;
    }
    printf("dio A %d B %d \n",tmp[i],tmp[m+j]);
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
    for(int k = 0 ; k < e-b;k++) printf("dio maiale %d\t",arr[k+b]);
        printf("\n");
    return; 
}


void recWhamsort(int p, int e, int *a, int *tmp){
    int i = p+1;
    while (i < e && a[i-1] <= a[i])  i++;
    while (i < e) { 
        int s = e < 2*i - p  ?   e   :   2*i - p;
        recWhamsort(i, s, a, tmp);
        printf(" i = %d s = %d e = %d p = %d\n",i,s,e,p);
        for(int k = 0 ; k < s-p;k++) printf("dio lurrido %d\t",a[k+p]);
        printf("\n");
        merge(p, i, s, a, tmp);
        printf(" i = %d s = %d e = %d p = %d\n",i,s,e,p);
        i = s;
    }
    return;
}

void whamsort(int len, int *a){
    int *tmp = malloc(len*sizeof(int));
    recWhamsort(0, len, a, tmp);
    free(tmp);
}


    


int main (int argc, char** argv){
    Hist h = collectInput();
    for(int k = 0 ; k < h.cursor ;k++) printf("dio canaglia %d\t\n",h.digits[k]);
    whamsort(h.cursor,h.digits);
    for (int i = 0 ; i < h.cursor;i++){
        printf("%d: \n",h.digits[i]);
    }
    return 0; 
}

