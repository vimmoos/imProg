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

typedef struct IntArr{
    int *arr;
    int size;
    int cursor;
}IntArr;

typedef struct BTree{
    IntArr nodes;
    int nlayer;
    int root;
    int start;
}BTree;

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


void reAllocIntArray(BTree *t){
    t->nodes.size *= 2;
    t->nodes.arr = reAllocIntPointer(t->nodes.arr,t->nodes.size);
    return;
}



void appendIValue(BTree *t ,int value){
    if(t->nodes.cursor >= t->nodes.size) reAllocIntArray(t);
    t->nodes.arr[t->nodes.cursor] = value;
    t->nodes.cursor +=1 ;
    return;
}



IntArr makeIA(){
    IntArr iA;
    iA.cursor = 0 ;
    iA.size = 1;
    iA.arr = intAlloc(iA.size);
    return iA;
}


int findRootBT(BTree t){
    return ((1<<t.nlayer)/ 2) -1; 
}

BTree makeBT(){
    BTree t;
    t.nodes = makeIA();
    t.start = 0 ;
    scanf("%d",&t.nlayer);
    t.root = findRootBT(t);
    return t;
}

void freeH(BTree t){
    free(t.nodes.arr);
    return;
}

BTree collectInput(){
    int n;
    BTree t = makeBT();
    for(int i = 1 ; i < 1<<t.nlayer ; i++){
        scanf("%d",&n);
        appendIValue(&t,n);
    }
    return t;
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


void recPrintT(BTree t){
    int pRoot = t.root;
    if(t.nlayer > 1){
        t.nlayer -= 1;
        printf("Tree (");
        t.root = findRootBT(t)+t.start ;
       // printf("\n\tcalling SX part wiht root %d ==== and  start  %d\n",t.root,t.start);  
        recPrintT(t);
        printf(") %d (",t.nodes.arr[pRoot]);
        t.start = pRoot+1;
        t.root = findRootBT(t)+t.start ;
       // printf("\n\t\t\tcalling DX part with root  %d ==== and  start %d\n",t.root,t.start);  
        recPrintT(t);
        printf(")");

    }else printf("Leaf %d",t.nodes.arr[t.start]);
}


int main (int argc, char** argv){
    BTree t = collectInput();
    whamsort(t.nodes.cursor,t.nodes.arr);
    recPrintT(t);
    printf("\n");
    return 0; 
}
// 4
// 2 6 10 14 16 17 21 30 4 12 18 25 20 8 15
