#include <stdio.h>
#include <stdlib.h>

// 2.1

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

void SelectionSort(LinkList L) {
    if (!L || !L->next) return;

    Node *p, *q, *min;
    int temp;

    for (p = L->next; p != NULL; p = p->next) {
        min = p;
        for (q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }
        if (min != p) {
            temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
    }
}

// 2.2

#define MAX 500

void quickSortIndices(int sums[], int indices[], int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    int pivotIndex = indices[left];
    int pivotSum = sums[pivotIndex];

    while (i < j) {
        while (i < j && sums[indices[j]] <= pivotSum) j--;
        indices[i] = indices[j];
        
        while (i < j && sums[indices[i]] >= pivotSum) i++;
        indices[j] = indices[i];
    }
    indices[i] = pivotIndex;

    quickSortIndices(sums, indices, left, i - 1);
    quickSortIndices(sums, indices, i + 1, right);
}

void ArraySort(int A[500][500], int n) {
    int sums[MAX];
    int indices[MAX];

    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        indices[i] = i;
        for (int j = 0; j < n; j++) {
            sums[i] += A[i][j];
        }
    }

    quickSortIndices(sums, indices, 0, n - 1);

    int tempA[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempA[i][j] = A[indices[i]][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = tempA[i][j];
        }
    }
}

void PrintList(LinkList L) {
    Node* p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    // --- 2.1 ---
    printf("--- 2.1 Test ---\n");
    LinkList L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    int vals[] = {503, 87, 512, 61, 908};
    Node* r = L;
    for(int i=0; i<5; i++) {
        Node* s = (Node*)malloc(sizeof(Node));
        s->data = vals[i]; s->next = NULL;
        r->next = s; r = s;
    }
    printf("Before: "); PrintList(L);
    SelectionSort(L);
    printf("After: "); PrintList(L);

    // --- 2.2 ---
    printf("\n--- 2.2 Test ---\n");
    int n = 4;
    int A[500][500] = {
        {7, 2, 8, 3}, // sum: 20
        {9, 7, 1, 8}, // sum: 25
        {4, 3, 6, 5}, // sum: 18
        {6, 7, 5, 6}  // sum: 24
    };
    printf("Before:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) printf("%d ", A[i][j]);
        printf("\n");
    }

    ArraySort(A, n);

    printf("After:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) printf("%d ", A[i][j]);
        printf("\n");
    }

    return 0;
}