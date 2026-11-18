#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node *left, *right, *parent;
} Node;
int main() {
    char str[1000000];
    int target, k;
    fgets(str, sizeof(str), stdin);
    int val[100005], n = 0;
    char *token = strtok(str, "[], \n");
    while (token != NULL) {
        val[n++] = atoi(token);
        token = strtok(NULL, "[], \n");
    }
    scanf("%d%d", &target, &k);
    Node **nodes = malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = NULL;
        if (val[i] != -1) {
            nodes[i] = malloc(sizeof(Node));
            nodes[i]->data = val[i];
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
            nodes[i]->parent = NULL;
        }
    }
    int q[100005];
    int front = 0, rear = 0;
    int pos = 1;
    q[rear++] = 0;
    while (front < rear && pos < n) {
        int p = q[front++];
        if (pos < n && nodes[pos] != NULL) {
            nodes[p]->left = nodes[pos];
            nodes[pos]->parent = nodes[p];
            q[rear++] = pos;
        }
        pos++;
        if (pos < n && nodes[pos] != NULL) {
            nodes[p]->right = nodes[pos];
            nodes[pos]->parent = nodes[p];
            q[rear++] = pos;
        }
        pos++;
    }
    Node *start = NULL;
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL && nodes[i]->data == target) {
            start = nodes[i];
            break;
        }
    }
    Node *bfs[100005];
    int visited[100005] = {0};
    front = 0;
    rear = 0;
    int startIndex = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i] == start) {
            startIndex = i;
            break;
        }
    }
    bfs[rear++] = start;
    visited[startIndex] = 1;
    int distance = 0;
    while (front < rear && distance < k) {
        int size = rear - front;
        while (size--) {
            Node *curr = bfs[front++];
            Node *next[3] = { curr->left, curr->right, curr->parent };
            for (int j = 0; j < 3; j++) {
                if (next[j] != NULL) {
                    int idx = 0;
                    while (nodes[idx] != next[j])
                        idx++;
                    if (!visited[idx]) {
                        visited[idx] = 1;
                        bfs[rear++] = next[j];
                    }
                }
            }
        }
        distance++;
    }
    printf("[");
    for (int i = front; i < rear; i++) {
        printf("%d", bfs[i]->data);
        if (i != rear - 1)
            printf(", ");
    }
    printf("]\n");
    return 0;
}
