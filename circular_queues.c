#include <stdio.h>
#define MAX 5  // Define the maximum capacity of the circular queue

int queue[MAX];
int front = -1, rear = -1;  // Initialize front and rear to -1 (empty queue)

// Function to add an element to the queue (enqueue)
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue overflow. Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) front = 0;  // Set front to 0 if the queue was empty
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Enqueued %d.\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (front == -1) {
        printf("Queue underflow. No elements to dequeue.\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) {
            // Queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("Dequeued %d.\n", value);
        return value;
    }
}

// Function to display the elements of the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Main function to test circular queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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
