#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isEmpty(struct Node* front) {
    return front == NULL;
}

void enqueue(struct Node** front, struct Node** rear) {
    int val;
    printf("Enter Value to Add: ");
    scanf("%d", &val);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty(*front)) {
        *front = *rear = newNode;
        (*rear)->next = *front; 
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
        (*rear)->next = *front;
    }

    printf("Element Enqueued in queue.\n");
}

void dequeue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = *front;

    if (*front == *rear) { 
        printf("Dequeued Element - %d\n", (*front)->data);
        *front = *rear = NULL; 
    } else {
        printf("Dequeued Element - %d\n", (*front)->data);
        *front = (*front)->next;
        (*rear)->next = *front;
    }

    free(temp); 
}

void display(struct Node* front, struct Node* rear) {
    if (isEmpty(front)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front); 
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int ch;

    while (1) {
        printf("\n1. Add Element to Queue\n2. Delete Element from Queue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue(&front, &rear);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Option!\n");
        }
    }

    return 0;
}

