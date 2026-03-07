## **《数据结构》 - 树及其算法**

---

### **第一部分：树的基础 (Slides 1-20)**

#### **1. 树的定义 (The definition of a tree - Slide 7)**
树 (Tree) 是由 n (n ≥ 0) 个节点组成的有限集合。
*   当 **n = 0** 时，称为**空树**。这是树的递归定义中的**基本情况 (recursion base)**。
*   在任何非空树中：
    1.  有且仅有一个特定的节点，称为**根 (root)**。
    2.  其余的节点可以被划分为 m (m ≥ 0) 个互不相交的有限集合 T₁, T₂,..., Tₘ，其中每一个集合本身又是一棵树，被称为根的**子树 (subtree)**。

#### **例题 1: 树的表示 (Slide 8)**
下图所示的树：
```
      A
     /|\
    / | \
   B  C  D
  / \ | /|\
 E   F G H I J
    / \     |
   K   L    M
```
可以用括号表示法写为：`A( B(E, F(K, L)), C(G), D(H, I, J(M)) )`
*   **根 (Root):** A
*   **A的子树:** T₁ (以B为根), T₂ (以C为根), T₃ (以D为根)

#### **2. 树作为抽象数据类型 (Tree as an abstract data type - Slide 9)**
```
ADT Tree {
    数据对象 D: D 是具有相同特性的数据元素的集合。

    数据关系 R: 如果 D 为空，则称为空树；否则：
    (1) D 中存在一个唯一的被称为根的数据元素。
    (2) 当 n>1 时，其余节点可被划分为 m (m>0) 个互不相交的有限集合 T₁, T₂,..., Tₘ，
        其中每个集合本身都是一棵符合此定义的树，称为根的子树。

    基本操作:
    // ... (详见下一节)
}
```

#### **3. 树的基本操作 (Slides 10-12)**
*   **查找操作 (Searching)**
    *   `Root(T)`: 查找树 T 的根节点。
    *   `Value(T, cur_e)`: 获取当前节点 cur_e 的值。
    *   `Parent(T, cur_e)`: 返回当前节点 cur_e 的父节点。
    *   `LeftChild(T, cur_e)`: 返回当前节点 cur_e 的最左边的孩子。
    *   `RightSibling(T, cur_e)`: 返回当前节点 cur_e 的右兄弟。
    *   `TreeEmpty(T)`: 判断树 T 是否为空。
    *   `TreeDepth(T)`: 计算树 T 的深度。
    *   `TraverseTree(T, Visit())`: 遍历树 T。
*   **插入操作 (Insertion)**
    *   `InitTree(&T)`: 初始化一个空树。
    *   `CreateTree(&T, definition)`: 按定义构造树。
    *   `Assign(T, cur_e, value)`: 给当前节点赋值。
    *   `InsertChild(&T, &p, i, c)`: 将以 c 为根的树作为节点 p 的第 i 棵子树插入。
*   **删除操作 (Deletion)**
    *   `ClearTree(&T)`: 清空树。
    *   `DestroyTree(&T)`: 销毁树结构。
    *   `DeleteChild(&T, &p, i)`: 删除节点 p 的第 i 棵子树。

#### **4. 树结构与线性结构对比 (Slide 14)**
| 结构类型 | 线性结构 (linear structure) | 树结构 (tree structure) |
| :--- | :--- | :--- |
| **起始元素** | 唯一的首元素 (无前驱) | 唯一的**根节点** (无前驱) |
| **终端元素** | 唯一的尾元素 (无后继) | 多个**叶子节点** (无后继) |
| **内部元素** | 一个前驱, 一个后继 | 一个前驱, **多个后继** |

