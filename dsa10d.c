#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct Node* root, int arr[], int *count) {
    if (root == NULL) return;
    inorder(root->left, arr, count);
    arr[(*count)++] = root->data;
    inorder(root->right, arr, count);
}
int main() {
    struct Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right->left = createNode(13);
    int sorted[100], count = 0, queries, k;
    inorder(root, sorted, &count);
    printf("Enter number of queries: ");
    scanf("%d", &queries);
    int queryarr[queries];
    printf("Enter queries: ");
    for(int i = 0; i < queries; i++) {
        scanf("%d", &k);
        if (k < 1 || k > count)
            queryarr[i] = -1;
        else
        queryarr[i] = sorted[k - 1];
    }
    printf("\n");
    for(int i = 0; i < queries; i++) {
        if (queryarr[i] == -1)
            printf("\nInvalid ");
        else
            printf("%d \n", queryarr[i]);
    }
    return 0;
}
