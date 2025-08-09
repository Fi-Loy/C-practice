//Note to next session:
//Working on Chapter 3.6 Loops - Do While
//Chapter 2.9: Exercise 2-6. 
/* Write a function setbits(x,p,n,y) that returns x with
** with the n bits that begin at position p set to the 
** rightmost n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main(){

    int x = 143013; //143013 -> 141989

    printf("%d -> %d\n", x, setbits(x,7,4,13));

} 

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n); //(x,4,3)
}

unsigned setbits(unsigned x, int p, int n, int y){
    int getSection = getbits(x, p, n);

    return (x | (~(~0 << n) << (y-n+1))) & (~(~(~0 << n) << (y-n+1)) | (getSection << (y-n+1)));
    //works, its ugly, but it works
    //*it works for this instance, haven't tested any other case*
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