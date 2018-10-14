
#include <stdlib.h>
#include <stdio.h>

typedef struct NPP{
    int solutions;
    int a;
    int b;
}NPP;
void *safeCalloc (int sz){
    void *p= calloc(sz,sizeof(int));
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(2);
    }
    return p;
}

int *intAlloc (int n){
    return safeCalloc(sizeof(int)*n);
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

int powe(int x,int y){
	int result=1;
	if(y==0) return 1;
	for(int i=0;i<y;i++) result *= x;
	return result;
}

int digitN(int n) {
    if (n >= 100000000) return 9;
    if (n >= 10000000) return 8;
    if (n >= 1000000) return 7;
    if (n >= 100000) return 6;
    if (n >= 10000) return 5;
    if (n >= 1000) return 4;
    if (n >= 100) return 3;
    if (n >= 10) return 2;
    return 1;
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


int isPangram(int n,int c){
    int *frequency = intAlloc(10);
    int digit,sum=0,count=0;
    //printf("number : %d\t",n);
    for(int i=1;i <= c;i++){
        digit = n%10;
        if(digit > c) break;
        if(!digit) break;
        if(frequency[digit]!=0) break;
        frequency[digit] = 1;
        sum += digit;
        count += i;
        n /= 10;
    }
    free(frequency);
    if(n) return 0;
    if(sum % 3 == 0) return 0;
    if(sum != count ) return 0;
    return 1;
}

void nPangramP(NPP *nP){
    // change the lower and the upper bound because we can easily see that if a number has 3 or less digit 
    // is impossible that this number is  a pangramPrimes because it will be divisible by 3 (logical deduction from the definition)
    // on the other side if we a number which have more than 7 digit is impossible that this nummber is a PangramPrime
    // because it will be divisible by 3 (logical deduction from the definition)
    
    if(digitN(nP->b) > 4) {
        if(digitN(nP->a) < 4 ) nP->a = powe(10,3);
        if(digitN(nP->b) > 7) nP->b = powe(10,7);
    }
    
    if(nP->a %2 == 0) nP->a += 1;
    for(int i = nP->a; i <= nP->b ; i+=2) if(isPangram(i,digitN(i))) if(prime(i)) nP->solutions += 1;
    
    return;
}


void structManager(){
    NPP nP = collectInput();
    nPangramP(&nP);
    printf("%d\n",nP.solutions);
    return;
}



int main (int argc, char **argv){
    structManager();
    return 0;
}
