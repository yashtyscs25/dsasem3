#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data, lt, rt;
    struct Node *left, *right;
};
struct Node* create(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    n->lt = n->rt = 0;
    return n;
}
struct Node* insert(struct Node* root, int x) {
    if (!root) return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void convert(struct Node* root, struct Node** prev) {
    if (!root) return;
    if (!root->lt)
        convert(root->left, prev);
    if (!root->left) {
        root->left = *prev;
        root->lt = 1;
    }
    if (*prev && !(*prev)->right) {
        (*prev)->right = root;
        (*prev)->rt = 1;
    }
    *prev = root;
    if (!root->rt)
        convert(root->right, prev);
}
struct Node* search(struct Node* root, int x) {
    while (root && root->data != x) {
        if (x < root->data)
            root = root->lt ? NULL : root->left;
        else
            root = root->rt ? NULL : root->right;
    }
    return root;
}
struct Node* next(struct Node* p) {
    if (!p) return NULL;
    if (p->rt) return p->right;
    p = p->right;
    while (p && !p->lt)
        p = p->left;
    return p;
}
struct Node* prev(struct Node* p) {
    if (!p) return NULL;
    if (p->lt) return p->left;
    p = p->left;
    while (p && !p->rt)
        p = p->right;
    return p;
}
struct Node* smallest(struct Node* root) {
    while (root && !root->lt)
        root = root->left;
    return root;
}
void range(struct Node* root, int L, int R) {
    struct Node* p = NULL;
    while (root) {
        if (root->data >= L) {
            p = root;
            root = root->lt ? NULL : root->left;
        } else {
            root = root->rt ? NULL : root->right;
        }
    }
    while (p && p->data <= R) {
        printf("%d ", p->data);
        p = next(p);
    }
}
int kth(struct Node* root, int k) {
    struct Node* p = smallest(root);
    while (p && --k)
        p = next(p);
    return p ? p->data : -1;
}
int main() {
    struct Node* root = NULL;
    struct Node* p = NULL;
    int a[] = {40, 20, 60, 10, 30, 50, 70};
    int n = 7;
    for (int i = 0; i < n; i++)
        root = insert(root, a[i]);
    convert(root, &p);
    p = search(root, 30);
    struct Node* s = next(p);
    struct Node* pr = prev(p);
    printf("NEXT 30 = %d\n", s ? s->data : -1);
    printf("PREV 30 = %d\n", pr ? pr->data : -1);
    printf("RANGE = ");
    range(root, 25, 60);
    printf("\nKTH 5 = %d\n", kth(root, 5));
    return 0;
}
