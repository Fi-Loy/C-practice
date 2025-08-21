//Note to next session:
//Working on Chapter 4.1 Basics of Functions
//Chapter 2.10: Exercise 2-9. 
/* Sorting Array algorithm
*/

int sort(int array[], int length);

#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(){
    int myArray[] = {12, 2423, 34523, 56536, 44, 14, 6, 761, 2, 4, 68, 983, 3};

    sort(myArray, 13);

    for(int i = 0; i < 13; i++){
        printf("%d\n", myArray[i]);
    }
    
}

int sort(int array[], int length){
    //bubble sort
    int temp;

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }  
        }
    }
    
}

//2.9 Exercises : DONE
//2.10 Exercises : PARTIALLY DONE
//Exercises to return to
//3.3 else-if statements 
//sorting array algorithm
//binary search algorithm
//hexdump
//3.5 shell sort
//3.5 exercises
//3.5 reverse function