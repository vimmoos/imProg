#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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




int main(int argc,char **argv){
    int size=0;
    char *cp=charAlloc(10000);
    do {
        // just check if i need to resize or not 
        // for every person scan all the name and the genome 
        cp[size] = getchar();
        size++;
    }while(cp[size-1]!= '0');
   
    printf("%d",strlen(cp));
    return 0 ;
}