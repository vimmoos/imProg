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
int main (int argc, char** argv){
    int nFriends; 
    scanf("%d",&nFriends);
    // calculate the number of bottles
    int nBottles = (nFriends+1)%10 == 0  ? (nFriends+1)/10 : (nFriends+1)/10+1;
    printf("%d\n",nBottles);
return 0; 
}
