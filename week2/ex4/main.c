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

 
//this int func reverse a number 
int Rnumber (int x){
    int Rx=0;
    while (x>0){
        Rx = Rx*10+(x%10);
        x = x/10;
    }
    return Rx;
}

//this int func calculate how many multipals there are in the interval between a and b
int mulpals (int a,int b){
    int x=a,n=0;
    while(x<=b){
        int X = Rnumber(x);
        if (X%x==0) n=n+1;
        x++;
    }
    return n;
}
//the main func just scan and print the result
int main (int argc, char** argv){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",mulpals(a,b));
    return 0; 
}
