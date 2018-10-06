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



// define all the struct 
typedef struct Pattern{
    char* pattern;
    int size;
    int cursor;
}Pattern;

typedef struct Buff{
    char *buffer;
    int size;
    int cursor;
}Buff;

typedef struct Person{
    char *name;
    char *genome;
    int sizeG;
    int *solutions;
    int cursorS;
    int sizeS;
}Person;

typedef struct Database{
    Person *data;
    int size;
    int cursor;
}Database;

typedef struct Problem{
    Database db;
    Pattern pattern;
}Problem;

//declaration of the headers 

void *safeMalloc (int sz);

char *charAlloc (int n);

int *intAlloc (int n);

Person *PersonAlloc(int sz);

Problem makeP(Pattern pattern);

Database makeDB(int maxSZ);

void addRecordDB(Database *dbp, Person record);

void parsePerson(Buff *buffer , Database *dbp);

void printDb(Database db);

Database parseDB();


void setProblem(Problem *P,Database db);

void solveProblem(Problem *P);

void setSolution(Problem *P,int row,int col);

// define functions body

//normal safemalloc 
void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}

// standard  char alloc 
char *charAlloc (int n){
    return safeMalloc(sizeof(char)*n);
}

// standard int alloc 
int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}
//standard alloc of sizeof(Person)
Person *PersonAlloc(int sz){
    return safeMalloc(sizeof(Person)*sz);
}
// resize an int pointer 
int *reAllocIntPointer(int *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}
// resize a char pointer 
char *reAllocCharPointer(char *p,int size){
    size_t new_size = size;
    void *tmp = realloc(p, new_size * sizeof *p);
    if ( tmp == NULL ) {
        exit(EXIT_FAILURE);
    }   
    p = tmp;      
    return p;
}

// make a Buffer, charAlloc the char * then initialize size and cursor
Buff makeBuff(){
    Buff buffer;
    buffer.buffer = charAlloc(2);
    buffer.size = 1;
    buffer.cursor = 0; 
    return buffer;
}

// make the P and append the char *pattern
Problem makeP(Pattern pattern){
    Problem P;
    P.pattern = pattern;
    return P;
}

Pattern makePattern(){
    Pattern pattern;
    pattern.pattern = charAlloc(2);
    pattern.size = 1;
    pattern.cursor = 0;
    return pattern;
}

// make the database, 
Database makeDB(int maxSZ){
    Database db;
    // initialize the size at maxSZ
    db.size = maxSZ;
    //initialize the cursor at 0
    db.cursor = 0;
    // and then alloc a pointer of sz maxSZ for all the Person (pointer to struct)
    db.data = PersonAlloc(maxSZ);
    return db;
}

// small function for printing the Database 
void printDb(Database db){
    printf("[\n");
    for(int i=0;i<db.cursor;i++) 
        printf("\t{\n\t\t\"name\":\"%s\",\n\t\t\"genome\":\"%s\",\n\t}\n size g %d\t\t size s %d  \n",
            db.data[i].name,db.data[i].genome,db.data[i].sizeG,db.data[i].sizeS);
    printf("]\n");
    return;
}

// simple function for print the solution
void printSolution(Problem *P){
    int j=0;
    for(int i = 0;i<P->db.size;i++){
        if(P->db.data[i].cursorS != 0){
                printf("%s: shift=%d\n",P->db.data[i].name,P->db.data[i].solutions[0]);
                j++;
        }
    }
    printf("%d match%s found.\n",j, j == 1 ? "":"es");
    return;
}

// free all pointers in Person p 
void freePerson(Person p){
    free(p.name);
    free(p.genome);
    if(p.cursorS != 0) free(p.solutions);
    return;
}
// free all the Person and then free the pointer 
void freeDB(Database db){
    for(int i = 0;i<db.size;i++){
        freePerson(db.data[i]);
    }
    free(db.data);
    return;
}
//free pattern pointer 
void freeProblem(Pattern pattern){
    free(pattern.pattern);
    return;
}
void freeBuffer(Buff buffer){
    free(buffer.buffer);
    return;
}



// add a  new Person (or record) to the pointer of all the Person 
void addRecordDB(Database *dbp, Person record){
    // just check if thare are too many people 
    if(dbp->cursor  >=  dbp->size) {
        printf("error too many people");
        exit(EXIT_FAILURE);
    }
    // dbp->data this is the pointer of all the Person 
    dbp->data[dbp->cursor] = record;
    // then add 1 to the cursor to remember at what index we are  
    dbp->cursor+=1;
    return;
}


 // this function create a new Person
