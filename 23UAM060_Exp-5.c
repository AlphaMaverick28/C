#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void initNode(struct node* nn) {
    printf("Enter value for node: ");
    scanf("%d", &nn->data);
    nn->next = NULL;
}

void attach_begin(struct node **hptr, struct node* nn) {
    nn->next = *hptr;
    *hptr = nn;
}

int attachMiddle(struct node **head, int val, struct node *nn) {
    if (*head == NULL) {
        *head = nn;
        return 1; 
    } else {
        struct node *cnode = *head;
        while (cnode != NULL) {
            if (cnode->data == val) {
                nn->next = cnode->next;
                cnode->next = nn;
                return 1; 
            }
            cnode = cnode->next;
        }
        return 0; 
    }
}

void attachEnd(struct node **head, struct node *nn) {
    if (*head == NULL) {
        *head = nn;
    } else { 
        struct node *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = nn;
    }
}

void detachBegin(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("First node detached.\n");
    }
}

void detachEnd(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct node *current = *head;
        if (current->next == NULL) { 
            free(current);
            *head = NULL;
            printf("Last node detached.\n");
            return;
        }
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        printf("Last node detached.\n");
    }
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node* createNode() {
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit on allocation failure
    }
    return newNode;
}

int main() {
    struct node *head = NULL;
    int choice, val;

   
    struct node *firstNode = createNode();
    initNode(firstNode);
    head = firstNode;

    struct node *secondNode = createNode();
    initNode(secondNode);
    attach_begin(&head, secondNode);

  
    printList(head);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Attach at Beginning\n");
        printf("2. Attach in Middle\n");
        printf("3. Attach at End\n");
        printf("4. Detach from Beginning\n");
        printf("5. Detach from End\n");
        printf("6. Print List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        struct node *newNode = createNode();
        switch (choice) {
            case 1:
                initNode(newNode);
                attach_begin(&head, newNode);
                 printList(head);
                break;
            case 2:
                printf("Enter the value after which to insert: ");
                scanf("%d", &val);
                initNode(newNode);
                if (attachMiddle(&head, val, newNode)) {
                    printf("Node inserted after %d.\n", val);
                } else {
                    printf("Value %d not found.\n", val);
                }
                 printList(head);
                break;
            case 3:
                initNode(newNode);
                attachEnd(&head, newNode);
                 printList(head);
                break;
            case 4:
                detachBegin(&head);
                 printList(head);
                break;
            case 5:
                detachEnd(&head);
                 printList(head);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                printf("Exiting...\n");
                while (head != NULL) {
                    detachBegin(&head); // Clean up remaining nodes
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

