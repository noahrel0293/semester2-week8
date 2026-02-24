# Task 1: Student Record Management

This activity introduces the use of structures (`struct`) in C to manage related data as a single unit. You'll create a student record system that stores and manipulates student information.

## Learning Objectives

* Define and use structures in C
* Initialise structure variables
* Access and modify structure members
* Perform calculations with structure data
* Understand the difference between structure member access with dot notation (`.`) and arrow notation (`->`)

## The Task

1. Complete the implementation of a student record system using the provided stub code.
2. The student structure should contain:
   - Name (as a character array)
   - ID number (as an integer)
   - Three module marks (as floating-point numbers)
3. Create and initialise a student variable
4. Calculate and display the average module mark
5. Modify the student's name and third module mark
6. Display the updated student information

## Step-by-Step Instructions

1. Review the `struct Student` definition provided in the stub file
2. Initialise a student variable with sample data
3. Implement the `calculate_average` function to compute the average of the three module marks
4. Update the student's record with new values for name and third module mark
5. Print the updated student information

## Testing Your Implementation

As you implement each function, test it to ensure it works correctly:
- Verify that student information is correctly stored
- Check that the average calculation is accurate
- Confirm that updates to the student record are properly applied

## Extension Tasks

If you finish early, or in your own study time, try these extensions:
1. Extend the program to handle an array of students
2. Add a function to find the student with the highest average mark
3. Implement a function to sort students by their average marks
4. Add a function to write student records to a file and read them back

## Tips for Working with Structures

* Access structure members using the dot operator (`.`) for structure variables
* For structure pointers, use the arrow operator (`->`) to access members
* When passing large structures to functions, consider passing them by reference (using pointers) rather than by value to improve efficiency