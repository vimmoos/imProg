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


typedef struct Person{
    char *name;
    char *genome;
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
}Problem;
void *safeMalloc (int sz)
char *charAlloc (int n)
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


Person *PersonAlloc(int sz);


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

void printProblem(Problem P){
    printf("\t%s\n",P.pattern);
    return;
}


int main (int argc, char** argv){
    char *pattern = charAlloc(256);
    scanf("%s",pattern);
    Problem P = makeP(pattern);
    // printProblem(P);
    Database db = makeDB(320);
    parseDB(&db);
    // printDb(db);
    return 0;
}