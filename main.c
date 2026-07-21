//Note to next session:
//Working on Chapter 6.2 Structures and Functions

#include <stdio.h>
#define XMAX 360
#define YMAX 200

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

//makepoint: make a point from x and y components
struct point makepoint(int x, int y) { 
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

//addpoints: add two points
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p1.y;
    return p1;
}

//ptInRect: return 1 if p in r, 0 elsewise
int ptInRect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x 
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

//canonrect: cononicalize coordinates of rectangle
struct rect canonrect(struct rect r) {
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);

    return temp;
}

int main() {
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0,0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                       (screen.pt1.y + screen.pt2.y)/2);

    printf("I want to stop before origin is called\n");
    struct point origin = {0,0}, *pp;
    struct point corner = {9,9};
    struct point sample = {3,5};
    struct rect rect = {origin, corner};
    rect = canonrect(rect);

    printf("The point is inside the rectangle: %s\n", ptInRect(sample,rect) ? "true.": "false.");
    printf("p1: (%d, %d)\n", sample.x, sample.y);
    printf("p2: (%d, %d)\n", corner.x, corner.y);
    printf("p1 + p2: (%d, %d)\n",(addpoint(sample, corner)).x, (addpoint(sample, corner)).y);

    pp = &origin;
    printf("origin is (%d, %d)\n", pp->x, pp->y);

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