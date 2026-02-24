# Activity 2: Coordinates with Structs 

This exercise introduces you to using structs in C, refactoring our previous coords example, for more organised and 
maintainable code. 
You'll be working with coordinate points in a 2D plane, implementing three transformation functions on these points.

## Learning Objectives

After completing this exercise, you should be able to:

1. Define and use structs in C
2. Access struct members using the dot notation
3. Pass structs to functions
4. Return structs from functions
5. Create functions that operate on custom data types

## The Exercise

In this exercise, you'll work with a `Point` struct that represents a 2D coordinate. 
You'll implement three functions that perform transformations on points:

1. `move_point`: Move a point by adding x and y deltas
2. `reflect_point`: Reflect a point across the x or y axis
3. `swap_coords`: Swap the x and y coordinates of a point

The program visualises these transformations on a 2D grid displayed in the console.

## The Point Struct

The `Point` struct is defined as:

```c
typedef struct _point {
    int x;  // x-coordinate
    int y;  // y-coordinate
} Point;
```

You can create a Point and access its members using dot notation:

```c
Point p = {.x = 3, .y = 4};  // Initialization using designated initializers
printf("Point coordinates: (%d, %d)\n", p.x, p.y);
```

## Your Tasks

Open `coordinates_struct.c` and implement the following functions:

### 1. Move Point Function

```c
Point move_point(Point p, Point dp);
```

This function should:
- Take a point `p` and a delta `dp`
- Return a new point where x = p.x + dp.x and y = p.y + dp.y

### 2. Reflect Point Function

```c
Point reflect_point(Point p, char axis);
```

This function should:
- Take a point `p` and an axis character ('x' or 'y')
- If axis is 'x', return a new point (p.x, -p.y)
- If axis is 'y', return a new point (-p.x, p.y)

### 3. Swap Coordinates Function

```c
Point swap_coords(Point p);
```

This function should:
- Take a point `p`
- Return a new point where x = p.y and y = p.x

## Testing Your Implementation

The `main()` function contains commented-out test code for each of your functions. 
After implementing each function, uncomment the corresponding test section to verify it works correctly.

## Further Concepts (For work out of class)

While not required for this exercise, consider these advanced struct concepts:

1. **Struct Pointers**: You can use pointers to structs, accessing members with the arrow operator (`->`) instead of the dot (`.`).

```c
Point *pPtr = &p;
printf("X coordinate: %d\n", pPtr->x);  // Same as (*pPtr).x
```

2. **Nested Structs**: Structs can contain other structs as members.

```c
typedef struct {
    Point start;
    Point end;
} Line;
```

3. **Arrays of Structs**: You can create arrays of structs to represent collections of similar objects.

```c
Point points[10];  // Array of 10 Point structs
```

## Activity Requirements

Your solution should:
1. Implement all three functions correctly
2. Be well-commented
3. Demonstrate proper understanding of struct usage
4. Pass all the test cases in main()
