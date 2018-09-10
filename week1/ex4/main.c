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
    int Xa,Ya,Xb,Yb,Xc,Yc,Xd,Yd;
    scanf("%d %d %d %d",&Xa,&Ya,&Xb,&Yb);
    scanf("%d %d %d %d",&Xc,&Yc,&Xd,&Yd);
    
    /* 
        divide the problem in two part:
        in this way the Xpart and the Ypart are the same.
    */

    //check if Ya<Yb && Yc<Yd otherwise swap their pointers (the same for Xparts)
    
    if (Ya>Yb) swapInt(&Ya,&Yb);
    if (Yc>Yd) swapInt(&Yc,&Yd);
    if (Xa>Xb) swapInt(&Xa,&Xb);
    if (Xc>Xd) swapInt(&Xc,&Xd);
    
    // check if Ya<Yc otherwise swap their pointers (the same for Xparts)
    
    if (Ya>Yc){
        swapInt(&Ya,&Yc);
        swapInt(&Yb,&Yd);
    }

    if (Xa>Xc){
        swapInt(&Xa,&Xc);
        swapInt(&Xb,&Xd);
    }
    
    //  use the Xpart & Ypart for calculate the Area  
    int Xpart = Xd>Xb ? Xb-Xc : Xd-Xc;
    int Ypart = Yd>Yb ? Yb-Yc : Yd-Yc;
    int Area = Xpart * Ypart;
    printf("%d\n",Area >=0 ? Area : 0); 
    return 0; 
}
