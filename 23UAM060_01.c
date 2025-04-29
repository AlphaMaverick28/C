#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void attachBegin(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}
void attachEnd(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void attachMiddle(Node** head, Node* newNode, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        if (temp->data == value) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}
void detachBegin(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}
void detachEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
void detachMiddle(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->data == value) {
        Node* temp = *head;
        *head = temp->next;
        free(temp);
    } else {
        Node* temp = *head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            if (temp->next->data == value) {
                prev->next = temp->next->next;
                free(temp->next);
                return;
            }
            temp = temp->next;
        }
        printf("Node not found\n");
    }
}
void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Node* head = NULL;
    int choice, data, value;
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert in the middle\n4. Delete from beginning\n5. Delete from end\n6. Delete from middle\n7. Traverse\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                attachBegin(&head, createNode(data));
                printf("List after insertion: ");
                traverse(head);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                attachEnd(&head, createNode(data));
                printf("List after insertion: ");
                traverse(head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter value for insertion: ");
                scanf("%d", &value);
                attachMiddle(&head, createNode(data), value);
                printf("List after insertion: ");
                traverse(head);
                break;
            case 4:
                detachBegin(&head);
                printf("List after deletion: ");
                traverse(head);
                break;
            case 5:
                detachEnd(&head);
                printf("List after deletion: ");
                traverse(head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                detachMiddle(&head, value);
                printf("List after deletion: ");
                traverse(head);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}