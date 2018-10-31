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

typedef struct TChiper{
    char *code;
    int size;
    int cursor;
    int m;
    int n;
}TChiper;

int *reAllocCharPointer(char *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}

// classic safeMalloc 
void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}
//safeMalloc and int *
char *charAlloc (int n){
    return safeMalloc(sizeof(char)*n);
}

TChiper makeTC(){
    TChiper tc; 
    tc.code = charAlloc(1);
    tc.size = 1;
    tc.cursor = 0;
    return tc;
}

TChiper collectInput(){
    char c;
    TChiper tc = makeTC();
    c = getchar
    if(c == '.') return tc;
    do{
        if(c == ' ') c = '#';
        if(tc.cursor >= tc.size){
            tc.size *= 2 ;
            tc.code = reAllocCharPointer(tc.code,tc.size);
        }
        tc.code[tc.cursor] = c ;
        tc.cursor += 1;
        c = getchar();
    }while(c != '.');
    return tc;
}

void findMod(TChiper *tc){
    for(int i = 0;i<tc->cursor;i++){
        if(i*i <= tc->cursor && (i+1)*(i+1) > tc->cursor){
            tc->m = i
            break; 
        }
    }
    for(int j = 0;j < tc.cursor ;j++) {
        if(j*tc->m >= tc->cursor){
            tc->n = j;
            break;
        }
    }
}

void fillCode(){

}

int main (int argc, char** argv){

    return 0; 
}
