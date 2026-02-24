/**
 * @file act2_-_coords_struct_stub.c
 * @brief A program demonstrating the use of structs for coordinate manipulation
 */

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 21 // 21x21 grid for -10 to +10 range

/**
 * @brief Structure to represent a 2D point
 */
typedef struct _point {
    int x;
    int y;
} Point;

/**
 * @brief Structure to represent a grid
 */
typedef struct _grid {
    char **grid;
    int width;
    int height;
} Grid;

// Function prototypes
char **initialize_grid(void);
void draw_grid(char **grid);
void add_point(char **grid, Point p);

// TODO: Implement these functions
Point move_point(Point p, Point dp);
Point reflect_point(Point p, char axis);
Point swap_coords(Point p);

int main(void) {
    // This creates a 20 x 20 grid (-10 -> +10, plus 1 row & column used for axes)
    char **grid = initialize_grid();
    
    // Initial point at (-7, 3)
    Point p = {.x = -7, .y = 3};
    printf("Original point: (%d, %d)\n", p.x, p.y);
    
    // Add and display the original point
    add_point(grid, p);
    draw_grid(grid);
    
    // TODO: Uncomment and test each function after implementing it
    
    /* Test move_point function
    Point dp = {.x = 2, .y = 3};  // Delta to move by
    Point q = move_point(p, dp);
    printf("After moving by (%d, %d): (%d, %d)\n", dp.x, dp.y, q.x, q.y);
    add_point(grid, q);
    draw_grid(grid);
    */
    
    /* Test swap_coords function
    Point q2 = swap_coords(p);
    printf("After swapping coordinates: (%d, %d)\n", q2.x, q2.y);
    add_point(grid, q2);
    draw_grid(grid);
    */
    
    /* Test reflect_point function
    Point q3 = reflect_point(p, 'x');
    printf("After reflecting across X-axis: (%d, %d)\n", q3.x, q3.y);
    add_point(grid, q3);
    draw_grid(grid);
    
    Point q4 = reflect_point(p, 'y');
    printf("After reflecting across Y-axis: (%d, %d)\n", q4.x, q4.y);
    add_point(grid, q4);
    draw_grid(grid);
    */
    
    return 0;
}

/**
 * @brief Move a point by the provided delta
 *
 * This function creates a new point by adding the delta values to the original point.
 *
 * @param p The original point
 * @param dp The delta to add (contains x and y components)
 * @return Point A new point representing p + dp
 */
Point move_point(Point p, Point dp) {
    // TODO: Create and return a new point by adding dp to p
    // Hint: You need to add dp.x to p.x and dp.y to p.y
    
    // Placeholder return to make the program compile
    Point newp = {0, 0};
    return newp;
}

/**
 * @brief Reflects a point across an axis
 *
 * This function creates a new point that is the reflection of the original point
 * across either the x-axis or the y-axis.
 *
 * @param p The point to reflect
 * @param axis The axis to reflect across ('x' or 'y')
 * @return Point A new point representing the reflection of p
 */
Point reflect_point(Point p, char axis) {
    // TODO: Create and return a new point that is the reflection of p across the specified axis
    // Hint: For x-axis reflection, only y coordinate changes sign
    // Hint: For y-axis reflection, only x coordinate changes sign
    
    // Placeholder return to make the program compile
    Point newp = {0, 0};
    return newp;
}

/**
 * @brief Swaps the x and y coordinates of a point
 *
 * This function creates a new point with the x and y coordinates swapped.
 *
 * @param p The original point
 * @return Point A new point with x and y coordinates swapped
 */
Point swap_coords(Point p) {
    // TODO: Create and return a new point with p's x and y coordinates swapped
    // Hint: The new point should have x=p.y and y=p.x
    
    // Placeholder return to make the program compile
    Point newp = {0, 0};
    return newp;
}

/**
 * @brief Initialises the grid with axes
 *
 * @return char** 2D array representing the initialised grid
 */
char **initialize_grid(void) {
    char **grid = (char **)malloc(GRID_SIZE * sizeof(char *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (char *)malloc(GRID_SIZE * sizeof(char));
    }

    // Fill with spaces
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = ' ';

    // Draw x and y axes
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i][10] = '|'; // Y-axis
        grid[10][i] = '-'; // X-axis
    }

    grid[10][10] = '+'; // Origin (0,0)

    return grid;
}

/**
 * @brief Draws the grid
 *
 * @param grid The 2D array representing the grid
 */
void draw_grid(char **grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++)
            printf("%c ", grid[i][j]);
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Adds a point to the grid
 *
 * @param grid The 2D array representing the grid
 * @param p The point to add
 */
void add_point(char **grid, Point p) {
    // Adjust coordinates for grid's origin (10, 10)
    int plot_x = p.x + 10; // Offset the x-coordinate by 10 to fit grid range
    int plot_y = 10 - p.y; // Offset the y-coordinate by 10 and invert it for grid display

    // Check bounds to make sure point stays within grid
    if (plot_x >= 0 && plot_x < GRID_SIZE && plot_y >= 0 && plot_y < GRID_SIZE) {
        grid[plot_y][plot_x] = '*'; // Place the point on the grid
    }
}
