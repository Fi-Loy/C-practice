//Note to next session:
//Working on Chapter 7.4 Formatted Input - Scanf

#include <stdio.h>
#include "hmHelpers.c"
//main() { //rudimentary calculator
//    double sum, v;
//
//    sum = 0;
//    while(scanf("%lf", &v) == 1)
//        printf("\t%.2f\n", sum += v);
//    return 0;
//}

main() { //read date

    char line[20];
    char monthname[20];
    int day, month, year;

    while(myGetline(line, sizeof(line)) > 0) {
        if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line); // 25 Dec 1988 form
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line); //mm/dd/yy form
        else
            printf("Invalid: %s\n", line);
    }
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
//7.1 Write a program that converts upper to lower case or vice versa depending on the name in argv
//7.3 Revise minprintf to handle more of the other facilities of printf
//7.4 Write a private version of scanf similar to minprintf
//5.5 Rewrite the postfix calculator from Chapter 4 to use scanf or sscanf