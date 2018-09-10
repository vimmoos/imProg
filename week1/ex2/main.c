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
int main (int argc, char** argv){
    int number;
    scanf("%d",&number);
    // check whether all the digits are even or not
    if (((number%10)%2==0)&&(((number/10)%10)%2==0)&&(((number/100)%10)%2==0)&&(((number/1000)%10)%2==0)){
        printf("%d is an even digit number.\n",number);
    }else{
        printf("%d is not an even digit number.\n",number);
    }
    return 0; 
}
