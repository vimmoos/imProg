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
#include <limits.h>
#define MOD 2099202
#define MODN 1023


typedef struct Hist{
    int *frequency;
    int size;
}Hist;

typedef struct ModularHist{
    Hist *h;
    int modN;
    int *activate;
    int maxIflag;
}MH;


int *safeICalloc (int sz){
    int  *p= (int *)calloc(sz,sizeof(int));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}
Hist *safeSCalloc (int sz){
    Hist *p= (Hist *)calloc(sz,sizeof(Hist));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

Hist makeH(){
    Hist h;
    h.size = MOD;
    h.frequency = safeICalloc(h.size);
    return h;
}


void appendIValue(MH *mh ,int value){
    int index = value / MOD;
    if(mh->activate[index] == 0 ) mh->h[index] = makeH(); 
    mh->h[index].frequency[value%MOD] += 1;
    mh->activate[index] = 1;
    return;
}


MH makeMH(){
    MH mh;
    mh.modN = MODN;
    mh.h = safeSCalloc(mh.modN);
    mh.activate = safeICalloc(mh.modN);
    mh.maxIflag = 0;
    for(int i = 0;i<MODN;i++){
        Hist h = makeH();
        mh.h[i] = h;
    }
    return mh;
}
void freeH(Hist h ){
    free(h.frequency);
    return;
}

void freeMH(MH mh ){
    free(mh.h);
    return;
}

MH collectInput(){
    int n;
    MH mh = makeMH();
    scanf("%d",&n);
    do{ 
        if(n==INT_MAX) mh.maxIflag += 1;
        appendIValue(&mh,n);
        scanf("%d",&n);
    }while( n != 0);
    return mh;
}



int main (int argc, char** argv){
    MH mh = collectInput();
    for(int j = 0 ; j < MODN ; j++){
       // printf("flag == %d\n",mh.h[j].activate);
        if(mh.activate[j]){
            for (int i = 0 ; i <= MOD;i++){
                //printf("%d: %d\n",i*(j+1),mh.h[j].frequency[i]);
                if(mh.h[j].frequency[i] != 0 ) printf("%d: %d\n",i+MOD*j,mh.h[j].frequency[i]);
            }
        }
    }
    if(mh.maxIflag != 0) printf("%d: %d\n",INT_MAX,mh.maxIflag);  
    return 0; 
}