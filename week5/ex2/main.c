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

typedef struct Pangram{
    int *frequencyP;
    int size;
    int maxD;
}Pangram;

typedef struct NPP{
    int solutions;
    int a;
    int b;
}NPP;

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
//sqroot calculation
int sqroot(int k){
    int x=1;
    if(k==2 || k==3) return x;
    while (x*x<k) x++;
    return x;
}
//calculate whether a number is prime or not 
int prime (int num){
    int tValue = 1;
    int root = sqroot(num);
    // remove the edge case 1,2,3 because their root is 1 
    if( root==1 ) return ( num==1 ? 0 : tValue );
    // remove the even number 
    if(num%2!=0){
        //start from 3 and check all the odd number 
        //if one of them is a divisor of num 
        // change the tValue to 0 and break
        for(int j=3; j<=root ;j+=2){
                if(num%j==0 ) {
                    tValue = 0;
                    break;
                }
        }
    }else tValue=0;
    //return the tValue which could be only 0 or 1 
    return tValue;
}


Pangram makePangram(){
    Pangram pp;
    pp.size = 10;
    pp.maxD = 1;
    pp.frequencyP = intAlloc(pp.size);
    return pp;
}

NPP makeNPP(){
    NPP nPP;
    nPP.a = 0;
    nPP.b = 0;
    nPP.solutions = 0;
    return nPP;
}

NPP collectInput(){
    NPP nP = makeNPP();
    scanf("%d",&nP.a);
    scanf("%d",&nP.b);
    return nP ;
}

int extractFD(Pangram *p , int n){
    int digit;
    //printf("number : %d\t",n);
    while(n){
        digit = n%10; 
        if(digit){
            if(p->maxD < digit ) p->maxD = digit;
            //printf("%d\t",p->maxD);
            if(p->frequencyP[digit]==0) p->frequencyP[digit] = 1;
            else {
                //printf("\n");
                return 0 ;
            }
            
        }
        n /= 10;
    }
    //printf("\n");
    return 1;
}

int isPangram(int n ){
    Pangram p = makePangram();
    if(!extractFD(&p,n)) return 0 ;
    for(int i = 1;i <= p.maxD;i++){
        //printf("frequency of the digit %d == %d\n",i,p.frequencyP[i]);
        if(!p.frequencyP[i]) return 0;
    }
    //printf("number %d is a pangram\n",n);
    free(p.frequencyP);
    return 1;
}


void nPangramP(NPP *nP){
    for(int i = nP->a ; i <= nP->b ; i++){
        if(isPangram(i)) if(prime(i)) nP->solutions += 1;
    }
    return;
}


void structManager(){
    NPP nP = collectInput();
    nPangramP(&nP);
    printf("%d\n",nP.solutions);
    return;
}



int main (int argc, char** argv){
    //if(isPangram(7652403)) printf("bonaa\n");
    structManager();
    return 0; 
}
