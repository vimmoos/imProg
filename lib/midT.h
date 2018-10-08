#ifndef MIDTLIB_H
#define MIDTLIB_H


typedef struct IntArray{
    int *array;
    int size;
    int cursor;
}IntArray;


IntArray makeIArr(int sz);

void appendIValue(IntArray *intArr,int value);

void printI(IntArray intArr);

void reAllocIntArray( IntArray *intArr);


typedef struct CharArray{
    char *array;
    int size;
    int cursor;
}CharArray;

CharArray makeCArr(int sz);

void appendCValue(CharArray *charArr,char c);

void printC(CharArray charArr);

void reAllocCharArray( CharArray *charArr);


#endif
