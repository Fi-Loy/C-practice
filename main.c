//Note to next session:
//Working on Chapter 3.7 Break and Continue
//Chapter 2.9: Exercise 2-7. 
/* Write a function invert(x,p,n) that returns x with
** with the n bits that begin at position p inverted
this is a change for testing
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned invert(unsigned x, int p, int n);

int main(){

    int x = 143014; 

    //Expected result 143014 -> 143001
    printf("%d -> %d\n", x, invert(x,10,7));

} 

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n); //(x,4,3)
}

unsigned invert(unsigned x, int p, int n){
    /* Exercise takeaway: bit shifting by a negative
    numbers is undefined in C, and will cause bugs.
    Creating the mask with a bit length longer than
    the position will lead to such errors
    */
    int mask = (~(-1 << n) << (p-n+1));
    return ~(mask & x) & (mask | x);
}

//2.9 Exercises
//2.10 Exercises
//Exercises to return to
//3.3 else-if statements
//sorting array algorithm
//binary search algorithm
//hexdump
//3.5 shell sort
//3.5 exercises
//3.5 reverse function