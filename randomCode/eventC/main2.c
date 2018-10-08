/* JSON 
{
    'author':['massimilianoFalzari',"bandoos"]
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


typedef struct Event{
    int param;
    FunQ *qp;
}Event;
// forever by value 
typedef struct Fun{
    Event (*funP)(Event);
    char *name;
}Fun;

typedef struct FunQ{
    Fun *queue;
    int cursor;
    int size;
}FunQ;


Event makeEvent(int para,FunQ *qp){
    Event ev;
    ev.param = para;
    ev.qp = qp;
    return ev;
}



Fun makeFun(char *name,Event (*funP)(Event)){
    Fun f;
    f.name = name;
    f.funP = funP;
    return f;
}

FunQ makeFunQ(int sz){
    FunQ q;
    q.cursor = 0;
    q.size = sz;
    q.queue = safeMalloc(sizeof(Fun)*sz);
    return q;
}

Fun *reAllocFunPointer(Fun *fp,int size ){
    size_t new_size = size ;
    void *tmp = realloc(fp, new_size * sizeof(Fun));
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    fp = tmp;      
    return fp;
}

void enQ(FunQ *qp,Fun f){
    if(qp->cursor>=qp->size) {
        qp->size += 1;
        reAllocFunPointer(qp->queue,qp->size);
    }
    qp->queue[qp->cursor] = f;
    qp->cursor += 1;
    return;
}

int hasNext(FunQ *qp){
    return qp->cursor >= qp->size ? 0 : 1 ;
} 


Event exeQ(FunQ *qp,Event ev0){
    qp->cursor = 0 ;
    while(hasNext(qp)){
        printf("evalueting");
        ev0 = qp->queue[qp->cursor].funP(ev0);
        qp->cursor += 1; 
    }    
    return ev0;
}



// typedef struct 
Event fun0(Event e ){ 
    Fun f1 = makeFun("test",fun1);
    printf("F0='Value of a is %d'\n", e.param*e.param);
    enQ(e.qp,f1);
    
    return e; 
} 

Event fun1(Event e ){ 
   
    printf("Value of a is %d\n", e.param);
    return e; 
} 
Event fun2(Event e ){ 

    printf("Value of a is %d\n", e.param*2);
    return e; 
} 

Event fun3(Event e ){ 
    printf("Value of a is %d\n", e.param*e.param/2);
    return e; 
} 



int main(int argc, char  **argv){
    // void (*funP)(int) = fun;
    // funP(10);
    // void (*funPA[])(int) = {fun,fun1,fun2,fun3};
    // int c;
    // scanf("%d",&c);
    // for(int i=0;i<4;i++){
    //     funPA[i](c);
    // }
    
        
    // Fun f0 = makeFun("test",fun0);
    // Fun f2 = makeFun("test",fun2);
    // Fun f3 = makeFun("test",fun3);

    // FunQ evLoop = makeFunQ(2);
    // Event ev0 = makeEvent(2,&evLoop);
    // enQ(&evLoop,f0);
    // ev = exeQ(&evLoop,ev);
    // printf("%d\n",ev.param);
    return 0;
}
