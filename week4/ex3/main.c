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

typedef struct RecursionStruct{
    int nFunc;
    int value;
    int *array;
    int index;
}RecursionStruct;

RecursionStruct makeFS (int n, int index){
    RecursionStruct data;
    data.nFunc = n;
    data.value = value;
    data.array = intAlloc(index);
    data.index = 0;
    return data;
}



int recursion (RecursionStruct *data){
    if(data->index == data->value) return data;
    if(data->value<data->nFunc) {
        data->array[data->index] = data->value;
        data->index += 1 ;
        return recursion(data)
    }else{
        
    }

}
int main (int argc, char** argv){

    return 0; 
}
