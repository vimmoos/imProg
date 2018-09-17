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
#include "../../lib/utils.h"
#include "../../lib/arrLib.h"

int fDigitConstraint(int x , int y){
    int Tvalue;
    Tvalue = x%2==0 || x%5==0 || x==0 ? 0 : 1;
    Tvalue = y%2==0 || y%5==0 || y==0 ? 0 : 1;
    return Tvalue;
}

int Prime (int num){

}

int superPrime (int num,int *p){
    int SP=0;
    int *digits=intAlloc(10);
    if (fDigitConstraint(num%10,num%100)==1){
        while (num>0){
            digits[SP]=num%10;
            SP++;
            num /= 10;
        
        }
        p++;
    }
    return SP;
}

int nSuperPrime (int n) {
    int x=0,result;
    for (int i=1;x<=n;i++){
        if(Prime(i)==1) result = superPrime(i,&x);
    }
    return result;
}

int main (int argc, char** argv){
    int x;
    scanf("%d ",&x);        
    printf("%d",nSuperPrime(x));
    return 0; 
}
