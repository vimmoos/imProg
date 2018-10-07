#ifndef ARRLIB_H
#define ARRLIB_H

void *safeMalloc (int sz);

char *charAlloc (int n);

int *intAlloc (int n);

int *reAllocIntPointer(int *p,int size);

char *reAllocCharPointer(char *p,int size);

#endif
