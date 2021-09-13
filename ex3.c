/* Evgenii Meshcheriakov. Excercise 3 */

#include<stdio.h>
#define STUDENTS 40
#define GRADE_MIN 0
#define GRADE_MAX 5

// Declaration of a function
float grades_average(int *array, int array_size);

int main(void)
{
// Initializations
    int grades[STUDENTS] = {};
    int student_to_grade = STUDENTS;

// Array bounds checking and set up of students to be graded
    do
    {
        printf("Enter number of students to be graded, please: ");
        scanf("%d", &student_to_grade);
        if(student_to_grade <=0 || student_to_grade > STUDENTS)
        {
            printf("You can grade only up to %d students\n", STUDENTS);
        }
    } while(student_to_grade <=0 || student_to_grade > STUDENTS);

// Grading of the students
    for(int i = 0; i<student_to_grade; i++)
    {
        printf("Enter grade of student %d, please: ", 45001+i);
        scanf("%d", &grades[i]);

// Grade bound checking
        while(grades[i] < GRADE_MIN || grades[i] > GRADE_MAX)
        {
            printf("Grade must be in range %d to %d\n", GRADE_MIN, GRADE_MAX);
            printf("Enter grade of student %d within valid range, please: ", 45001+i);
            scanf("%d", &grades[i]);
        }
    }

// Print out the result
    float result = grades_average(grades, student_to_grade);
    printf("Average of %d students is %0.2f\n", student_to_grade, result);
    return 0;
}

// Definition of a function that returns the average of course grades.
float grades_average(int *array, int array_size)
{
    int sum = 0;
    for(int i = 0; i<array_size; i++)
    {
        sum += array[i];
    }
    float average = (float) sum/array_size;
    return average;
}