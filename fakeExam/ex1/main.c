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

typedef struct MissN{
    int *arr;
    int size;
}MissN;

// dynamic reallocation
int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp ;
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

MissN makeM(){
    MissN m;
    m.size = 1 ;
    m.arr = intAlloc(m.size);
    return m;
}

void printE(MissN m){
    for(int i=0;i<m.size;i++){
        if (m.arr[i]==0){
            printf("%d",i);
            return;
        }
    } 
}

void collectInput(){
    int n,x;
    scanf("%d",&n);
    MissN m = makeM();
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x-1 >= m.size){
            m.size = x;
            m.arr = reAllocIntPointer(m.arr,m.size);
        }
        m.arr[x-1] = 1;
    }
    printE(m);
}


int main (int argc, char** argv){
    collectInput();
    return 0; 
}
