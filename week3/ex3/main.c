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
//sqroot calculation
int sqroot(int k){
    int x=1;
    if(k==2 || k==3) return x;
    while (x*x<k) x++;
    return x;
}
// safeMalloc is a function than malloc a pointer    and 
// if the pointer it's null exit the process
void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}
//safeMalloc an integer pointer of size n
int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}
// elevate an integer x to an integer y 
int power (int x,int y){
    int n=1;
    for(int i=1;i<y;i++) n *= x ;
    return n;
}

//drop a single digit from a pointer and then bring it back to the normal form  
int dropedDigit (int *d, int index, int digit ){
    int finalN=0;
    for (int j=index-1;j>=0;j--){
        //finalN is the the number in the normal form without a digit
        finalN=  j!=digit  ? finalN+(d[j]*power(10,(index-1))) : finalN ;
        // then change the exponent for the power func 
        // in this way every single digit will be  on a different power of 10 
        index= j!=digit ? index-1 : index;
    }
    return finalN;
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

//calculate whether num is superPrime or not
int superPrime (int num){
    int index=0,nPrime=0,tValue=0;
    if (prime(num)==1){
        //malloc *digits with size 10 
        int *digits=intAlloc(10);
        // insert every digits of num
        while (num>0){
            digits[index]=num%10;
            index++;
            num /= 10;
        }
    
        for(int j=0;j!=index;j++)
            //check whether the number without a digits is prime or not 
            nPrime = prime(dropedDigit(digits,index,j))==1 ? nPrime+1 : nPrime ;
        //tValue is true only when nPrime it's equal to the lenght of the initial number 
        tValue= nPrime == index ? 1 : 0;
        // free the pointer digits
        free(digits);
    }
    return tValue;
}

// calculate the n-superPrime 
int nSuperPrime (int n) {
    int x=0,result=0;
    for (int i=11;x<n;i=i+2){
        //check whether i is a superPrime or not 
        if(superPrime(i)==1){
            result = i;
            x++;
        }    
    }
    return result;
}
// the main function just scan and print the result 
int main (int argc, char** argv){
    int x;
    scanf("%d",&x);        
    printf("%d\n",nSuperPrime(x));
    return 0; 
}

// htc@veracles.nl 
