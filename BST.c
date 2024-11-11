#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Find the minimum value node in the BST
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int data) {
    // Base case
    if (root == NULL) {
        return root;
    }

    // If the data to be deleted is smaller than the root's data
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's data
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is the same as the root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// In-order traversal of the BST
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main function
int main() {
    Node* root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Displaying the BST in in-order traversal
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    // Deleting a node from the BST
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50: ");
    inOrder(root);
    printf("\n");

    return 0;
}
