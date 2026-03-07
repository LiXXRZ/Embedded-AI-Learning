# 数据结构笔记：第九章 查找 (Search)

## 1. 基本概念 (Basic Concepts)

### 1.1 查找表 (Search Table)
*   **定义**：同一类型的数据元素（或记录）的集合。
*   **特点**：数据元素之间关系松散，通常只需通过关键字识别。
*   **常见操作**：
    1.  **查询 (Query)**：判断某个特定数据元素是否存在。
    2.  **检索 (Retrieve)**：获取特定数据元素的属性。
    3.  **插入 (Insert)**：将新元素加入表中。
    4.  **删除 (Delete)**：从表中移除元素。

### 1.2 查找表的分类
1.  **静态查找表 (Static Search Table)**：仅执行“查询”和“检索”操作。
2.  **动态查找表 (Dynamic Search Table)**：在查找过程中可能进行“插入”（若不存在）或“删除”（若存在）操作。

### 1.3 关键字 (Keyword)
*   **关键字 (Key)**：数据元素中用于识别该元素的某个数据项的值。
*   **主关键字 (Primary Key)**：能**唯一**标识一个记录的关键字。
*   **次关键字 (Secondary Key)**：能标识**一组**记录的关键字（不唯一）。

### 1.4 查找结果
*   **查找成功**：表中存在关键字等于给定值的记录，返回该记录信息或位置。
*   **查找失败**：表中不存在该记录，返回“空记录”或“空指针”。

---

## 2. 静态查找表 (Static Search Tables)

### 2.1 数据结构定义
静态查找表通常使用**顺序表**（数组）存储。

**宏定义（用于关键字比较）：**
```c
// 数值型关键字
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

// 字符串型关键字
#define EQ(a, b) (!strcmp((a), (b)))
#define LT(a, b) (strcmp((a), (b)) < 0)
#define LQ(a, b) (strcmp((a), (b)) <= 0)
```

**结构体定义：**
```c
typedef struct {
    keyType key;      // 关键字域
    // ... 其他属性域
} ElemType;

typedef struct {
    ElemType *elem;   // 数据元素存储基址 (0号单元留空，作为哨兵)
    int length;       // 表长度
} SSTable;
```

---

### 2.2 顺序查找 (Sequential Search)
**基本思想**：从表的一端向另一端逐个比对。

#### 算法一：从前向后查找 (基础版)
```c
int location(SqList L, ElemType& e, Status (*compare)(ElemType, ElemType)) {
    k = 1;
    p = L.elem;
    while (k <= L.length && !(*compare)(*p++, e))
        k++;
    if (k <= L.length) return k;
    else return 0;
}
```

#### 算法二：从后向前查找 (带“哨兵”优化版)
**核心技巧**：将 `ST.elem[0]` 设置为待查找的关键字。这样循环中不需要每次判断 `i >= 0`，因为当 `i=0` 时肯定会因为相等而退出循环。
**优势**：当表长 > 1000 时，可减少一半的平均查找时间（省去了越界判断）。

```c
int Search_Seq(SSTable ST, KeyType key) {
    // 在顺序表ST中顺序查找关键字等于key的数据元素
    // 若找到，返回其在表中的位置，否则返回0
    ST.elem[0].key = key;  // 设置“哨兵”
    int i;
    for (i = ST.length; ST.elem[i].key != key; --i); 
    // 从后往前找，找不到时 i 会最终停在 0
    return i; 
}
```

#### 性能分析 (ASL - Average Search Length)
*   查找成功时的 ASL：
    $$ASL_{ss} = \frac{1}{n} \sum_{i=1}^{n} (n - i + 1) = \frac{n + 1}{2}$$
*   查找失败时的比较次数：$n + 1$。
*   时间复杂度：$O(n)$。

---

### 2.3 有序表的二分查找 (Binary Search / Sorted Table)
**前提条件**：
1.  表中的元素按关键字**有序**（通常是升序）。
2.  必须采用**顺序存储结构**。

**基本思想**：将给定值与表中中间位置的关键字比较，若相等则成功；若给定值小于中间值，则在前半区查找；否则在后半区查找。

#### 二分查找算法代码
```c
int Search_Bin(SSTable ST, KeyType key) {
    int low = 1; 
    int high = ST.length; // 初始搜索区间
    int mid;
    
    while (low <= high) {
        mid = (low + high) / 2; // 向下取整
        if (EQ(key, ST.elem[mid].key))
            return mid;   // 找到元素
        else if (LT(key, ST.elem[mid].key))
            high = mid - 1; // 继续在前半区间查找
        else 
            low = mid + 1;  // 继续在后半区间查找
    }
    return 0; // 未找到
}
```

#### 性能分析
*   **判定树 (Decision Tree)**：二分查找的过程可以用一棵二叉树描述。
    *   **内部节点 (圆)**：表示表中记录，值为该记录的位置。
    *   **查找成功**：比较次数不超过判定树的深度。
    *   **查找失败**：路径从根到外部节点（方框），次数不超过 $\lfloor \log_2 n \rfloor + 1$。
*   **ASL (当 n > 50 时)**：
    $$ASL_{bs} \approx \log_2(n+1) - 1$$
*   时间复杂度：$O(\log n)$。

---

## 3. 动态查找表：二叉排序树 (Binary Search Tree, BST)

