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

typedef struct JumpArr{
    int *arr;
    int size;
    int cursor;
    int reachable;
}JumpArr;

void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

JumpArr makeJump(int sz){
    JumpArr jA;
    jA.cursor = sz-1 ;
    jA.arr = intAlloc(sz);
    return jA;
}

JumpArr collectInput(){ 
    int n;
    scanf("%d",&n);
    JumpArr jump = makeJump(n);
    for(int i=0;i<n;i++){
        scanf("%d",&jump.arr[i]);
    }
    return jump;
}

int  reachable(JumpArr *jump){
    if(jump->cursor == 0) return 1;
    
    for(int i = jump->cursor-1 ; i >= 0; i--){
        //printf("cursor == %d\t index == %d\n",jump->cursor,i);
        if(jump->cursor - i <= jump->arr[i]){
            //printf("cursor == %d\n",jump->cursor);
            jump->cursor = i;
            return reachable(jump);
        }
    }
    return 0 ;
}


int main (int argc, char** argv){
    JumpArr jump = collectInput();

    printf("%s\n",reachable(&jump) == 1 ? "YES" : "NO" );
    return 0; 
}
