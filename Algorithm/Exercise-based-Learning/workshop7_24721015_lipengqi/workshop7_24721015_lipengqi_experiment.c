#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;

typedef char* KeyType; 

#define EQ(a, b) (!strcmp((a), (b)))
#define LT(a, b) (strcmp((a), (b)) < 0)
#define LQ(a, b) (strcmp((a), (b)) <= 0)

typedef struct BiTNode 
{
    KeyType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct 
{
    KeyType *elem;
    int length;
} SSTable;

Status InsertBST(BiTree *T, KeyType e) 
{
    if (!(*T)) 
    {
        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = NULL;
        *T = s;
        return TRUE;
    }

    if (EQ(e, (*T)->data)) 
    {
        return FALSE;
    } 
    else if (LT(e, (*T)->data)) 
    {
        InsertBST(&((*T)->lchild), e);
    } 
    else 
    {
        InsertBST(&((*T)->rchild), e);
    }
    return TRUE;
}

void CalcTPL(BiTree T, int depth, int *sum) 
{
    if (T) 
    {
        *sum += depth;
        CalcTPL(T->lchild, depth + 1, sum);
        CalcTPL(T->rchild, depth + 1, sum);
    }
}

void InOrder(BiTree T) 
{
    if (T) 
    {
        InOrder(T->lchild);
        printf("%s ", T->data);
        InOrder(T->rchild);
    }
}

int Search_Bin_Cost(SSTable ST, KeyType key) 
{
    int low = 1; 
    int high = ST.length;
    int cost = 0;

    while (low <= high) 
    {
        cost++;
        int mid = (low + high) / 2;
        
        if (EQ(key, ST.elem[mid])) 
        {
            return cost;
        } 
        else if (LT(key, ST.elem[mid])) 
        {
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    return cost;
}

int cmp_str(const void *a, const void *b) 
{
    return strcmp(*(char **)a, *(char **)b);
}

int main() 
{
    int i;
    char *dataset[] = 
    {
        "Jan", "Feb", "Mar", "Apr", "May", "June", 
        "July", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    int n = 12;

    printf("=========================================\n");
    printf("Task 5.1: BST Construction & ASL\n");
    printf("=========================================\n");

    BiTree root = NULL;
    for (i = 0; i < n; i++) 
    {
        InsertBST(&root, dataset[i]);
    }

    printf("BST Inorder Traversal: ");
    InOrder(root);
    printf("\n");

    int tpl_bst = 0;
    CalcTPL(root, 1, &tpl_bst);
    printf("Total Path Length: %d\n", tpl_bst);
    printf("ASL (BST) = %d / %d = %.4f\n\n", tpl_bst, n, (float)tpl_bst/n);


    printf("=========================================\n");
    printf("Task 5.2: Ordered Table & Binary Search\n");
    printf("=========================================\n");

    SSTable ST;
    ST.length = n;
    ST.elem = (KeyType *)malloc((n + 1) * sizeof(KeyType));

    for (i = 0; i < n; i++) 
    {
        ST.elem[i + 1] = dataset[i];
    }

    qsort(ST.elem + 1, n, sizeof(KeyType), cmp_str);

    printf("Ordered Table Content: ");
    for (i = 1; i <= ST.length; i++) 
    {
        printf("%s ", ST.elem[i]);
    }
    printf("\n");

    int total_cost = 0;
    printf("Costs per element: ");
    for (i = 1; i <= ST.length; i++) 
    {
        int cost = Search_Bin_Cost(ST, ST.elem[i]);
        printf("%s(%d) ", ST.elem[i], cost);
        total_cost += cost;
    }
    printf("\n");
    
    printf("Total Comparisons: %d\n", total_cost);
    printf("ASL (Binary Search) = %d / %d = %.4f\n", total_cost, n, (float)total_cost/n);

    free(ST.elem);
    
    return 0;
}