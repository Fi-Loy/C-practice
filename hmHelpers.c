//Library for homemade helper functions
#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */ 
#define MAXLINES 5000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */ 
static char *allocp = allocbuf;  /* next free position */ 

char *alloc(int n)    /* return pointer to n characters */ 
{ 
    if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */ 
        allocp += n; 
        return allocp - n; /* old p */ 
    } else      /* not enough room */ 
        return 0; 
} 

void afree(char *p)  /* free storage pointed to by p */ 
{ 
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) 
        allocp = p; 
} 

/* getline:  get line into s, return length */ 
int myGetline(char s[], int lim) 
{ 
    int c, i; 
    i = 0; 
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
        s[i++] = c; 
    if (c == '\n') 
        s[i++] = c; 

    s[i] = '\0'; 
    return i;
}

//readlines: read input lines
int readlines(char *lineptr[], int maxlines) 
{ 
    int len, nlines; 
    char *p, line[MAXLINES]; 
    nlines = 0; 
    while ((len = myGetline(line, MAXLINES)) > 0) 
        if (nlines >= maxlines || (p = alloc(len)) == NULL) 
            return -1; 
        else { 

            line[len-1] = '\0';  /* delete newline */ 
            strcpy(p, line); 
            lineptr[nlines++] = p; 
        } 
    return nlines; 
} 

/* writelines:  write output lines */ 
void writelines(char *lineptr[], int nlines) 
{ 
    int i; 
    for (i = 0; i < nlines; i++) 
        printf("%s\n", lineptr[i]); 
} 