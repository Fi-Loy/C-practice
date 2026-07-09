//Note to next session:
//Working on Chapter 5.5: Character Pointers and Functions

#include <stdio.h>

//strcopy: copy t to s; array subscript version
void strcopyA(char* s, char* t) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0') 
        i++;
}

//strcopy: copy t to s; pointer version
void strcopyP(char* s, char* t) {
    int i;
    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

//strcopy: copy t to s; pointer version 2
void strcopy2(char* s, char* t) {
    while ((*s++ = *t++) != '\0')
        ;
}

//strcopy: copy t to s; pointer version 3
void strcopy3(char* s, char* t) {
    while (*s++ = *t++)
        ;
}

//strcmp: return <0 if s < t, 0 is s == t, >0 if s > t
//Array version
int strcompA(char* s, char* t) {
    int i;

    for (i = 0; s[i] == t[i]; i++) 
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

//strcmp: return <0 if s < t, 0 is s == t, >0 if s > t
//Pointer version
int strcompP(char* s, char* t) {
    for ( ; *s == *t; s++, t++)
        if ( *s == '\0')
            return 0;
    return *s - *t;
} 

int main() {
    char string1[] = "when I was young, it seemed that life was so wonderful";
    char copy0[55];
    char copy1[55];
    char copy2[55];
    char copy3[55];
    

    strcopyA(copy0, string1);
    printf("%s\n", copy0);
    strcopyP(copy1, string1);
    printf("%s\n", copy1);
    strcopy2(copy2, string1);
    printf("%s\n", copy2);
    strcopy3(copy3, string1);
    printf("%s\n", copy3);

    char string2[] = "which is greater?";
    char string3[] = "this string, or above?";

    printf("%d\n", strcompA(string2, string3));
    printf("%d\n", strcompP(string2, string3));
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
//5.3 write a pointer version of the function strcat shown in Chapter 2
//5.4 write the function strend(s,t), which returns 1 is the string t occurs at the end of the string s, and 0 otherwise
//5.5 write version of the library functions strncopy, strncat, and strncmp
//5.6 rewrite functions from earlier chapter with pointers instead of indexing