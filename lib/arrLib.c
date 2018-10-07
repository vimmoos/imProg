#include <stdlib.h>
#include <stdio.h>
#include "arrLib.h"


// resize a char pointer 
int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}
// resize a char pointer 
char *reAllocCharPointer(char *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
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

char *charAlloc (int n){
    return safeMalloc(sizeof(char)*n);
}

int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}
