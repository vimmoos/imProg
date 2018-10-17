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

typedef struct IntArray{
    int *arr;
    int size;
}IntArray;



void *safeCalloc (int sz){
    void *p= calloc(sz,sizeof(int));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

int *intAlloc (int n){
    return safeCalloc(sizeof(int)*n);
}

int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}
void reAllocIntArray( IntArray *intArr,int value ){
    intArr->size = value;
    intArr->arr = reAllocIntPointer(intArr->arr,intArr->size);
    return;
}


void appendIValue(IntArray *intArr,int value){
    if(value >= intArr->size) reAllocIntArray(intArr,value);
    intArr->arr[value-1] += 1; 
    return;
}


IntArray makeIArr(int sz){
    IntArray intArr;
    intArr.arr = intAlloc(sz);
    intArr.size = sz;
    return intArr;
}

void collectInput (){
    IntArray frequency = makeIArr(1);
    int n,max1 = 0,max2 = 0;
    scanf("%d",&n);
    if(max1==0) max1 = n;
    scanf("%d",&n);
    if(max2==0) max2 = n;
    scanf("%d",&n);
    do{
        appendIValue(&frequency,n);
        if(n != max1){
            if(frequency.arr[n-1]>frequency.arr[max1-1]) max1 = n; 
        }
        if(n != max1 && n != max2 ){
            if(frequency.arr[n-1]>frequency.arr[max2-1]) max2 = n; 
        }
        scanf("%d",&n);

    }while(n != 0 );
    printf("%d %d\n",max1,max2);
    return;

}




int main (int argc, char** argv){
    collectInput();
    return 0; 
}
