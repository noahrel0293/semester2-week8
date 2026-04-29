
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "shapes.h"

// complete other functions below
// - start with stubs as above
// - compile regularly to test syntax
// - test functions by calling them from main()
Point makePoint( float x, float y ){
    Point aPoint = {
        .x = x,
        .y = y
    };
    return aPoint;
}

Line makeLine( Point p1, Point p2 ){
    Line aLine = {
        .p[0] = p1,
        .p[1] = p2
    };
    return aLine;
} 

Triangle makeTriangle( Point p1, Point p2, Point p3 ){
    Triangle aTriangle = {
        .p[0] = p1,
        .p[1] = p2,
        .p[2] = p3
    };
    return aTriangle;
}

float lineLength( Line l ){
    float xLength = l.p[1].x - l.p[0].x;
    float yLength = l.p[1].y - l.p[0].y;
    float lineLengthSqurd = (xLength * xLength) + (yLength * yLength);
    float lineLngth = sqrt(lineLengthSqurd);
    return lineLngth;
}

float triangleArea( Triangle t ){
    float xLngth;
    float yLngth;
    if(t.p[0].x<=t.p[1].x && t.p[0].x<=t.p[2].x && t.p[1].x>=t.p[2].x){
        xLngth = t.p[1].x - t.p[0].x;
    } else if(t.p[0].x<=t.p[1].x && t.p[0].x<=t.p[2].x && t.p[2].x>=t.p[1].x){
        xLngth = t.p[2].x - t.p[0].x;
    } else if(t.p[1].x<=t.p[0].x && t.p[1].x<=t.p[2].x && t.p[0].x>=t.p[2].x){
        xLngth = t.p[0].x - t.p[1].x;
    } else if(t.p[1].x<=t.p[0].x && t.p[1].x<=t.p[2].x && t.p[2].x>=t.p[0].x){
        xLngth = t.p[2].x - t.p[1].x;
    } else if(t.p[2].x<=t.p[0].x && t.p[2].x<=t.p[1].x && t.p[0].x>=t.p[1].x){
        xLngth = t.p[0].x - t.p[2].x;
    } else if(t.p[2].x<=t.p[0].x && t.p[2].x<=t.p[1].x && t.p[1].x>=t.p[0].x){
        xLngth = t.p[1].x - t.p[2].x;
    }

    if(t.p[0].y<=t.p[1].y && t.p[0].y<=t.p[2].y && t.p[1].y>=t.p[2].y){
        yLngth = t.p[1].y - t.p[0].y;
    } else if(t.p[0].y<=t.p[1].y && t.p[0].y<=t.p[2].y && t.p[2].y>=t.p[1].y){
        yLngth = t.p[2].y - t.p[0].y;
    } else if(t.p[1].y<=t.p[0].y && t.p[1].y<=t.p[2].y && t.p[0].y>=t.p[2].y){
        yLngth = t.p[0].y - t.p[1].y;
    } else if(t.p[1].y<=t.p[0].y && t.p[1].y<=t.p[2].y && t.p[2].y>=t.p[0].y){
        yLngth = t.p[2].y - t.p[1].y;
    } else if(t.p[2].y<=t.p[0].y && t.p[2].y<=t.p[1].y && t.p[0].y>=t.p[1].y){
        yLngth = t.p[0].y - t.p[2].y;
    } else if(t.p[2].y<=t.p[0].y && t.p[2].y<=t.p[1].y && t.p[1].y>=t.p[0].y){
        yLngth = t.p[1].y - t.p[2].y;
    }
    float lngthsMult = sqrt(xLngth*xLngth) * sqrt(yLngth*yLngth);
    float triArea = lngthsMult / 2.0;
    return triArea;
}

bool samePoint( Point p1, Point p2 ){
    bool returnVal = false;
    Line pointsLine = makeLine(p1, p2);
    float pointsLineLength = lineLength(pointsLine);
    if(pointsLineLength<1.0e-6){
        returnVal = true;
    }
    return returnVal;
}

bool pointInLine( Point p, Line l){
    bool returnVal = false;
    bool p1Val = samePoint(p, l.p[0]);
    bool p2Val = samePoint(p, l.p[1]);
    if(p1Val == true || p2Val == true){
        returnVal = true;
    }
    return returnVal;
}

bool pointInTriangle( Point p, Triangle t ){
    bool returnVal = false;
    bool p1Val = samePoint(p, t.p[0]);
    bool p2Val = samePoint(p, t.p[1]);
    bool p3Val = samePoint(p, t.p[2]);
    if(p1Val == true || p2Val == true || p3Val == true){
        returnVal = true;
    }
    return returnVal;
}