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

void setIValue(IntArray *intArr){

    return;
}

void printIV(IntArray intArr, int index){
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

void setCValue(CharArray *charArr,char c,int cursor){
    charArr->array[cursor]=
    return;
}

void printCV(CharArray charArr, int index);

void reAllocCharArray( CharArray *charArr){
    charArr->size *= 2;
    charArr->array = reAllocCharPointer(charArr->array,charArr->size);
    return;
}