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
    char *pattern;
    int sizeP;
}Problem;



//declaration of the headers 

void *safeMalloc (int sz);

char *charAlloc (int n);

int *intAlloc (int n);

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

void freePerson(Person p){
    free(p.name);
    free(p.genome);
    if(p.cursorS != 0) free(p.solutions);
    return;
}

void freeDB(Database db){
    for(int i = 0;i<db.size;i++){
        freePerson(db.data[i]);
    }
    free(db.data);
    return;
}

void freeProblem(Problem P){
    free(P.pattern);
    return;
}

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


int *intAlloc (int n){
    return safeMalloc(sizeof(int)*n);
}

// int **matrixIntAlloc(int m,int n){
//     int **c = intAlloc(m);
//     for (int i = 0; i < m; i++ ) c[i]=safeMalloc(n);
//     return c;
// }




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
    record.sizeG = strlen(record.genome);
    record.sizeS = 1;
    record.cursorS = 0;
    addRecordDB(dbp,record);
    return;
}

void printDb(Database db){
    printf("[\n");
    for(int i=0;i<db.cursor;i++) 
        printf("\t{\n\t\t\"name\":\"%s\",\n\t\t\"genome\":\"%s\",\n\t}\n size g %d\t\t size s %d  \n",
            db.data[i].name,db.data[i].genome,db.data[i].sizeG,db.data[i].sizeS);
    printf("]\n");
    return;
}

void parseDB(Database *dbp){
    int sz=0;
    scanf("%d",&sz);
    dbp->size = sz;
    char buf[11000];
    char buf1[11000];
    for(int i=0;i<sz;i++){
        scanf("%s%s",buf,buf1);
        strncat(buf," ",10000);
        strncat(buf,buf1,10000);
        parsePerson(buf ,dbp);
    }    
    return;
}



void setSolution(Problem *P,int row,int col){
    if(P->db.data[row].cursorS == 0){
        //printf("alloc solutions");
        P->db.data[row].solutions = intAlloc(P->db.data[row].sizeS);
    }
    if(P->db.data[row].cursorS > P->db.data[row].sizeS-1){
        //printf("realloc solutions");
        P->db.data[row].sizeS *= 2;
        P->db.data[row].solutions = (int *) realloc(P->db.data[row].solutions,P->db.data[row].sizeS);
    } 
    P->db.data[row].solutions[P->db.data[row].cursorS] = col;
    P->db.data[row].cursorS += 1;
    return;
}


void setProblem(Problem *P,Database db){
    P->db = db;
    P->db.cursor = 0;
    //printf("length pattern");
    //printf("%d\n",strlen(P->pattern));
    P->sizeP = strlen(P->pattern);
    return;
}


void solveProblem(Problem *P){
    int ncheck;
    for(int i=0;i<P->db.size;i++){
        //printf("\tloop n%d\n",i);
        for(int j=0; j <= (P->db.data[i].sizeG) - (P->sizeP);j++){
            if(P->db.data[i].cursorS!=0) break;
            ncheck = 0;
            //printf("\t\t\tloop n j %d\n",j);
            for(int k=0;k<P->sizeP;k++) {
                //printf("\t\t\t\tloop n k %d\n",k);
                if(j+k >= P->db.data[i].sizeG) break;
                if(P->pattern[k] == P->db.data[i].genome[j+k]) {
                    ncheck++;
                    if(ncheck==P->sizeP) setSolution(P,i,j);
                }else break;

            }
        }
    }
    return;
}

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

void structManager(){
    char *pattern = charAlloc(12048);
    scanf("%s",pattern);
    Problem P = makeP(pattern);
    printProblem(P);
    Database db = makeDB(12048);
    parseDB(&db);
    printDb(db);
    setProblem(&P,db);
    solveProblem(&P);
    //printf("solved\n");
    printSolution(&P);
    freeDB(db);
    freeProblem(P);
    return;
}






int main (int argc, char** argv){
    structManager();
    return 0;
}