#### **5. 树的基本术语 (Slides 15-20)**
*   **节点 (Tree node)**: 包含数据元素和指向子树的分支。
*   **节点的度 (Degree of a node)**: 节点拥有的子树数量。
*   **树的度 (Tree degree)**: 树中所有节点度的最大值。
*   **叶子节点 (Leaf node)**: 度为 0 的节点。
*   **分支节点 (Branch node)**: 度大于 0 的节点 (非叶子节点)。
*   **孩子/父节点 (Child/Parent node)**: 节点的子树的根是该节点的孩子；该节点是其孩子的父节点。
*   **兄弟节点 (Sibling)**: 具有相同父节点的节点。
*   **路径 (Path)**: 从根到某节点所经过的分支和节点序列。
*   **祖先/子孙 (Ancestor/Descendant node)**: 路径上的所有节点都是目标节点的祖先；反之，目标节点是它们的子孙。
*   **堂兄弟节点 (Cousin)**: 双亲在同一层的节点。
*   **节点的层次 (Level)**: 根为第 1 层，其孩子为第 2 层，以此类推。
*   **树的深度/高度 (Depth)**: 树中节点的最大层次。
*   **有序树 (Ordered tree)**: 节点的各子树从左到右是有次序的，不能互换。
*   **森林 (Forest)**: m (m ≥ 0) 棵互不相交的树的集合。一个树的子树集合也是一个森林。

---

### **第二部分：二叉树 (Binary Tree) (Slides 21-54)**

#### **1. 定义 (Definition of binary tree - Slide 22)**
二叉树是 n (n≥0) 个节点的有限集合，它或者是一个**空集**，或者由一个**根节点**和两棵互不相交的、分别称为根节点的**左子树 (left subtree)** 和**右子树 (right subtree)** 的二叉树组成。

**核心特性：**
1.  每个节点最多有两棵子树 (度 ≤ 2)。
2.  子树有左右之分，次序不能颠倒。
3.  左右子树本身也是二叉树。

#### **例题 2: 二叉树的形态 (Slides 23-24)**
*   **一个例子 (Slide 23):**
    *   根节点: A
    *   左子树: 以 B 为根的子树
    *   右子树: 以 E 为根的子树
*   **五种基本形态 (Slide 24):**
    1.  空树
    2.  只有根节点
    3.  只有左子树
    4.  只有右子树
    5.  左右子树都存在

#### **2. 二叉树的性质 (Properties of a binary tree - Slides 31-41)**

*   **性质 1 (Slide 31):** 在二叉树的第 i 层上，最多有 **2ⁱ⁻¹** 个节点 (i ≥ 1)。
    *   **证明 (Slide 32):** 通过数学归纳法证明。当 i=1 时，2¹⁻¹=1，正确。假设第 i-1 层最多有 2ⁱ⁻² 个节点，由于每个节点的度最多为2，第 i 层最多是第 i-1 层的2倍，即 2 * 2ⁱ⁻² = 2ⁱ⁻¹。

*   **性质 2 (Slide 33):** 深度为 k 的二叉树，最多有 **2ᵏ - 1** 个节点 (k ≥ 1)。
    *   **证明:** 各层最大节点数之和: 2⁰ + 2¹ + ... + 2ᵏ⁻¹ = 2ᵏ - 1。

*   **性质 3 (Slide 34):** 对任何二叉树，若叶子节点数为 n₀，度为 2 的节点数为 n₂，则 **n₀ = n₂ + 1**。
    *   **证明:** 设总节点数为 n，分支数为 b。n = n₀+n₁+n₂。b = n₁+2n₂。同时 b = n-1。联立解得 n₀ = n₂ + 1。

*   **例题 3: 验证性质3 (Slide 35)**
    *   **左树:** n₀=3 (节点4, 7, 3)，n₂=2 (节点1, 2)。 3 = 2 + 1。
    *   **右树:** n₀=2 (节点3, 4)，n₂=1 (节点1)。 2 = 1 + 1。

*   **满二叉树 (Full binary tree - Slide 36):** 深度为 k 且有 2ᵏ-1 个节点的二叉树。
*   **完全二叉树 (Complete binary tree - Slide 37):** 节点编号与同深度满二叉树从1到n的节点一一对应的二叉树。

*   **性质 4 (完全二叉树 - Slide 38):** 具有 n 个节点的完全二叉树的深度为 **⌊log₂n⌋ + 1**。
    *   **证明:** 设深度为 k，则 2ᵏ⁻¹ ≤ n < 2ᵏ。取对数得 k-1 ≤ log₂n < k。因为 k 为整数，所以 k = ⌊log₂n⌋ + 1。
