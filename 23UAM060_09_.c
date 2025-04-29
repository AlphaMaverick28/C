#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
    {
        return createNode(data);
    }

    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) 
    {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) 
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int n, value;
	int i;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) 
	{
        printf("Enter node value %d : ",i+1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder traversal: ");
    inorderTraversal(root);

    printf("\nPreorder traversal: ");
    preorderTraversal(root);

    printf("\nPostorder traversal: ");
    postorderTraversal(root);

    return 0;
}

