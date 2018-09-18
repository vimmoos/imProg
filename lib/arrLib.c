#include <stdlib.h>
#include <stdio.h>
#include "arrLib.h"






void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

char *charAlloc (int n){
    return safeMalloc(sizeof(char)*n);
}

int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}
