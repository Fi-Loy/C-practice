//Note to next session:
//Working on Chapter 6.5 Self-referential Structures

struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char*, int);

//word frequency count
int main() {
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

struct tnode* talloc(void);
char* myStrdup(char*);

//addtree: add a node with w, at or below p
struct tnode* addtree(struct tnode *p, char* w) {
    int cond;

    if (p == NULL) { //a new word has arrived
        p = talloc(); //make a new node
        p->word = myStrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++; //repeated word
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

//treeprint: in-order print of tree p
void treeprint(struct tnode* p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>
//talloc: make a tnode
struct tnode *talloc(void) {
    return (struct tnode*) malloc(sizeof(struct tnode));
}

//strdup: make a duplicate of s
char* myStrdup(char* s) {
    char* p;
    
    p = (char*) malloc(strlen(s) + 1); //+1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}

#include "hmHelpers.c"

/* getword:  get next word or character from input */ 
int getword(char *word, int lim) 
{ 
    int c, getch(void); 
    void ungetch(int); 
    char *w = word; 
    while (isspace(c = getch())) 
        ; 
    if (c != EOF) 
        *w++ = c; 
    if (!isalpha(c)) { 
        *w = '\0'; 
        return c; 
    } 
    for ( ; --lim > 0; w++) 
        if (!isalnum(*w = getch())) { 
            ungetch(*w); 
            break; 
        } 
    *w = '\0'; 
    return word[0]; 
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