void parsePerson (Buff *buffer, Database *dbp){
    Person record;
    // alloc the name and genome at the length of cp which is the pattern 
    record.name = charAlloc(strlen(buffer->buffer));
    record.genome = charAlloc(strlen(buffer->buffer));
    // translates to parse whatever untill : then : then another string
    char prototype[9] = "%[^:]:%s";
    if (sscanf(buffer->buffer, prototype , record.name, record.genome) != 2) exit(EXIT_FAILURE);
    // initialize the sizeG at the length of the genome 
    record.sizeG = strlen(record.genome);
    // initilize the sizeS at 1 
    record.sizeS = 1;
    // initialize the cursorS at 0
    record.cursorS = 0;
    // then add the new person at the pointer of all the Person
    addRecordDB(dbp,record);
    return;
}



// this function just set a solution
void setSolution(Problem *P,int row,int col){
    //firstly check if the solutions pointer is a null pointer and in case alloc it 
    if(P->db.data[row].cursorS == 0){
        //printf("alloc solutions");
        P->db.data[row].solutions = intAlloc(P->db.data[row].sizeS);
    }
    // then check if it need a realloc 
    if(P->db.data[row].cursorS > P->db.data[row].sizeS-1){
        //printf("realloc solutions");
        P->db.data[row].sizeS *= 2;
        P->db.data[row].solutions = (int *) realloc(P->db.data[row].solutions,P->db.data[row].sizeS);
    } 
    // at the end just add the solution to the pointer of solutions 
    P->db.data[row].solutions[P->db.data[row].cursorS] = col;
    // and add one to the cursorS 
    P->db.data[row].cursorS += 1;
    return;
}

// set some parameter for the Problem struct 
void setProblem(Problem *P,Database db){
    // append the db 
    P->db = db;
    // initialize the cursor
    P->db.cursor = 0;
    //printf("length pattern");
    //printf("%d\n",strlen(P->pattern));
    // inizitalize sizeP at length of the pattern 
    P->pattern.size = strlen(P->pattern.pattern)-1;
    return;
}

// this function actually solve the problem 
void solveProblem(Problem *P){
    int ncheck;
    // loop every possible Person so i rappresent our Person
    for(int i=0 ; i < P->db.size ; i++){
        //printf("\tloop n%d\n",i);
        // then loop on every single char of the genome so j is our genome char  
        for(int j=0; j <= (P->db.data[i].sizeG) - (P->pattern.size)+1;j++){
            // if we already found a solution just break we need just one 
            if(P->db.data[i].cursorS!=0) break;
            ncheck = 0;
            //printf("\t\t\tloop n j %d\n",j);
            // loop on every single char of the pattern so k is our pattern char 
            for(int k=0;k<P->pattern.size;k++) {
                //printf("\t\tloop n k %d\t\t%d\n",k,P->pattern.size);
                // if the j + k goes out of the genome size break 
                if(j+k >= P->db.data[i].sizeG) break;
                // check if the pattern char match with the genome char 
                if(P->pattern.pattern[k] == P->db.data[i].genome[j+k]) {
                    ncheck++;
                    // if we have checked all the pattern and it all char matches we can set the solution
                    if(ncheck==P->pattern.size) setSolution(P,i,j);
                }else break;
            }
        }
    }
    return;
}

//  start parsing the stdin
Database parseDB(){
    // scan how many people you want 
    int sz=0;
    scanf("%d",&sz);
    scanf("\n");
    //then initialize the database 
    Database db = makeDB(sz);
    //create a struct Buff 
    for(int i=0;i<sz;i++){
        Buff buffer = makeBuff();
        do {
            if(buffer.cursor >= buffer.size){
                buffer.size*=2;
                buffer.buffer = reAllocCharPointer(buffer.buffer,buffer.size);
            } 
            buffer.buffer[buffer.cursor] = getchar();
            buffer.cursor+=1;
        }while(buffer.buffer[buffer.cursor-1] != '\n');
        parsePerson(&buffer,&db);
        freeBuffer(buffer);
    }
    return db;
}


Pattern parsePattern(){
    Pattern pattern = makePattern();
    do {
        if(pattern.cursor >= pattern.size){
            pattern.size*=2;
            pattern.pattern = reAllocCharPointer(pattern.pattern,pattern.size);
        } 
        pattern.pattern[pattern.cursor] = getchar();
        pattern.cursor+=1;
    }while(pattern.pattern[pattern.cursor-1] != '\n');
    return pattern;
}

// this is the core function 
void structManager(){
    Pattern pattern = parsePattern();
    // make the Problem
    Problem P = makeP(pattern);
    // make and parse the Database 
    Database db = parseDB();
    //printDb(db);
    // set the Problem 
    setProblem(&P,db);
    // solve the Problem 
    solveProblem(&P);
    // print the solution 
    printSolution(&P);
    // free all the possible pointers
    freeDB(db);
    freeProblem(pattern);
    return;
}




 
// the main just call the core function
int main (int argc, char** argv){
    structManager();
    return 0;
}
