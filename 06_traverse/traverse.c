#include <stdio.h>
#include <stdlib.h>
#include "traverse.h"
#include "lstack.h"

int *value = NULL;
int *left = NULL;
int *right = NULL;

int *tValue = NULL;
int *tLeft = NULL;
int *tMid = NULL;
int *tRight = NULL;

void inorderNR(int v) {
    extern int *value;
    extern int *left;
    extern int *right;

    LStack s = CreateStack();

    int curr = v;
    while (curr != 0 || !IsEmptyStack(s)) {
        while (curr != 0) {
            Push(curr, s);
            curr = left[curr];
        }

        if (!IsEmptyStack(s)) {
            curr = Top(s);
            Pop(s);
            printf("%d ", value[curr]);
            curr = right[curr];
        }
    }

    RemoveStack(&s);
}

void SetBT(int *v, int *l, int *r) {
    value = v;
    left = l;
    right = r;
}

void SetTT(int *v, int *l, int *m, int *r) {
    tValue = v;
    tLeft = l;
    tMid = m;
    tRight = r;
}

void inorder(int v) {
    if (v == 0) return;
    inorder(left[v]);
    printf("%d ", value[v]);
    inorder(right[v]);
}

void preorder(int v) {
    if (v == 0) return;
    printf("%d ", value[v]);
    preorder(left[v]);
    preorder(right[v]);
}

void postorder(int v) {
    if (v == 0) return;
    postorder(left[v]);
    postorder(right[v]);
    printf("%d ", value[v]);
}

void preorderNR(int v) {
    if (v == 0) return;

    int stack[1000];
    int top = 0;
    stack[top++] = v;

    while (top > 0) {
        int node = stack[--top];
        printf("%d ", value[node]);

        if (right[node] != 0)
            stack[top++] = right[node];
        if (left[node] != 0)
            stack[top++] = left[node];
    }
}

void levelorder(int root) {
    if (root == 0) return;

    int queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", value[node]);

        if (left[node] != 0)
            queue[rear++] = left[node];
        if (right[node] != 0)
            queue[rear++] = right[node];
    }
}

void t_preorder(int root) {
    if (root == 0) return;
    printf("%d ", tValue[root]);
    if (tLeft[root]  != 0) t_preorder(tLeft[root]);
    if (tMid[root]   != 0) t_preorder(tMid[root]);
    if (tRight[root] != 0) t_preorder(tRight[root]);
}

void t_postorder(int root) {
    if (root == 0) return;
    if (tLeft[root]  != 0) t_postorder(tLeft[root]);
    if (tMid[root]   != 0) t_postorder(tMid[root]);
    if (tRight[root] != 0) t_postorder(tRight[root]);
    printf("%d ", tValue[root]);
}

void preorderTT(int root)  { t_preorder(root); }
void postorderTT(int root) { t_postorder(root); }
