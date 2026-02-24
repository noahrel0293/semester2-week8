/**
 * @file student_record.c
 * @brief Implementation of a student record management system using structures
 * 
 * This program demonstrates the use of structures in C to manage student data
 * including personal information and module marks.
 */

#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define NUM_MODULES 3

/**
 * @brief Structure to represent a student
 */
typedef struct {
    char name[NAME_LENGTH];  // Student's name
    int id;                  // Student's ID number
    float marks[NUM_MODULES]; // Marks for three modules
} Student;

/**
 * @brief Calculate the average mark for a student
 * 
 * @param student The student whose average mark is to be calculated
 * @return float The average mark
 */
float calculate_average(Student student) {
    // TODO: Implement this function to calculate and return the average
    // of the three module marks
    
    return 0.0; // Placeholder return value
}

/**
 * @brief Display student information including name, ID, marks, and average
 * 
 * @param student The student whose information is to be displayed
 */
void display_student(Student student) {
    // TODO: Implement this function to display student information
    // Format: Name, ID, individual marks, and average mark
}

/**
 * @brief Update student name
 * 
 * @param student Pointer to the student whose name is to be updated
 * @param new_name The new name for the student
 */
void update_name(Student *student, const char *new_name) {
    // TODO: Implement this function to update the student's name
    // Remember to use strncpy to avoid buffer overflow
}

/**
 * @brief Update a specific module mark
 * 
 * @param student Pointer to the student whose mark is to be updated
 * @param module_index The index of the module to update (0, 1, or 2)
 * @param new_mark The new mark
 * @return int 1 if successful, 0 if module_index is invalid
 */
int update_mark(Student *student, int module_index, float new_mark) {
    // TODO: Implement this function to update a specific module mark
    // Remember to validate the module_index
    
    return 0; // Placeholder return value
}

int main( void ) {
    // TODO: Create and initialise a student variable with sample data
    // Example: name = "John Smith", id = 12345, marks = {75.0, 68.5, 81.0}
    
    Student student;
    
    // TODO: Calculate and display the average mark
    
    // TODO: Update the student's name to "Jane Smith" and the third module mark to 92.5
    
    // TODO: Display the updated student information
    
    return 0;
}