*   **例题 4: 计算完全二叉树深度 (Slide 39)**
    *   树 (a) 有12个节点: 深度 = ⌊log₂12⌋ + 1 = 3 + 1 = 4。
    *   树 (b) 有8个节点: 深度 = ⌊log₂8⌋ + 1 = 3 + 1 = 4。

*   **性质 5 (完全二叉树 - Slide 40):** 对于编号为 i 的节点：
    *   父节点: `⌊i/2⌋` (i>1)
    *   左孩子: `2i` (若 2i ≤ n)
    *   右孩子: `2i+1` (若 2i+1 ≤ n)
*   **例题 5: 应用性质5 (Slide 41)**
    *   树有10个节点。节点1是根。节点5的父节点是 `⌊5/2⌋ = 2`。节点4的左孩子是 `2*4=8`。

#### **3. 二叉树的存储结构 (Storage structure of binary tree - Slides 42-54)**

*   **顺序存储 (Sequential storage - Slides 44-46)**
    *   用数组按层序存储。适用于完全二叉树。
    *   **C 语言描述 (Slide 46):**
        ```c
        #define MAX_TREE_SIZE 100 
        // The maximum number of nodes in a binary tree
        typedef TElemType SqBiTree[MAX_TREE_SIZE]; 
        // Unit 0 stores the root node (幻灯片中的注释, 但通常根存放在1)
        SqBiTree bt;
        ```

*   **链式存储 (Chain storage - Slides 47-54)**
    1.  **二叉链表 (Binary Linked List - Slide 48-49)**
        *   节点结构: `[lchild | data | rchild]`
        *   **C 语言描述 (Slide 49):**
            ```c
            typedef struct BiTNode { // Node structure
                TElemType data;
                struct BiTNode *lchild, *rchild; // Left and right child pointers
            } BiTNode, *BiTree;
            ```
    2.  **三叉链表 (Ternary Linked List - Slide 50-51)**
        *   节点结构: `[parent | lchild | data | rchild]`
        *   **C 语言描述 (Slide 51):**
            ```c
            typedef struct TriTNode { // Node structure
                TElemType data;
                struct TriTNode *lchild, *rchild; // Left and right child pointers
                struct TriTNode *parent;          // Double parent pointer
            } TriTNode, *TriTree;
            ```
    3.  **双亲链表 (Parent linked list - Slide 53-54)**
        *   节点结构: `[data | parent | LRTag]`
        *   **C 语言描述 (Slide 54):**
            ```c
            // 节点结构
            typedef struct BPTNode { 
                TElemType data;
                int parent;        // Pointer to the parent (index)
                char LRTag;        // Left and right child tag fields
            } BPTNode;

            // 树结构
            typedef struct BPTree { 
                BPTNode nodes[MAX_TREE_SIZE];
                int num_node;      // Number of nodes
                int root;          // The location of the root node
            } BPTree;
            ```
*   **例题 6: 存储结构对比 (Slide 52)**
    给出一棵二叉树，并展示了其对应的二叉链表和三叉链表的图示。

---

### **第三部分：二叉树的遍历与应用 (Slides 55-110)**

#### **1. 二叉树遍历 (Binary tree traversal - Slides 55-62)**
遍历是按某种路径访问树中每个节点一次且仅一次。

*   **三种主要遍历方式:**
    1.  **前序遍历 (Pre-order):** 根 → 左 → 右
    2.  **中序遍历 (In-order):** 左 → 根 → 右
    3.  **后序遍历 (Post-order):** 左 → 右 → 根

#### **例题 7: 表达式树遍历 (Slides 60-62)**
对于表达式 `(a + b * (c - d)) - e / f` 对应的二叉树:
*   前序遍历结果 (前缀表达式): `- + a * b - c d / e f`
*   中序遍历结果 (中缀表达式): `a + b * c - d - e / f` (注: 需括号恢复原意)
*   后序遍历结果 (后缀表达式): `a b c d - * + e f / -`

#### **例题 8: 遍历练习 (Slide 63)**
对于下图的树:
```
      A
     / \
    B   D
   /   / \
  E   H   J
   \ / \
    L M  I 
```
*   **前序遍历:** A, B, E, L, D, H, M, I, J
*   **中序遍历:** L, E, B, A, M, H, I, D, J
*   **后序遍历:** L, E, B, M, I, H, J, D, A

