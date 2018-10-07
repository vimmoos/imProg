#ifndef MIDTLIB_H
#define MIDTIB_H


typedef struct IntArray{
    int *array;
    int size;
    int cursor;
}IntArray;


IntArray makeIArr(int sz);

void setIValue(IntArray *intArr);

void printIV(IntArray intArr, int index);

void reAllocIntArray( IntArray *intArr, int sz);


typedef struct CharArray{
    char *array;
    int size;
    int cursor;
}CharArray;

CharArray makeCArr(int sz);

void setCValue(CharArray *charArr);

void printCV(CharArray charArr, int index);

void reAllocCharArray( CharArray *charArr, int sz);


#endif