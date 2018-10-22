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
// define an array struct which will have an int pointer, an int size (used for dynamic reallocation)
// and a cursor (used like an index for the int pointer) 
typedef struct IntArr{
    int *arr;
    int size;
    int cursor;
}IntArr;
//define an balanced binary search tree which will have an IntArr of nodes, a int nlayer( number of layers)
// a int  root (the index of the current root), a int start (the starting point of the tree/subtree) 
typedef struct BBSTree{
    IntArr nodes;
    int nlayer;
    int root;
    int start;
}BBSTree;
// used for dynamic allocation of an int pointer 
int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    p = realloc(p, new_size * sizeof *p);
    if ( p == NULL ) {
        printf("error cannot realloc %d",size);
        exit(EXIT_FAILURE);
    }   
    return p;
}

//classic safeMalloc for a void pointer 
void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

// use safeMalloc for allocing an int pointer 
int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

// use for reallocing the IntArr 
void reAllocIntArray(BBSTree *t){
    t->nodes.size *= 2;
    t->nodes.arr = reAllocIntPointer(t->nodes.arr,t->nodes.size);
    return;
}

// dynamic apppending logic 
void appendIValue(BBSTree *t ,int value){
    if(t->nodes.cursor >= t->nodes.size) reAllocIntArray(t);
    t->nodes.arr[t->nodes.cursor] = value;
    t->nodes.cursor +=1 ;
    return;
}

// initialize a new IntArr 
IntArr makeIA(){
    IntArr iA;
    iA.cursor = 0 ;
    iA.size = 1;
    iA.arr = intAlloc(iA.size);
    return iA;
}

// used to find the root of a subBBSTree of nlayer with an offset
int findRootBT(BBSTree t){
    return (((1<<t.nlayer)/ 2) - 1)+t.start; 
}

// initialize a BBSTree 
BBSTree makeBBST(){
    BBSTree t;
    t.nodes = makeIA();
    t.start = 0 ;
    scanf("%d",&t.nlayer);
    t.root = findRootBT(t);
    return t;
}

// free all the nodes 
void freeNodes(BBSTree t){
    free(t.nodes.arr);
    return;
}

//collectin all the imput 
BBSTree collectInput(){
    int n;
    BBSTree t = makeBBST();
    for(int i = 1 ; i < 1<<t.nlayer ; i++){
        scanf("%d",&n);
        appendIValue(&t,n);
    }
    return t;
}

// merge function for the WhamSort 
void merge(int b,int m,int e, int *arr,int *tmp){
    int i=0,j=0,index=b;
    int lenA = m-b  ;
    int lenB = e-m;
    for(int k = 0 ; k < e-b; k ++) tmp[k]= arr[k+b];
    while(i < lenA && j < lenB){
        if(tmp[i] <= tmp[lenA+j] ){
            arr[index] = tmp[i];
            i++;
        }else{
            arr[index] = tmp[lenA+j];
            j++;
        }
        index++;
    }
    while (i < lenA){ 
        arr[index] = tmp[i]; 
        i++; 
        index++; 
    } 
    while (j < lenB){ 
        arr[index] = tmp[lenA+j]; 
        j++; 
        index++; 
    }
    return; 
}

// recursive WhamSort
void recWhamsort(int p, int e, int *a, int *tmp){
    int i = p+1;
    while (i < e && a[i-1] <= a[i])  i++;
    while (i < e) { 
        int s = e < 2*i - p  ?   e   :   2*i - p;
        recWhamsort(i, s, a, tmp);
        merge(p, i, s, a, tmp);
        i = s;
    }
    return;
}

void whamsort(int len, int *a){
    int *tmp = malloc(len*sizeof(int));
    recWhamsort(0, len, a, tmp);
    free(tmp);
}

// recursive printing for the BBSTree
void recPrintT(BBSTree t){
    // safe private root i na viariable 
    int pRoot = t.root;
    // if there are more then 1 layer do 
    if(t.nlayer > 1){
        // decrement the number of layers
        t.nlayer -= 1;
        // print that this is a tree 
        printf("Tree (");
        // find the left root of its subTree 
        t.root = findRootBT(t); 
        // recursive call
        recPrintT(t);
        // than print the root of this tree 
        printf(") %d (",t.nodes.arr[pRoot]);
        // set the offset for the right subTree
        t.start = pRoot+1;
        // find the root of the right subTree
        t.root = findRootBT(t);
        // recursive call
        recPrintT(t);
        // ending of this tree 
        printf(")");
    // if there are other subTree (child) print that this is a leaf
    }else printf("Leaf %d",t.nodes.arr[t.start]);
}

// this function manage all the operation about the BBSTree 
void treeManager(){
    // build the BBSTree 
    BBSTree t = collectInput();
    whamsort(t.nodes.cursor,t.nodes.arr);
    // the recPrintT need a sorted permutation of the Tree 
    recPrintT(t);
    printf("\n");
    freeNodes(t);
    return;
}

int main (int argc, char** argv){
    treeManager();
    return 0; 
}
