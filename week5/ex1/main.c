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

typedef struct Groups{
    int a;
    int b;
}Groups;

typedef struct Splitter {
    Groups groups;
    int *frequency;
    int sz;
    int solution;
}Splitter;


void *safeCalloc (int sz){
    void *p= calloc(sz,sizeof(int));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

int *intAlloc (int n){
    return safeCalloc(sizeof(int)*n);
}

void freeSplitter(Splitter sl){
    free(sl.frequency);
    return;
}

Groups makeGruops ( ){
    Groups g ;
    g.a = 0;
    g.b = 0;
    return g;
}

Splitter makeS(int sz){
    Splitter sl;
    sl.sz = sz;
    sl.frequency = intAlloc(sz);
    sl.groups = makeGruops();
    return sl;
}

Splitter collectInput(){
    Splitter sl = makeS(100);
    int n;
    scanf("%d",&n);
    while(n){
        sl.frequency[n-1] += 1;
        scanf("%d",&n); 
    }   
    return sl ; 
}

void  solveProblem(Splitter *sl){
    for(int i = 2 ; i < sl->sz ; i++){
        sl->groups.a = 0;
        sl->groups.b = 0;
        for(int j = 0 ; j < sl->sz ; j++ ){
            if(i < j+1) sl->groups.a += sl->frequency[j];
            else if(j+1 < i) sl->groups.b += sl->frequency[j];
        }
        if(sl->groups.a == sl->groups.b) {
            sl->solution = i;
            break;
        }
    }
    return;
}
void printSolution(Splitter sl){
    if(sl.solution) printf("%d\n",sl.solution);
    else printf("UNBALANCED\n");
}



void structManager(){
    Splitter sl = collectInput();
    solveProblem(&sl);
    printSolution(sl);
    freeSplitter(sl);
    return;
}


int main (int argc, char** argv){
    structManager();
    return 0; 
}
