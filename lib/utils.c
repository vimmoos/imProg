#include <stdlib.h>
#include <stdio.h>
#include "utils.h"


void swapInt (int *A,int *B){
    *A=*A+*B;
    *B=*A-*B;
    *A=*A-*B;
    return;
}
int sqrootInt(int k){
    int x=1;
    while (x*x<k) x++;
    return x*x==k ? x : 0;
}

int gcd (int a,int b){
    int r;
    while (a != 0) {
        r = b%a;
        b = a;
        a = r;
    }
    return b;
}

int lcm (int a, int b) {
    return  (a*b)/(gcd(a,b));
}

int Revertnumber (int x){
    int Rx=0;
    while (x>0){
        Rx = Rx*10+(x%10);
        x = x/10;
    }
    return Rx;
}