#### **2. 遍历的递归算法代码 (Slides 64-66)**
*   **前序遍历 (Pre-order):**
    ```c
    void Preorder (BiTree T, void( *visit)(TElemType& e)) { 
        // Preorder a binary tree
        if (T) {
            visit(T->data);              // Visit the root node
            Preorder(T->lchild, visit);  // Traverse left subtree
            Preorder(T->rchild, visit);  // Traverse right subtree
        }
    }
    ```
*   **中序遍历 (In-order):**
    ```c
    void Inorder (BiTree T, void( *visit)(TElemType& e)) { 
        // In-order traversal binary tree
        if (T) {
            Inorder(T->lchild, visit);   // Traverse left subtree
            visit(T->data);              // Visit the root node
            Inorder(T->rchild, visit);   // Traverse right subtree
        }
    }
    ```
*   **后序遍历 (Post-order):**
    ```c
    void Postorder (BiTree T, void( *visit)(TElemType& e)) { 
        // Postorder traversal of a binary tree
        if (T) {
            Postorder(T->lchild, visit); // Traverse left subtree
            Postorder(T->rchild, visit); // Traverse right subtree
            visit(T->data);              // Visit the root node
        }
    }
    ```

#### **3. 遍历的非递归算法 (Slides 68-80)**

*   **中序遍历 (Non-recursive In-order - Slides 69-73)**
    *   **方法一代码:**
        ```c
        // Helper function: Go down the left chain and push nodes to stack
        BiTNode *GoFarLeft(BiTree T, Stack *S) { 
            if (!T) return NULL;
            while (T->lchild) { // Locate the bottom-left node
                Push(S, T);
                T = T->lchild;
            }
            return T;
        }

        void Inorder_I(BiTree T, void (*visit)(TelemType& e)) {
            Stack *S;
            BiTNode *t = GoFarLeft(T, S); // Locate the first node to visit
            while(t) {
                visit(t->data);
                if (t->rchild) { // If there's a right subtree
                    t = GoFarLeft(t->rchild, S);
                } else if (!StackEmpty(S)) { // No right subtree, pop from stack
                    t = Pop(S);
                } else { // Traversal ends
                    t = NULL; 
                }
            } 
        }
        ```
    *   **方法二代码 (更通用):**
        ```c
        void inorder(BiTree b) { 
            BiTree *stack[m0],*p;
            int top=0; 
            p=b;
            do {
                while (p!=NULL) { // Scan all left nodes
                    top++;
                    stack[top]=p;
                    p=p->lchild;
                }
                if (top>0) { 
                    p=stack[top]; // Pop from stack
                    top--;
                    printf(“%d”,p->data); // Access node
                    p=p->rchild; // Scan the right subtree
                }
            } while (p!=NULL || top!=0);
        }
        ```

*   **前序遍历 (Non-recursive Pre-order - Slides 74-76)**
    ```c
    void preorder(BiTree b) {
        BiTree *stack[m0];
        int top; 
        if (b!=NULL) {
            top=1; // root node into stack
            stack[top]=b;
            while (top>0) {
                p=stack[top]; // pop and access the node
                top--;
                printf(“%d”,p->data); 
                
                // Right child goes into the stack first, then left child
                if (p->rchild!=NULL) { // right child into stack
                    top++;
                    stack[top]=p->rchild;
                }
                if (p->lchild!=NULL) { // left child into stack
                    top++;
                    stack[top]=p->lchild;
                }
            }
        }
    }
    ```

*   **后序遍历 (Non-recursive Post-order - Slides 77-80)**
    ```c
    void postorder(BiTree b) {
        BiTree *stack[m0],*p;
        int tag[m0], top=0; // tag array to mark visited status
        p=b;
        do {
            while (p!=NULL) { // Scan left nodes
                top++; 
                stack[top]=p; 
                tag[top]=0; // Mark as left-visited
                p=p->lchild; 
            }
            while ((top>0) && tag[top]==1) { // Left and right subtrees visited
                p = stack[top];
                printf(“%d”, stack[top]->data); // Access node
                top--; 
            }
            if (top>0) {
                tag[top]=1; // Mark as right-visited
                p=stack[top]->rchild;
            }
        } while (top!=0);
    }
    ```

