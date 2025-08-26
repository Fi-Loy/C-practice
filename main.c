//Note to next session:
//Working on Chapter 4.2 Functions Returning Non-Integers
/* Chapter 4.2 Example
not only must a function have its return type declared, the 
calling routine must know what type the function is going
to give. what this means is that if we compile the function
separately from the main file, and the main file expects an
int from the function, we get bad juju.
*/

#include <ctype.h>
#include <stdio.h>

//atof: convert string s to double
double atof(char s[]){

    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power; 
}

int main(){
    char number[] = "-12034";

    printf("%f", atof(number));
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
//4.2 rewrite atof to handle sci notation