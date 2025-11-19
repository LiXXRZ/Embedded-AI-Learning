#include <stdio.h>
#include <stdlib.h>

typedef struct CSNode 
{
    char data;
    struct CSNode *firstchild;  // left pointer
    struct CSNode *nextsibling; // right pointer
} CSNode, *CSTree;

CSTree CreateNode(char data) 
{
    CSTree node = (CSTree)malloc(sizeof(CSNode));
    node->data = data;
    node->firstchild = NULL;
    node->nextsibling = NULL;
    return node;
}

CSTree FindNode(CSTree T, char target) 
{
    if (T == NULL) return NULL;

    if (T->data == target) return T;
    
    CSTree L = FindNode(T->firstchild, target);
    if (L != NULL) return L; 
    
    CSTree R = FindNode(T->firstchild, target);
    return R;
}

int GetDepth(CSTree T) 
{
    if (T == NULL) return 0;
    
    int childDepth = GetDepth(T->firstchild);
    int siblingDepth = GetDepth(T->nextsibling);
    int res = (childDepth + 1 > siblingDepth) ? (childDepth + 1) : siblingDepth;
    return res;
}

int main() {
    char str[100];
    CSTree root = NULL; 

    printf("请输入 (例如 #a, ab, ac, ##):\n");

    while (scanf("%s", str) != EOF) 
    {
        if (str[0] == '#' && str[1] == '#') break;

        if (str[0] == '#') 
        {
            root = CreateNode(str[1]); 
        }

        else {
            char parentChar = str[0];
            char childChar = str[1];
            
            CSTree parent = FindNode(root, parentChar);
            
            CSTree child = CreateNode(childChar);

            if (parent != NULL) 
            {
                if (parent->firstchild == NULL) 
                {
                    parent->firstchild = child;
                } 
                else 
                {
                    CSTree brother = parent->firstchild;
                    if (brother->nextsibling == NULL)
                    {
                        brother->nextsibling = child;
                    } 
                    while (brother->nextsibling != NULL) 
                    {
                        brother = brother->nextsibling;
                    }
                    brother->nextsibling = child;
                }
            }
        }
    }

    printf("树的深度为: %d\n", GetDepth(root));

    return 0;
}