*   **层序遍历 (Level-order traversal - Slides 81-83)**
    ```c
    #define MAXLEN 100
    void translevel(BiTree b) { // Traverse by level
        struct node {
            BiTree *vec[MAXLEN];
            int f,r; 
        } q;
        q.f=0;
        q.r=0; // Put the queue empty

        if (b!=NULL) printf(“%d”,b->data);
        q.vec[q.r]=b; // Node pointer enters the queue
        q.r=q.r+1;
        
        while (q.f<q.r) { // the queue is not empty
            b=q.vec[q.f]; q.f=q.f+1; // dequeue 
            
            if (b->lchild!=NULL) { // Output the left child and add it to the queue
                printf(“%d”,b->lchild->data); 
                q.vec[q.r]=b->lchild;
                q.r=q.r+1;
            }
            if (b->rchild!=NULL) { // Output the right child and add it to the queue
                printf(“%d”,b->rchild->data);
                q.vec[q.r]=b->rchild;
                q.r=q.r+1;
            }
        }
    }
    ```

#### **4. 遍历的应用 (Applications of traversal - Slides 85-110)**

*   **应用1: 统计叶子节点数 (Slides 86-89)**
    *   **方法一 (传引用参数):**
        ```c
        void CountLeaf (BiTree T, int& count) {
            // Count the number of leaf nodes in a binary tree
            if ( T ) {
                if ((!T->lchild)&& (!T->rchild))
                    count++; // Counting leaf nodes
                CountLeaf( T->lchild, count); 
                CountLeaf( T->rchild, count);
            }
        }
        ```
    *   **方法二 (返回值):**
        ```c
        int CountLeaf (BiTree T) {
            // Method two for counting the number of leaves in a binary tree
            if (T==NULL) return 0;
            else if (T->lchild==NULL && T->rchild==NULL) return 1;
            else return CountLeaf(T->lchild) + CountLeaf(T->rchild);
        }
        ```

*   **应用2: 计算二叉树深度 (Slides 90-91)**
    ```c
    int Depth (BiTree T) { // Return the depth of a binary tree
        int depthval, depthLeft, depthRight;
        if (!T) depthval = 0;
        else {
            depthLeft = Depth( T->lchild );
            depthRight= Depth( T->rchild );
            depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
        }
        return depthval;
    }
    ```

*   **应用3: 从前序字符串构建二叉树 (Slides 93-95)**
    *   **例题 9:** 字符串 `A(B( ,C( , )),D( , ))` 表示一棵树。
    *   **代码:**
        ```c
        Status CreateBiTree(BiTree &T) {
            // Enter the values of the binary tree nodes in preorder
            scanf(&ch);
            if (ch==' ') T = NULL;
            else {
                if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
                    exit(OVERFLOW);
                T->data = ch;                 // Generate root node
                CreateBiTree(T->lchild);      // Construct left subtree
                CreateBiTree(T->rchild);      // Construct the right subtree
            }
            return OK; 
        }
        ```
    *   **例题 10:** 输入 `ABC  D  ` 的执行过程图示 (Slide 95)。

*   **应用4: 从中缀表达式构建二叉树 (Slides 96-103)**
    *   **例题 11:** 表达式 `(a+b)*c-d/e` 及其前、中、后缀遍历。
    *   **算法思想:** 使用两个栈，一个操作数栈（存树节点），一个操作符栈。
    *   **代码 - 创建叶子节点:**
        ```c
        void CrtNode(BiTree& T, char ch) {
            T=(BiTNode*)malloc(sizeof(BiTNode));
            T->data = ch;
            T->lchild = T->rchild = NULL;
            Push( PTR, T ); // Insert leaf node into PTR tree stack
        }
        ```
    *   **代码 - 构建子树:**
        ```c
        void CrtSubtree (Bitree& T, char c) {
            T=(BiTNode*)malloc(sizeof(BiTNode));
            T->data = c;
            Pop(PTR, rc); T->rchild = rc; // Pop two leaf nodes
            Pop(PTR, lc); T->lchild = lc; // construct subtree
            Push(PTR, T); // Insert the subtree into the PTR stack
        }
        ```
    *   **代码 - 主算法框架 (不完整，展示了各部分):**
        ```c
        void CrtExptree(BiTree &T, char exp[] ) {
            InitStack(S); Push(S, '#'); InitStack(PTR); 
            // ... 主循环 ...
            while (!(GetTop(S)=='#' && ch=='#')) {
                if (!IN(ch, OP)) CrtNode(t, ch); // 如果是操作数
                else { // 如果是操作符
                    switch (ch) {
                        case '(': Push(S, ch); break;
                        case ')': 
                            Pop(S, c);
                            while (c!='(') { 
                                CrtSubtree(t, c);
                                Pop(S, c); 
                            }
                            break;
                        default: // 其他操作符
                            while(!Gettop(S, c) && (precede(c,ch))) {
                                CrtSubtree(t, c); 
                                Pop(S, c); 
                            }
                            if ( ch!= '#' ) Push(S, ch);
                            break;
                    } // end switch
                } // end else
                // ... 移动指针 ...
            } // end while
            Pop(PTR, T);
        }
        ```

