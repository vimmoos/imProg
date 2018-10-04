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

void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

char **charAlloc (int n){
    return safeMalloc(sizeof(char*)*n);
}

char **matrixCharAlloc(int n){
    char **c = charAlloc(n);
    for (int i = 0; i < n; i++ ) c[i]=safeMalloc(100);
    return c;
}
void collectGenome (char *p,int index){
    do{
        p[index]=getchar();
        index++;
    }while(p[index-1]!='\n');
    return;
}
void collectName (char *p){
    int i=0;
    do{
        p[i]=getchar();
        i++;
    }while(p[i-1]!=':');
    collectGenome(p,i);
    return;
}


char **collectInput (char *p){
    int i=0,n;
    do{
        p[i]=getchar();
        i++;
    }while(p[i-1]!='\n');
    scanf("%d",&n);
    char **p1 = matrixCharAlloc(n);
    for(int j=0;j<n;j++) collectName(p1[j]);
    return p1;

}
int main (int argc, char** argv){
    char *p = safeMalloc(sizeof(char)*30);
    char **p1 = collectInput(p);
    for(int i=0;i<2;i++){
        for(int j=0;j<10;j++){
            printf("%c\t",p1[i][j]);
        }
    }
    return 0; 
}
