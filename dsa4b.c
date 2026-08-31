#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void display(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteFront(struct Node **head) {
    if (*head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
void deleteMiddle(struct Node **head, int position) {
    if (*head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    if (position == 1) {
        deleteFront(head);
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    printf("Deleted element: %d\n", deleteNode->data);
    free(deleteNode);
}
void insertEnd(struct Node **head, int data) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
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
int main() {
    struct Node *head = NULL;
    int n, data, position;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }
    printf("\nOriginal Linked List:\n");
    display(head);
    deleteFront(&head);

    printf("After deletion from front:\n");
    display(head);
    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    deleteMiddle(&head, position);

    printf("After deletion from position %d:\n", position);
    display(head);

    return 0;
}