### 3.1 定义
二叉排序树要么是一棵空树，要么是具有以下性质的二叉树：
1.  若左子树不空，则左子树上所有节点的值均**小于**根节点的值。
2.  若右子树不空，则右子树上所有节点的值均**大于**根节点的值。
3.  其左右子树也分别为二叉排序树。

**存储结构 (二叉链表)：**
```c
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;
```

---

### 3.2 BST 的查找算法
**思路**：递归查找。若相等则返回；若小于则查左子树；若大于则查右子树。

**代码实现：**
```c
/*
 * T: 当前根节点指针
 * key: 待查找关键字
 * f: T的父节点指针 (初始调用为NULL)
 * p: 输出参数。若查找成功，p指向该数据元素节点；若失败，p指向查找路径上访问的最后一个节点。
 */
Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree &p) {
    if (!T) { 
        p = f; 
        return FALSE; // 查找失败
    }
    else if (EQ(key, T->data.key)) { 
        p = T; 
        return TRUE;  // 查找成功
    }
    else if (LT(key, T->data.key))
        return SearchBST(T->lchild, key, T, p); // 在左子树继续查找
    else 
        return SearchBST(T->rchild, key, T, p); // 在右子树继续查找
}
```

---

### 3.3 BST 的插入算法
**规则**：
*   插入操作仅在**查找不成功**时进行。
*   新插入的节点一定是一个**叶子节点**。
*   不需要移动其他节点，只需修改指针。

**代码实现：**
```c
Status InsertBST(BiTree &T, ElemType e) {
    BiTree p, s;
    // 查找失败时才插入 (p 将指向查找路径上最后一个节点，即待插入位置的父节点)
    if (!SearchBST(T, e.key, NULL, p)) {
        s = (BiTree)malloc(sizeof(BiTNode)); // 分配新节点空间
        s->data = e;
        s->lchild = s->rchild = NULL;
        
        if (!p) 
            T = s; // 原树为空，新节点作为根节点
        else if (LT(e.key, p->data.key))
            p->lchild = s; // 插入为左孩子
        else 
            p->rchild = s; // 插入为右孩子
        return TRUE; // 插入成功
    }
    else 
        return FALSE; // 树中已有同关键字节点，不插入
}
```

---

### 3.4 BST 的删除算法
**难点**：删除节点后必须保持二叉排序树的特性。
**三种情况**：
1.  **叶子节点**：直接删除，修改父节点指针为 NULL。
2.  **仅有左子树或仅有右子树**：删除该节点，将其子树“托付”给父节点（子承父业）。
3.  **既有左子树又有右子树**：
    *   找到该节点的**直接前驱**（左子树中最大的节点）或**直接后继**。
    *   用前驱的值替换当前节点的值。
    *   删除那个前驱节点（前驱节点一定属于情况1或情况2）。

**主删除函数：**
```c
Status DeleteBST(BiTree &T, KeyType key) {
    if (!T) return FALSE; // 未找到
    else {
        if (EQ(key, T->data.key)) {
            return Delete(T); // 找到关键字，执行删除
        }
        else if (LT(key, T->data.key))
            return DeleteBST(T->lchild, key); // 左递归
        else 
            return DeleteBST(T->rchild, key); // 右递归
    }
}
```

**核心删除逻辑 (`Delete` 函数)：**
```c
void Delete(BiTree &p) {
    // 从二叉排序树中删除节点 p，并重接其左或右子树
    BiTree q, s;
    
    if (!p->rchild) { 
        // 右子树为空，只需重接左子树
        q = p; 
        p = p->lchild; 
        free(q);
    }
    else if (!p->lchild) { 
        // 左子树为空，只需重接右子树
        q = p; 
        p = p->rchild; 
        free(q);
    }
    else { 
        // 左右子树均不空
        q = p; 
        s = p->lchild; 
        while (s->rchild) { // 转左，然后向右走到尽头（找直接前驱）
            q = s; 
            s = s->rchild; 
        }
        
        p->data = s->data; // 用前驱 s 的数据顶替 p 的数据
        
        if (q != p) 
            q->rchild = s->lchild; // 重接 *q 的右子树
        else 
            q->lchild = s->lchild; // 特殊情况：p的左孩子没有右子树，重接 *q 的左子树
            
        free(s); // 释放前驱节点 s
    }
}
```

---

## 4. 性能分析与结论

### 4.1 二叉排序树的性质
*   一个无序序列可以通过构建二叉排序树变成一个有序序列（中序遍历 BST 得到有序序列）。
*   构造 BST 的过程本质上是一个排序过程。
*   **优势**：适合频繁进行插入和删除操作的有序表（无需移动大量元素，只需改指针）。

### 4.2 ASL 分析
*   BST 的形态取决于插入关键字的顺序。
    *   **最好情况**：树形结构接近完全二叉树，ASL 约为 $\log_2 n$。
    *   **最坏情况**：输入序列有序（如 1, 2, 3, 4, 5），树退化为单支树（线性链表），ASL 退化为 $(n+1)/2$，即 $O(n)$。
*   **平均情况**（随机序列）：
    $$P(n) \approx 2 \ln n \approx 1.38 \log_2 n$$
    即平均查找性能接近二分查找，但维护成本（插入/删除）更低。