*   **应用5: 从遍历序列构建二叉树 (Slides 104-110)**
    *   **前序+中序** 或 **后序+中序** 可以唯一确定二叉树。
    *   **例题 12 (Slide 105):**
        *   Preorder: `a b c d e f g`
        *   Inorder: `c b d a e g f`
        *   结果: 构造出对应的二叉树图。
    *   **代码 - 从前序和中序构建:**
        ```c
        void CrtBT(BiTree& T, char pre[], char ino[], int ps, int is, int n ) {
            // Given pre[ps..ps+n-1] as the preorder sequence...
            // ino[is..is+n-1] represents the inorder sequence...
            if (n==0) T=NULL;
            else {
                T=(BiTNode*)malloc(sizeof(BiTNode));
                T->data = pre[ps]; // Establish the tree root
                k=Search(ino, pre[ps]); // Find root in inorder sequence
                
                // If the first character... is also the first character... no left subtree.
                if (k==is) T->lchild = NULL; 
                else CrtBT(T->lchild, pre, ino, ps+1, is, k-is);
                
                // If the first character... is the last character... no right subtree.
                if (k==is+n-1) T->rchild = NULL; 
                else CrtBT(T->rchild, pre, ino, ps+1+(k-is), k+1, n-(k-is)-1);
            }
        }
        ```
    *   **例题 13 (Slide 108-109):**
        *   Pre-order: `ABECDFGHIJ`
        *   In-order: `EBCDAFHIGJ`
        *   展示了详细的递归构建过程图。
    *   **例题 14 (Slide 110):**
        *   In-order: `cbedafhgij`
        *   Post-order: `iscedbhjigfa`
        *   展示了详细的递归构建过程图。

---

### **第四部分：线索二叉树 (Threaded Binary Tree) (Slides 111-125)**

#### **1. 概念与结构 (Slides 113-115)**
利用空指针域存放节点在某种遍历序列中的**前驱**和**后继**。
*   **节点结构:** 增加两个标志域 `LTag` 和 `RTag`。
    *   `lchild` 指针: 若 `LTag=0` 指向左孩子, 若 `LTag=1` 指向前驱。
    *   `rchild` 指针: 若 `RTag=0` 指向右孩子, 若 `RTag=1` 指向后继。
*   **C 语言描述 (Slide 117):**
    ```c
    typedef enum { Link, Thread } PointerThr;
    // Link==0: pointer, Thread==1: thread

    typedef struct BiThrNode {
        TElemType data;
        struct BiThrNode *lchild, *rchild; // left and right pointers
        PointerThr LTag, RTag;             // Left and right flags
    } BiThrNode, *BiThrTree;
    ```
*   **例题 15: 后序线索二叉树 (Slide 116)**
    *   后序序列: `DBECA`
    *   给出了一个5节点树的线索化后的存储结构图。

#### **2. 线索化过程 (Threading - Slides 122-125)**
在遍历过程中修改空指针域。需要一个 `pre` 指针记录前驱。
*   **中序线索化核心代码 (Slide 123):**
    ```c
    void InThreading (BiThrTree p) {
        if (p) {
            InThreading (p->lchild); // Left subtree cycled
            
            if (!p->lchild) { // Left child is empty, build predecessor clue
                p->LTag = Thread; p->lchild = pre; 
            }
            if (pre && !pre->rchild) { // Predecessor's right child is empty
                pre->RTag = Thread; pre->rchild = p; 
            }
            pre = p; // pre keeps the predecessor
            
            InThreading (p->rchild); // Right subtree lenticulation
        }
    }
    ```
