//Note to next session:
//Working on Chapter 6.6 Table Lookup

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist { //table entry
    struct nlist* next; //next entry in train
    char* name; //defined name
    char* defn; //replacement text
};

#define HASHSIZE 11

static struct nlist *hashtab[HASHSIZE];

//hash: form hash value for string s
unsigned hash(char* s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) 
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

//lookup: look for s in hashtab
struct nlist* lookup(char* s) {
    struct nlist* np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist* np;
char* myStrdup(char*);

//install: put (name, defn) in hashtab
struct nlist* install(char* name, char* defn) {
    struct nlist* np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { //not found
        np = (struct nlist*) malloc(sizeof(*np));
        if (np == NULL || (np->name = myStrdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else //already there
        free((void*) np->defn); //free previous defn
    if ((np->defn = myStrdup(defn)) == NULL)
        return NULL;
    return np;
}

//strdup: make a duplicate of s
char* myStrdup(char* s) {
    char* p;

    p = (char *) malloc(strlen(s) + 1); //+1 for '\0'
    if (p != NULL)
        strcpy(p,s);
    return p;
}

int main() {
    char* name = "David";
    char* defn1 = "Handsome Gent";
    char* defn2 = "Immaculate Fellow";

    install(name, defn1);
    struct nlist* myDef = lookup("David");
    printf("Every time you hear %s, what you should really hear is %s\n", myDef->name, myDef->defn );
    install(name, defn2);
    printf("Every time you hear %s, what you should really hear is %s\n", myDef->name, myDef->defn );

    printf("It didn't shit itself :) \n");
}

//2.9 Exercises : DONE
//2.10 Exercises : PARTIALLY DONE
//Exercises to return to
//3.3 else-if statements 
//sorting array algorithm : DONE
//binary search algorithm
//hexdump
//3.5 shell sort
//3.5 exercises
//3.5 reverse function
//4.1 rewrite strindex(s,t)
//4.2 rewrite atof to handle sci notation : DONE
//4.3 add modulus and negative numbers : DONE
//4.4 add peek, swapping, and stack clearing methods: DONE
//4.5 add access to library functions sin, exp, and pow
//4.6 add commands for having variables
//4.7 write a routine ungets(s)
//4.10 rewrite the calculator to use getline
//4.11 modify getop so that it doesnt use ungetch HINT: use an internal static variable
//4.12 write a recursive version of itoa
//4.13 write function that recursively reverses a string in place
//5.2 write getfloat, What type does getflow return as its function value?
//5.3 write a pointer version of the function strcat shown in Chapter 2 (DONE)
//5.4 write the function strend(s,t), which returns 1 is the string t occurs at the end of the string s, and 0 otherwise
//5.6 rewrite functions from earlier chapter with pointers instead of indexing
//5.10 rewrite the program expr, which can calculate a polish expression from the command line
//5.11 write the program tail, which prints the last n lines of input and can handle an optional argument "-n"
//5.14 to 5.17 adding various command line flags for futher functionality
//6.3 write a cross referencer that prints a list of all words in a document, and for each word, a list of the line numbers where it occurs
//6.4 write a program that prints the distinct worrds in its input sorted into decreasing order of frequency