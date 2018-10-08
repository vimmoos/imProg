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

typedef struct IntHist{
    int *array;
    int *frequency;
    int size;
    int cursor;
}IntHist;


IntArray makeIArr(int sz);

void appendIValue(IntArray *intArr,int value);

int *intAlloc (int n);

void *safeMalloc (int sz);



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

IntArray makeIArr(int sz){
    IntArray intArr;
    intArr.array = intAlloc(sz);
    intArr.size = sz;
    intArr.cursor = 0;
    return intArr;
}

void appendIValue(IntArray *intArr,int value){
    intArr->array[intArr->cursor]= value;
    intArr->cursor += 1; 
    return;
}

void colectionInput(IntArray *arr){
    int input;
    do{
        scanf("%d",&input);
        appendIValue(arr,input);
    }while(input != 0);
    return;
}

int main (int argc, char** argv){
  
    return 0; 
}
