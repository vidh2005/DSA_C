#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Student and typedef it as a pointer type
typedef struct Student {
    int id;
    char name[50];
    float cgpa;
    char branch[10];
    struct Student* next;
} *Student; // Now, Student is effectively a pointer to struct Student

// Function to create a new student node
Student createStudent(int id, char name[], float cgpa, char branch[]) {
    Student newStudent = (Student)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->cgpa = cgpa;
    strcpy(newStudent->branch, branch);
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new student node at the end of the list
void insertStudent(Student* head, int id, char name[], float cgpa, char branch[]) {
    Student newStudent = createStudent(id, name, cgpa, branch);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to change the branch of students with a CGPA above a certain threshold
void changeBranch(Student head, float cgpaThreshold, char newBranch[]) {
    Student temp = head;
    while (temp != NULL) {
        if (temp->cgpa >= cgpaThreshold) {
            strcpy(temp->branch, newBranch);
        }
        temp = temp->next;
    }
}

// Function to display details of students only in the "ISE" branch
void displayISEStudents(Student head) {
    Student temp = head;
    printf("ISE Branch Students:\n");
    while (temp != NULL) {
        if (strcmp(temp->branch, "ISE") == 0) {
            printf("ID: %d, Name: %s, CGPA: %.2f, Branch: %s\n",
                   temp->id, temp->name, temp->cgpa, temp->branch);
        }
        temp = temp->next;
    }
}

// Main function to test the linked list operations
int main() {
    Student head = NULL;
    int choice, id;
    char name[50], branch[10];
    float cgpa, cgpaThreshold;

    while (1) {
        printf("\n1. Insert Student\n2. Change Branch for High CGPA\n3. Display ISE Students\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf(" %[^\n]", name);
                printf("Enter CGPA: ");
                scanf("%f", &cgpa);
                printf("Enter branch: ");
                scanf("%s", branch);
                insertStudent(&head, id, name, cgpa, branch);
                break;
            case 2:
                printf("Enter CGPA threshold for branch change: ");
                scanf("%f", &cgpaThreshold);
                printf("Enter new branch: ");
                scanf("%s", branch);
                changeBranch(head, cgpaThreshold, branch);
                break;
            case 3:
                displayISEStudents(head);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
