#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode 
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T) 
{
    char ch;
    scanf(" %c", &ch);

    if (ch == '#') 
    {
        *T = NULL;
    } 
    else 
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T)) 
        {
            exit(EXIT_FAILURE);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild); 
        CreateBiTrie(&(*T)->rchild); 
    }
}

void PreOrderTraversal(BiTree T) 
{
    if (T) 
    {
        printf("%c", T->data);
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

void InOrderTraversal(BiTree T) 
{
    if (T) 
    {
        InOrderTraversal(T->lchild);
        printf("%c", T->data);
        InOrderTraversal(T->rchild);
    }
}

void PostOrderTraversal(BiTree T) 
{
    if (T) 
    {
        PostOrderTraversal(T->lchild);
        PostOrderTraversal(T->rchild);
        printf("%c", T->data);
    }
}

int CountNodes(BiTree T) 
{
    if (T == NULL) 
    {
        return 0;
    }

    int res = 1 + CountNodes(T->lchild) + CountNodes(T->rchild);

    return res;
}

int GetDepth(BiTree T) 
{
    if (T == NULL) 
    {
        return 0;
    }

    int left_depth = GetDepth(T->lchild);
    int right_depth = GetDepth(T->rchild);
    int res = 1 + ((left_depth) > (right_depth) ? (left_depth) : (right_depth));
    
    return res;
}

int main() 
{
    BiTree root = NULL;
    CreateBiTree(&root);

    PreOrderTraversal(root);
    printf("\n");

    InOrderTraversal(root);
    printf("\n");

    PostOrderTraversal(root);
    printf("\n");

    printf("%d\n", CountNodes(root));

    printf("%d\n", GetDepth(root));

    return 0;
}