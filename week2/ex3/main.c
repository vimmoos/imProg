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




int recursion (int a,int n){
    for (int k=1;k<=a/2;k++){
        if(a%k==0){
            // printf("first\n");
            for (int x=1;x<=k;x++){
                if((a/k)%x==0 ){
                    // printf("==========second\n");  
                    for(int y=1;y<=x;y++){
                        // printf("====================third\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t%d\n",k,x,y,k*x*y);
                        if(x*y*k==a) n++;
                    }
                }  
            }
        }
        
    }
    return n;
}

int main (int argc, char** argv){
    int R , n=1;
    scanf("%d",&R);
    printf("%d\n", recursion(R,n));
    return 0; 
}
