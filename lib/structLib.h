#ifndef STRUCTLIB_H

#define STRUCTLIB_H





typedef struct Pattern{
    char* pattern;
    int size;
    int cursor;
}Pattern;

Pattern makePattern();

Pattern parsePattern();

void freePattern(Pattern pattern);

typedef struct Buff{
    char *buffer;
    int size;
    int cursor;
}Buff;

Buff makeBuff();

void freeBuffer(Buff buffer);

//NOTE that struct Person and struct Database are strictly connected 
// do not use Person without Database because there is no make method for Person 
typedef struct Person{
    char *name;
    char *genome;
    int sizeG;
    int *solutions;
    int cursorS;
    int sizeS;
}Person;

void freePerson(Person p);

typedef struct Database{
    Person *data;
    int size;
    int cursor;
}Database;

Database makeDB(int maxSZ);

Person *PersonAlloc(int sz);

Database parseDB();

void freeDB(Database db);

void printDb(Database db);

void addRecordDB(Database *dbp, Person record);

void parsePerson (Buff *buffer, Database *dbp);


typedef struct Problem{
    Database db;
    Pattern pattern;
}Problem;

Problem makeP(Pattern pattern);

void printSolution(Problem *P);

void setSolution(Problem *P,int row,int col);

void setProblem(Problem *P,Database db);

void solveProblem(Problem *P);



#endif







