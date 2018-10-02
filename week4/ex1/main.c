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


int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

typedef struct swappingData{
    int size;
    int *array;
    int indexI;
    int indexJ;
}swappingData;

swappingData makeFS (int size){
    swappingData data;
    data.size = size;
    data.array = intAlloc(size);
    data.indexI = -1 ;
    data.indexJ = -1 ;
    return data;
}


void swapValue(swappingData *data){
    int temp = data->array[data->indexI];
    data->array[data->indexI]=data->array[data->indexJ];
    data->array[data->indexJ]=temp;
    return;
}

void collectInput (swappingData *data){
    while(data->indexI!=0 || data->indexJ!=0){
        // printf("WTf\t%d\t",data->size);
        if(data->indexI == -1){
            for(int i=0;i<data->size;i++){
                if(i== data->size - 1) scanf(" %d",&data->array[i]);
                else  scanf(" %d",&data->array[i]);
                // printf("WTH\t%d\t",data->array[i]);
                // printf("wTH\t%d\t",data->indexI);
            }
        // printf ("after frist scan %d %d\n",data->indexI,data->indexJ);
        }
        
        scanf(" %d%d",&data->indexI,&data->indexJ);
        swapValue(data);
        //  printf ("after rescan %d %d\n",data->indexI,data->indexJ);
    }
    return;
}

int checkAsc (swappingData *data){
    for (int i = 1;i<data->size;i++){
            if(data->array[i-1]>data->array[i]) return 0;
    }
    return 1;
}

int main (int argc, char** argv){
    int sz=0;
    scanf("%d",&sz);
    swappingData data = makeFS(sz);
    collectInput(&data);
    printf("%s\n",checkAsc(&data)==1 ? "YES" : "NO");
    free(data.array);
    return 0; 
}
