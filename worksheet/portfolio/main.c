
#include <stdio.h>
#include <stdbool.h>

#include "shapes.h"

int main( void ) {

    Point p1 = makePoint(-1,2);
    Point p2 = makePoint(4,3);
    Point p3 = makePoint(5,-2);

    Triangle t = makeTriangle(p1, p2, p3);
    printf("%f\n", triangleArea(t));
    
    // test your code by calling the functions and printing the output 
    
    return 0;
}