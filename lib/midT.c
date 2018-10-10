#include "midT.h"
#include "arrLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

IntArray makeIArr(int sz){
    IntArray intArr;
    intArr.array = intAlloc(sz);
    intArr.size = sz;
    intArr.cursor = 0;
    return intArr;
}

void appendIValue(IntArray *intArr,int value){
    if(intArr->cursor >= intArr->size) reAllocIntArray(intArr);
    intArr->array[intArr->cursor]= value;
    intArr->cursor += 1; 
    return;
}

void printI(IntArray intArr){
    printf("[");
    for(int i=0;i<intArr.size;i++){
        printf("%d,",intArr.array[i]);
    }
    printf("]\n");
    return;
}

void reAllocIntArray( IntArray *intArr){
    intArr->size *= 2;
    intArr->array = reAllocIntPointer(intArr->array,intArr->size);
    return;
}


CharArray makeCArr(int sz){
    CharArray charArr;
    charArr.array = charAlloc(sz);
    charArr.size = sz;
    charArr.cursor = 0;
    return charArr;
}
//TODO add string terminator 
void appendCValue(CharArray *charArr,char c){
    if(charArr->cursor >= charArr->size) reAllocCharArray(charArr);
    charArr->array[charArr->cursor]= c;
    charArr->cursor += 1; 
    return;
}

void printC(CharArray charArr){
    printf("[");
    for(int i=0;i<strlen(charArr.array);i++){
        printf("%c,",charArr.array[i]);
    }
    printf("]\n");
    return;
}

void reAllocCharArray( CharArray *charArr){
    charArr->size *= 2;
    charArr->array = reAllocCharPointer(charArr->array,charArr->size);
    return;
}
