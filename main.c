//Note to next session:
//Working on Chapter 4 - Functions and Program Structure
//Chapter 2.10: Exercise 2-9. 
/* In a two's compliment system, x &= (x-1) deletes the 
rightmost 1-bit in x. Explain why. Use this observation 
to write a faster version of bitcount.

Explanation: it deletes the rightmost bit because if its
odd, then removing 1 makes if the number is even, then 
removing 1 makes it odd, but anding it with an even number
removes the 1 at the end

not going to do the exervise cause I have no idea how to 
make it faster using this knowledge
*/

#include <stdio.h>

unsigned bitcount(unsigned x);

int main(){

    int x = 143014; 

    //Expected result 143014 -> 107242
    printf("number: %d \nnumber of 1s in its bit rep: %d", x, bitcount(x));

} 

unsigned bitcount(unsigned x){
    int b;
    for(b = 0; x != 0; x >>= 1)
        if(x & 01)
            b++;
    return b;
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