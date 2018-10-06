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

typedef struct Person{
    char *name;
    char *genome;
    int sizeG;
}Person;


typedef struct Database{
    Person *data;
    int size;
    int cursor;
}Database;

typedef struct Problem{
    Database db;
    char *pattern;
    int **solutions;
    int sizeP;
    int cursorS;
    int sizeS;
}Problem;



//declaration of the headers 

void *safeMalloc (int sz);

char *charAlloc (int n);

int **intAlloc (int n);

Person *PersonAlloc(int sz);

Problem makeP(char *cp);

Database makeDB(int maxSZ);

void addRecordDB(Database *dbp, Person record);

void parsePerson (char *cp, Database *dbp);

void printDb(Database db);

void parseDB(Database *dbp);

void printProblem(Problem P);

void setProblem(Problem *P,Database db);

void solveProblem(Problem *P);

void setSolution(Problem *P,int row,int col);

// define functions body

void *safeMalloc (int sz){
    void *p= malloc(sz);
    if(p==NULL){
        printf("error cannot alloc %d",sz);
        exit(EXIT_FAILURE);
    }
    return p;
}


char *charAlloc (int n){
    return safeMalloc(sizeof(char)*n);
}


int **intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

int **matrixIntAlloc(int m,int n){
    int **c = intAlloc(m);
    for (int i = 0; i < m; i++ ) c[i]=safeMalloc(n);
    return c;
}
Problem makeP(char *cp){
    Problem P;
    P.pattern = cp;
    return P;
}

Database makeDB(int maxSZ){
    Database db;
    db.size = maxSZ;
    db.cursor = 0;
    db.data = PersonAlloc(maxSZ);
    return db;
}

void addRecordDB(Database *dbp, Person record){
    if(dbp->cursor  >=  dbp->size) {
        printf("error too many people");
        exit(EXIT_FAILURE);
    }
    dbp->data[dbp->cursor] = record;
    dbp->cursor+=1;
    return;
}


Person *PersonAlloc(int sz){
    return safeMalloc(sizeof(Person)*sz);
}

void parsePerson (char *cp, Database *dbp){
    Person record;
    record.name = charAlloc(strlen(cp));
    record.genome = charAlloc(strlen(cp));
    // translates to parse whatever untill : then : then another string
    char prototype[9] = "%[^:]:%s";
    if (sscanf(cp, prototype , record.name, record.genome) != 2) exit(EXIT_FAILURE);
    addRecordDB(dbp,record);
    return;
}

void printDb(Database db){
    printf("[\n");
    for(int i=0;i<db.cursor;i++) 
        printf("\t{\n\t\t\"name\":\"%s\",\n\t\t\"genome\":\"%s\",\n\t}\n",
            db.data[i].name,db.data[i].genome);
    printf("]\n");
    return;
}

void parseDB(Database *dbp){
    int sz=0;
    scanf("%d",&sz);
    for(int i=0;i<sz;i++){
        char buf[256];
        scanf("%s",buf);
        parsePerson(buf,dbp);
    }    
    return;
}

void setSolution(Problem *P,int row,int col){
    if(P->solutions==NULL) P->solutions = matrixIntAlloc(P->db.size,P->sizeS);
    if(P->cursorS > P->sizeS-1){
        P->sizeS *= 2;
        P->solutions[row] = (int *) realloc(P->solutions[row],P->sizeS);
    } 
    P->solutions[row][P->cursorS] = col;
    P->cursorS += 1 ;
    return;
}


void printProblem(Problem P){
    printf("\t%s\n",P.pattern);
    return;
}


void solveProblem(Problem *P){
    int ncheck;
    P->cursorS = 0;
    for(int i=0;i<=P->db.size;i++){
        for(int j=0;j<P->db.data->sizeG;j++){
            ncheck = 0;
            for(int k=0;k<P->sizeP;k++) {
                if(P->pattern[k] == P->db.data->genome[j+k]) {
                    ncheck++;
                    if(ncheck==P->sizeP) setSolution(P,i,j);
                }

            }
        }
    }
    return;
}


void setProblem(Problem *P,Database db){
    P->db = db;
    P->db.cursor = 0;
    P->db.data->sizeG = strlen(P->db.data->genome);
    P->sizeP = strlen(P->pattern);
    P->sizeS = 1;
    return;
}


void structManager(){
    char *pattern = charAlloc(256);
    scanf("%s",pattern);
    Problem P = makeP(pattern);
    // printProblem(P);
    Database db = makeDB(320);
    parseDB(&db);
    // printDb(db);
    setProblem(&P,db);
    solveProblem(&P);
    printSolution(&P);
    return;
}






int main (int argc, char** argv){
    structManager();
    return 0;
}