*   **带头结点的中序线索化完整函数 (Slides 124-125):**
    ```c
    Status InOrderThreading (BiThrTree &Thrt, BiThrTree T) {
        // Build a middle-order linked list Thrt points to the header node
        if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
            exit (OVERFLOW); // Allocate the head node
        Thrt->LTag = Link; Thrt->RTag = Thread;
        Thrt->rchild = Thrt; // Right pointer points to itself initially

        if (!T) Thrt->lchild = Thrt; // If the binary tree is empty
        else {
            Thrt->lchild = T; pre = Thrt;
            InThreading(T); // In-order traversal with in-order threading
            pre->RTag = Thread; // Process the last node
            pre->rchild = Thrt;
            Thrt->rchild = pre; // Head node's right pointer points to the last node
        }
        return OK;
    }
    ```

#### **3. 遍历线索二叉树 (Slides 120-121)**
*   **代码 (中序遍历中序线索二叉树):**
    ```c
    void InOrderTraverse_Thr(BiThrTree T, void (*Visit)(TElemType e)) {
        // T points to the head node
        BiThrTree p = T->lchild; // p points to the root node
        while (p != T) {
            while (p->LTag==Link) p=p->lchild; // Find the first node
            Visit(p->data);
            
            while (p->RTag==Thread && p->rchild!=T) {
                p = p->rchild; 
                Visit(p->data); // Visit successor nodes
            }
            p = p->rchild; // p advances to its right child root
        }
    }
    ```

---

### **第五部分：树、森林与转换 (Slides 126-158)**

#### **1. 树的存储结构 (Slides 128-143)**

*   **1. 双亲表示法 (Parental expression - Slides 129-131)**
    *   数组存储，每个节点记录父节点下标。
    *   **C 语言描述 (Slide 130):**
        ```c
        #define MAX_TREE_SIZE 100
        typedef struct PTNode { // Node structure
            Elem data;
            int parent; // Parent position field
        } PTNode; 

        typedef struct { // Tree structure
            PTNode nodes[MAX_TREE_SIZE];
            int r, n; // root node position and node count
        } PTree;
        ```

*   **2. 孩子表示法 (Childrens expressions - Slides 132-133)**
    *   每个节点包含多个指针域，指向各子树的根。存在空间浪费问题。

*   **3. 孩子链表表示法 (Child list representation - Slides 134-138)**
    *   数组+链表。节点存入数组，每个节点有一个指针指向它的孩子链表。
    *   **C 语言描述 (Slides 136-137):**
        ```c
        // Child node structure
        typedef struct CTNode {
            int child; // child index in the array
            struct CTNode *next;
        } * ChildPtr;

        // Parent-child node structure (in the array)
        typedef struct {
            Elem data;
            ChildPtr firstchild; // Head pointer of the child chain
        } CTBox;

        // Tree structure
        typedef struct {
            CTBox nodes[MAX_TREE_SIZE];
            int n, r; // Number of nodes and root node position
        } CTree;
        ```
    *   **例题 16:** Slide 135 和 Slide 138 分别展示了孩子链表和带双亲的孩子链表的存储图。

*   **4. 孩子兄弟表示法 (Binary tree linked list - Slides 139-143)**
    *   物理结构等同于二叉链表。`lchild` -> `firstchild`, `rchild` -> `nextsibling`。
    *   **C 语言描述 (Slide 140):**
        ```c
        typedef struct CSNode {
            Elem data;
            struct CSNode *firstchild, *nextsibling;
        } CSNode, *CSTree;
        ```
    *   **例题 17 (Slide 141):** 展示了一棵普通树如何用孩子兄弟表示法转换成一棵二叉树，以及其二叉链表存储形式。

#### **2. 树、森林与二叉树的转换 (Slides 144-148)**

*   **森林转二叉树规则:**
    1.  将森林中每棵树用孩子兄弟表示法转成二叉树。
    2.  将第 i 棵树的根，作为第 i-1 棵树的根的右兄弟连接起来。
