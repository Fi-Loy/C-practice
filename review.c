#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double myExp(double b, int e);

//rudimentary calculator
main() {
    double sum, atof(char[]);
    char line[MAXLINE];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
   
}

//getline: get line into s, return length
int mygetline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

//exp: raises b to the power of e
double myExp(double b, int e) {
    double r = 1.0;
    if (e == 0)
        return 1;
    else if (e > 0)
        for(; e > 0; e--)
            r *= b;
    else
        for(; e < 0; e++)
            r /= b;
    return r;
}

//atof: convert string s to double
double atof(char s[]) {
    double val, power;
    double exp = 1.0;
    int i, sign, e;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        char expStr[MAXLINE];
        i++; 
        for (int j = 0; s[i] != '\n'; i++, j++) 
            expStr[j] = s[i];
        int e = atof(expStr);
        exp = myExp(10, e);
    }
    return sign * val * exp / power;
}

