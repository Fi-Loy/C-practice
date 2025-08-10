//Note to next session:
//Working on Chapter 3.7 Break and Continue
//Chapter 2.9: Exercise 2-8. 
/* Write a function rightrot(x,p,n) that returns the
value of the integer x rotated to the right by n
positions
*/

#include <stdio.h>
#include <math.h>

unsigned getbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main(){

    int x = 143014; 

    //Expected result 143014 -> 107242
    printf("%d -> %d\n", x, rightrot(x,5));

} 

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n); //(x,4,3)
}

unsigned rightrot(unsigned x, int n){
    /* Probably not the best implementation,
    fun tho. would be worth seeing how this
    is done properly in the future. */
    int firstPlace = log2(x);
    while(n > 0){
        x = ((x & 1) << firstPlace) | (x >> 1);
        n--;
    }
    return x;
}

//2.9 Exercises : DONE
//2.10 Exercises
//Exercises to return to
//3.3 else-if statements
//sorting array algorithm
//binary search algorithm
//hexdump
//3.5 shell sort
//3.5 exercises
//3.5 reverse function