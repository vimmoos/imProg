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


typedef struct Event Event;

typedef struct Fun Fun;

void fun3(Event *e );

void fun2(Event *e );

void fun1(Event *e );

void fun0(Event *e );

struct Event{
    int param;
    Fun *fp; // the function which will execute the event 
    int kill;
};

struct Fun{
    void (*funP)(Event*);
    char *name;
    Fun *nextP;
};

Event makeEvent(int para,Fun *fp){
    Event ev;
    ev.param = para;
    ev.fp = fp;
    ev.kill = 0;
    return ev;
}


Fun makeFun(char *name, void (*funP)(Event*)){
    Fun f;
    f.name = charAlloc(strlen(name)+1);
    for(int i=0;i <= strlen(name);i++){
        printf("furby!\n");
        f.name[i] = name[i];
    }
    f.funP = funP;

    f.nextP = NULL;
    return f;
}

//@callback
void fun0(Event *e ){ 
    // exec body
    printf("Fun0, %d \n", e->param);
    e->param+=1;// inc count
    // construct next
    Fun f1 = makeFun("test1",fun1);
    // set next on the event's environment Fun
    e->fp->nextP = &f1;
    return ; 
} 

void fun1(Event *e ){ 
    printf("Fun1, %d \n", e->param);
    e->param+=1;
    Fun f0 = makeFun("test0",fun0);
    e->fp->nextP = &f0;
    return; 
} 
void fun2(Event *e ){ 
    
    printf("Fun2, %d \n", e->param);
    e->param+=1;
    
    Fun f3 = makeFun("test3",fun3);
    e->fp->nextP = &f3;
    //e->fp->nextP->funP(e);
   printf("In fun2b =====: %s\n",e->fp->nextP->name);
    return; 
} 

void fun3(Event *e ){ 
    printf("\tFun3, %d \n", e->param);
    e->param+=1;
    e->kill = 1;
    return; 
} 




int hasNext(Fun *f){
    return f->nextP == NULL ? 0 : 1 ;
} 

/**
 * Execute a FULL chain of functions.
 * Infinite loop ready if function are expansiveEvent fun3(Event e )
 * ends as soon as all functions are executed, SYNC,
 * so that t might be infite :)
 * */
void  exeF(Event *buffer){
    printf("init buffer:\t%d\n",buffer->param);
    Event *ev = buffer;
    int s;
    do{
        ev->fp->funP(ev);
        printf("DONE: %s \n",ev->fp->name);
        ev->fp = ev->fp->nextP;
                    
    }while(!ev->kill);    

    return;
}




int main(int argc, char  **argv){
    Fun f2 = makeFun("start",fun2);
    Event ev0 = makeEvent(0,&f2);
    exeF(&ev0);
    return 0;
}
