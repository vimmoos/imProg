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
#include <string.h>
#include "../../lib/utils.h"
#include "../../lib/midT.h"
#include "../../lib/arrLib.h"

typedef struct LinearEq{
    Options op;
    int y;
    int m;
    int x;
    int q;
}LinearEq;

typedef struct Options{
    CharArray *carr;
    int size;
    int cursor;
}Options;

typedef struct NQueens{
    LinearEq *eqs;
    CharArray solution;
    int sz;
}NQueens;

Options makeO(int sz){
    Options options;
    options.size = sz;
    options.cursor = 0;
    for(int i=0;i<sz;i++){
        options.carr[i] = makeCArr(sz);    
    }
    return options;
}

LinearEq makeL(){
    LinearEq le;
    le.q = 0;
    le.m = 0;
    le.x = 0;
    le.y = 0;
    char *options[]={
        "slope",
        "quote",
        "solveX",
        "solveY"
    };
    le.op = setOptions(options,4);
    return le;
}

NQueens makeNQs(int sz){
    NQueens queens;
    queens.sz = sz;
    queens.eqs = safeMalloc(sizeof(LinearEq)*sz);
    for(int i=0;i<sz;i++){
        queens.eqs[i] = makeL();
        queens.eqs[i].y = i;
        queens.eqs[i].m = 1;
    }
    queens.eqs[0].x = rand() % sz ;
    return queens;
}


//   TODO string collection struct 
//              NOTE
// the lenght of the char **options must be equal or at least minor than  sz 
// otherwise a seg fault will stop the program
Options setOptions(char **options,int sz){
    Options op = makeO(sz);
    for(int i=0;i<sz;i++){
        for(int j=0;j<strlen(options[i]);j++ ){
            appendCValue(&op.carr[i],options[i][j]);
        }
    }
    return op;
}


int codeOption(Options ops,char *op){
    int code;
    for (int i=0;i<ops.size;i++){
        if(matchPString(ops.carr[i].array,op) ==1 ) code = i;
    }
    return code;
} 



int solveLinearEquation(LinearEq le,char *option){
    switch (codeOption(le.op,option)){
        case 0:
            return (le.y-le.q)/le.x;
        case 1:
            return le.y/(le.x*le.m);
        case 2:
            return (le.y-le.q)/le.m;
        case 3:
            return le.m*le.x + le.q;
        default:
            pritf("wrong option");
            exit(EXIT_FAILURE);
            break;
    }
}

int setSolveLE( char *option,int firstp,int secondp,int thirdp){
    LinearEq le = makeL();
    switch (codeOption(le.op,option)){
        case 0:
            le.y = firstp;
            le.x = secondp;
            le.q = thirdp;
            return (le.y-le.q)/le.x;
        case 1:
            le.y = firstp;
            le.m = secondp;
            le.x = thirdp;
            return le.y/(le.x*le.m);
        case 2:
            le.y = firstp;
            le.m = secondp;
            le.q = thirdp;
            return (le.y-le.q)/le.m;
        case 3:
            le.m = firstp;
            le.x = secondp;
            le.q = thirdp;
            return le.m*le.x + le.q;
        default:
            pritf("wrong option");
            exit(EXIT_FAILURE);
            break;
    }
}
void setX(LinearEq *le,int x){
    le->x = x ;
    return;
}

void setY(LinearEq *le,int y){
    le->y = y ;
    return;
}

void setM(LinearEq *le,int m){
    le->m = m ;
    return;
}

void setQ(LinearEq *le,int q){
    le->q = q ;
    return;
}





void nextQueen(NQueens *queens);

void convertSolution(NQueens *queens);

void printS(NQueens queens);

void printSL(NQueens  queens);



int main(int argc, char  **argv){

    return 0;
}
