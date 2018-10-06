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

void putALotsOfChar(int n){
    for(int i=0;i<n;i++){
        putchar('A');
    }
}
int main (int argc, char** argv){
    printf("ATCG\n3\nfaggi o:");
    putALotsOfChar(2048);
    printf("\nmimm o:");
    putALotsOfChar(2048);
    printf("\nban do:");
    putALotsOfChar(2048);
    printf("\n");
    return 0; 
}