*   **二叉树转森林规则:**
    1.  从根节点开始，所有右孩子链上的节点都成为森林中各棵树的根。
    2.  对每个根的左子树，递归应用此规则。
*   **例题 18 (Slide 146 & 148):** 详细图解了一个包含三棵树的森林与一棵二叉树之间的相互转换过程。

#### **3. 树与森林的遍历 (Slides 149-158)**

*   **树的遍历 (Slide 151):**
    *   **先根遍历:** 根 -> 依次遍历各子树 (等价于对应二叉树的**前序遍历**)。
    *   **后根遍历:** 依次遍历各子树 -> 根 (等价于对应二叉树的**中序遍历**)。
    *   **按层遍历:** 从上到下，从左到右。
*   **例题 19: 树的遍历 (Slide 152)**
    *   先根遍历: `A B E F C D G H I J K`
    *   后根遍历: `E F B C I J K H G D A`
    *   按层遍历: `A B C D E F G H I J K`
*   **森林的遍历 (Slides 153-155):**
    *   **先序遍历:** 访问第一棵树的根 -> 先序遍历第一棵树的子树森林 -> 先序遍历剩余森林 (等价于对应二叉树的**前序遍历**)。
    *   **中序遍历:** 中序遍历第一棵树的子树森林 -> 访问第一棵树的根 -> 中序遍历剩余森林 (等价于对应二叉树的**中序遍历**)。
*   **应用: 求树的深度 (孩子兄弟表示法 - Slide 158)**
    ```c
    int TreeDepth(CSTree T) {
        int h1, h2;
        if(!T) return 0;
        else {
            h1 = TreeDepth( T->firstchild );  // 深度是孩子的深度+1
            h2 = TreeDepth( T->nextsibling); // 兄弟的深度与当前节点无关
            return(max(h1+1, h2));
        }
    }
    ```

---

### **第六部分：Huffman树与编码 (Slides 159-173)**

#### **1. 定义 (Slides 161-163)**
*   **带权路径长度 WPL (Weighted Path Length):** 所有叶子节点的 (权值 × 到根的路径长度) 之和。
*   **Huffman 树 (最优二叉树):** 给定n个权值，WPL 最小的二叉树。

#### **例题 20: 计算 WPL (Slide 162)**
给定叶子节点 a, b, c, d，权值为 7, 5, 2, 4。
*   **树1:** WPL = 7*2 + 5*2 + 2*2 + 4*2 = 36
*   **树2:** WPL = 7*3 + 5*3 + 2*1 + 4*2 = 46
*   **树3:** WPL = 7*1 + 5*2 + 2*3 + 4*3 = 35 (此例中WPL最小)

#### **2. Huffman 树的构造算法 (Slide 167)**
1.  **初始化**: n 个权值构成 n 棵树的森林 F。
2.  **循环**:
    a. 在 F 中选出**权值最小**的两棵树。
    b. 合并它们成一棵新树，新树的权值为两者之和。
    c. 从 F 中删除旧树，加入新树。
3.  **结束**: 直到 F 中只剩一棵树。

#### **例题 21: 构造 Huffman 树 (Slides 168-169)**
*   **权值集合:** W = {5, 6, 2, 9, 7}
*   **构造过程:**
    1.  合并 2 和 5，得新树权值为 7。森林: {6, 9, 7, 7}
    2.  合并 6 和 7，得新树权值为 13。森林: {9, 7, 13}
    3.  合并 7 和 9，得新树权值为 16。森林: {13, 16}
    4.  合并 13 和 16，得新树权值为 29。构造完成。
*   最终的 Huffman 树图示在 Slide 169。

#### **3. Huffman 编码 (Slides 170-173)**
*   **前缀编码:** 任何编码都不是其他编码的前缀。
*   **构造方法:**
    1.  用字符频率作权值构造 Huffman 树。
    2.  约定左分支为 0，右分支为 1。
    3.  从根到每个叶子节点的路径即为该字符的编码。
*   **例题 22: Huffman 编码 (Slide 173)**
    *   对例题21中的树进行编码:
        *   权值 6 (00)
        *   权值 7 (01)
        *   权值 9 (10)
        *   权值 5 (110)
        *   权值 2 (111)