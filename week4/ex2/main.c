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
#define  OFFSET  96
// this is the calloc version of safeMalloc 
void *safeCalloc (int sz){
    void *p= calloc(sz,sizeof(char));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

// initialize a char pointer
char *charCalloc (int n){
    return safeCalloc(sizeof(char)*n);
}
//
void diagonalChecker(char *p,int index,int *tValue){
    if(index==8) return;
    int q1=0,q2=0,q3=0,q4=0;
    q1 = (index+1) + (p[index]-OFFSET);
    q2 = (index+1) - (p[index]-OFFSET); 
    for (int i=0;i<8;i++){
        if(i!=index){
            q3 = (i+1) + (p[i]-OFFSET);
            q4 = (i+1) - (p[i]-OFFSET);
            if(q1==q3 || q2 == q4) *tValue = 0;
        }   
    }
    index++;
    if(*tValue == 1) diagonalChecker(p,index,tValue);
    else return;
}

char *colletInput(int *tValue){
    int i=0,nPos;
    char cPos;
    char *p = charCalloc(8);
    do{
        scanf("%c%d%*c",&cPos,&nPos);
        if(p[nPos-1]!=0) *tValue = 0;
        for(int j=0;j<8;j++){
            if(p[j]==cPos) *tValue = 0;
        }
        p[nPos-1] = cPos;
        i++;
    }while(i<8);
    
    return p;
}

int main (int argc, char** argv){
    int tValue = 1;
    char *p = colletInput(&tValue);
    if(tValue == 1) diagonalChecker(p,0,&tValue);
    printf("%s\n",tValue == 1 ? "VALID":"INVALID");
    free(p);
    return 0; 
}
