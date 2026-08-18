#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert a node at the beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the first node contains the value
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Free all nodes
void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    // Insert elements
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Linked List: ");
    display(head);

    // Insert at beginning
    insertAtBeginning(&head, 5);

    printf("After inserting 5 at beginning: ");
    display(head);

    // Delete an element
    deleteNode(&head, 20);

    printf("After deleting 20: ");
    display(head);

    // Free memory
    freeList(&head);

    return 0;
}
