#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data, lthread, rthread;
    struct Node *left, *right;
};
struct Node* create(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    n->lthread = n->rthread = 0;
    return n;
}
struct Node* insert(struct Node* root, int x) {
    if (root == NULL) return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void convert(struct Node* root, struct Node** prev) {
    if (!root) return;
    convert(root->left, prev);
    if (!root->left) {
        root->left = *prev;
        root->lthread = 1;
    }
    if (*prev && !(*prev)->right) {
        (*prev)->right = root;
        (*prev)->rthread = 1;
    }
    *prev = root;
    convert(root->right, prev);
}
struct Node* leftmost(struct Node* root) {
    while (root && !root->lthread)
        root = root->left;
    return root;
}
void inorder(struct Node* root) {
    struct Node* curr = leftmost(root);
    while (curr) {
        printf("%d ", curr->data);
        if (curr->rthread)
            curr = curr->right;
        else
            curr = leftmost(curr->right);
    }
}
int main() {
    struct Node* root = NULL;
    struct Node* prev = NULL;
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values: ");
    while (n--) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    convert(root, &prev);
    printf("Inorder Traversal: ");
    inorder(root);
    return 0;
}
