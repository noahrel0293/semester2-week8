# Activity 1: Simple Modularisation

## Learning Objectives
By the end of this activity, you should be able to:
- Separate a C program into header and implementation files
- Implement proper include guards
- Understand the relationship between interface and implementation
- Compile a multi-file C program

## Background
In this activity, you'll take the Student Record Management program from last week's Structure activity and refactor it into a properly modularised structure. This involves separating the program into three files:

1. **student.h** - Header file containing structure definitions and function declarations
2. **student.c** - Implementation file containing function definitions
3. **main.c** - Main program file that uses the student module

## Starting Code
Below is a reminder of the original, single-file student record program:

```c
/**
 * @file student_record.c
 * @brief Implementation of a student record management system using structures
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
    float sum = 0.0;
    
    // Sum up all the module marks
    for (int i = 0; i < NUM_MODULES; i++) {
        sum += student.marks[i];
    }
    
    // Return the average
    return sum / NUM_MODULES;
}

/**
 * @brief Display student information including name, ID, marks, and average
 * 
 * @param student The student whose information is to be displayed
 */
void display_student(Student student) {
    float average = calculate_average(student);
    
    printf("Student Information:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Module marks: ");
    
    for (int i = 0; i < NUM_MODULES; i++) {
        printf("%.1f", student.marks[i]);
        if (i < NUM_MODULES - 1) {
            printf(", ");
        }
    }
    
    printf("\nAverage mark: %.1f\n", average);
}

/**
 * @brief Update student name
 * 
 * @param student Pointer to the student whose name is to be updated
 * @param new_name The new name for the student
 */
void update_name(Student *student, const char *new_name) {
    // Use strncpy to avoid buffer overflow
    strncpy(student->name, new_name, NAME_LENGTH - 1);
    student->name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
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
    // Validate the module index
    if (module_index < 0 || module_index >= NUM_MODULES) {
        return 0; // Invalid module index
    }
    
    // Update the mark
    student->marks[module_index] = new_mark;
    return 1; // Success
}

int main() {
    // Create and initialise a student variable
    Student student = {
        .name = "John Smith",
        .id = 12345,
        .marks = {75.0, 68.5, 81.0}
    };
    
    // Display original student information
    printf("Original student record:\n");
    display_student(student);
    
    // Calculate and display the average mark
    float average = calculate_average(student);
    printf("\nThe average mark is: %.1f\n", average);
    
    // Update the student's name and third module mark
    update_name(&student, "Jane Smith");
    update_mark(&student, 2, 92.5); // Update the third module (index 2)
    
    // Display the updated student information
    printf("\nAfter updates:\n");
    display_student(student);
    
    return 0;
}
```

## Step 1: Create the Header File (student.h)
Create a new file named `student.h` that contains:
- Include guards
- Structure definition
- Function prototypes (declarations)
- Constant definitions

The header file should provide the **interface** to your student record module without revealing implementation details.

**Your Task:** Complete the student.h file below:

```c
/**
 * @file student.h
 * @brief Header file for student record management system
 */

/* Add include guards here */
#ifndef STUDENT_H
#define STUDENT_H

/* Add necessary includes here */


/* Add constant definitions here */


/* Add the Student structure definition here */


/* Add function prototypes here */


#endif /* STUDENT_H */
```

## Step 2: Create the Implementation File (student.c)
Create a new file named `student.c` that contains:
- Necessary includes (including your header file)
- Function implementations

The implementation file provides the actual code that makes the functions work, but doesn't include main().

**Important:** When including headers, always include your own header file first, then system headers.

**Your Task:** Complete the student.c file below:

```c
/**
 * @file student.c
 * @brief Implementation of student record management functions
 */

/* Add necessary includes here */
#include "student.h"  /* Always include your own header first */
#include <stdio.h>
#include <string.h>


/* Implement the calculate_average function here */



/* Implement the display_student function here */



/* Implement the update_name function here */



/* Implement the update_mark function here */


```

## Step 3: Create the Main Program File (main.c)
Create a new file named `main.c` that contains:
- Necessary includes (including your header file)
- The main() function

The main program file focuses on the high-level flow of your program, using the functions defined in your student module.

**Your Task:** Complete the main.c file below:

```c
/**
 * @file main.c
 * @brief Main program for student record management system
 */

/* Add necessary includes here */



/* Implement the main function here */


```

## Step 4: Compile and Test
Compile your modularised program with the following commands:

```bash
# Compile the implementation file to an object file
gcc -c student.c -o student.o

# Compile the main program file to an object file
gcc -c main.c -o main.o

# Link the object files to create the executable
gcc student.o main.o -o student_program

# Alternative one-line compilation (simpler but less efficient for large projects)
gcc student.c main.c -o student_program

# Run the program
./student_program
```

The output should be identical to the original single-file program.

## Common Issues

- **"undefined reference"** errors typically indicate you've declared a function in the header but not implemented it in the .c file
- **"multiple definition"** errors often mean missing include guards
- **"implicit declaration"** errors usually mean you forgot to include the header file
- If your program behavior differs from the original, check that all functions are implemented correctly

## Reflection Questions
1. How does separating the program into multiple files improve its organisation?
2. What is the purpose of include guards, and what problems do they prevent?
3. Why do we include the header file in both the implementation file and the main program file?
4. How would you extend this modular structure if you wanted to add more functionality, such as reading/writing student records to a file?

## Extension Tasks
If you finish early, try these extension tasks:

1. Add a new function to the student module that sorts an array of students by their average mark
2. Add appropriate documentation comments to all files
3. Update the program to handle multiple students
4. Create a new module for file operations (e.g., saving and loading student records)

## Note on Documentation

Maintain consistent documentation style across all files. Use the same Doxygen-style comments as in the original code for all new functions and data structures:

```c
/**
 * @brief Short description of function/structure
 *
 * @param param_name Description of parameter
 * @return Description of return value
 */
```
