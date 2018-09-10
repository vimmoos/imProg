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
//this void function swap two pointers  
void swapInt (int *A,int *B){
    *A=*A+*B;
    *B=*A-*B;
    *A=*A-*B;
    return;
}

int main (int argc, char** argv){
    int Rnumber;
    scanf("%d",&Rnumber);
    // split Rnumber in 4 digit 
    int X =Rnumber%10;
    int Y =(Rnumber/10)%10;
    int Z =(Rnumber/100)%10;
    int S =(Rnumber/1000)%10;
    // check if X<Y && Z<S otherwise swap their pointers 
    if (X>Y) swapInt(&X,&Y);
    if (Z>S) swapInt (&Z,&S);
    // check if X<Z && X<S otherwise swap their pointers
    if (X>Z) {
        if(X>S){
            swapInt (&Y,&S);
            swapInt(&X,&Z);
        }else{
            swapInt (&Y,&Z);
            swapInt(&X,&Y);   
        }
    }
    // check if Y<S otherwise swap their pointers
    if (S<Y){
        swapInt (&S,&Z);
        swapInt(&Y,&S);
    }
    // check if Z<S && Z>Y otherwise swap their pointers
    if (Z>S) swapInt(&Z,&S);
    if (Y>Z) swapInt (&Y,&Z); 
    printf ("%d%d%d%d\n",S,Z,Y,X);
return 0; 
}
