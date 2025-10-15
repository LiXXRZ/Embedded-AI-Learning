好的，遵照您的指示。我已将前两份笔记的所有内容（包括每一行代码）进行整合，并进行了排版优化，以便于您进行高效的考前复习。

这是一份结合了所有幻灯片信息的、排版精良的终极备考笔记。

---

### **备考笔记：队列 (Comprehensive Exam Notes: Queues)**

#### **1. 核心概念 (Core Concepts)**

> **Stacks and Queues:** Both are linear lists with restricted operations on their endpoints.
> *栈和队列：* 两者都是操作受限于端点的线性表。

> **Stack (栈):** Operates on a **Last-In, First-Out (LIFO)** principle. Insertions (push) and deletions (pop) occur at the same end, called the **top**.
> *栈 (Stack)：* 遵循 **“后进先出” (LIFO)** 原则。插入（入栈）和删除（出栈）都在同一端（**栈顶**）进行。

> **Queue (队列):** Operates on a **First-In, First-Out (FIFO)** principle. Insertions (enqueue) occur at one end (**rear**), and deletions (dequeue) occur at the other end (**front**).
> *队列 (Queue)：* 遵循 **“先进先出” (FIFO)** 原则。插入（入队）在一端（**队尾**）进行，删除（出队）在另一端（**队头**）进行。

---

#### **2. 队列的抽象数据类型 (Queue as an Abstract Data Type - ADT)**

> **Data Object (数据对象):**
> A set of elements, D = {aᵢ | aᵢ ∈ ElemSet, i=1, 2, ..., n, n≥0}.
> *元素集合 D = {aᵢ | aᵢ ∈ ElemSet, i=1, 2, ..., n, n≥0}。*

> **Data Relationships (数据关系):**
> A linear relationship where a₁ is the **head** and aₙ is the **tail**.
> *元素间呈线性关系，其中 a₁ 是**队头**，aₙ 是**队尾**。*

> **Basic Operations (基本操作):**
> - **`InitQueue(&Q)`:** Constructs an empty queue Q.
>   *构造一个空队列 Q。*
> - **`DestroyQueue(&Q)`:** Destroys an existing queue Q.
>   *销毁已存在的队列 Q。*
> - **`QueueEmpty(Q)`:** Checks if the queue is empty. Returns `TRUE` if it is, `FALSE` otherwise.
>   *判断队列是否为空。若为空则返回 `TRUE`，否则返回 `FALSE`。*
> - **`QueueLength(Q)`:** Returns the number of elements in the queue.
>   *返回队列中元素的数量。*
> - **`GetHead(Q, &e)`:** Retrieves the head element of the queue without deleting it.
>   *获取队头元素，但不删除它。*
> - **`ClearQueue(&Q)`:** Clears all elements from the queue, making it empty.
>   *清除队列中的所有元素，使其变为空队列。*
> - **`EnQueue(&Q, e)`:** Inserts element `e` at the rear of the queue.
>   *在队尾插入元素 `e`。*
> - **`DeQueue(&Q, &e)`:** Removes the element at the front of the queue and returns it.
>   *删除队头元素并返回它。*
> - **`QueueTravers(Q, visit())`:** Traverses the queue from front to rear, applying a function to each element.
>   *从队头到队尾遍历队列，并对每个元素执行指定操作。*

---

#### **3. 队列的实现方式 (Implementations of Queues)**

##### **3.1 顺序存储实现 (Sequential Implementation)**

###### **A. 普通顺序队列 (Non-Cyclic Sequential Queue)**

> **Concept:** Uses a one-dimensional array and two pointers, `front` and `rear`.
> *概念：* 使用一个一维数组和两个指针 `front` 和 `rear`。
> - `front`: Points to the position of the head element. (*指向队头元素的位置。*)
> - `rear`: Points to the next available position after the tail element. (*指向队尾元素之后的下一个可用位置。*)

> **C Language Definition & Example:**
> *C 语言定义与示例：*
> ```c
> // General Definition (通用定义)
> #define MAXQSIZE n
> typedef struct {
>     elemtype queue[MAXQSIZE];
>     int front, rear;
> } sequeuetp;
> 
> // Example from slides (幻灯片示例)
> #define MAXQSIZE 8
> typedef struct {
>     char queue[MAXQSIZE];
>     int front, rear;
> } sequeuetp;
> sequeuetp Q;
> ```

> **Core Algorithms:**
> *核心算法：*
> ```c
> // Initialization (初始化)
> void initqueue(sequeuetp Q) {
>     Q.front = 0;
>     Q.rear = 0;
> }
> 
> // Enqueue (入队)
> status enqueue(sequeuetp &Q, elemtype x) {
>     if (Q.rear == MAXSIZE) return error; // Queue is full (队满)
>     Q.queue[Q.rear++] = x;
>     return ok;
> }
> 
> // Dequeue (出队)
> status delqueue(sequeuetp &Q, elemtype &e) {
>     if (Q.front == Q.rear) return (NULL); // Queue is empty (队空)
>     e = Q.queue[Q.front++];
>     return OK;
> }
> ```

> **Key Problem: False Overflow (假溢出)**
> *核心问题：假溢出*
> - Occurs when `Q.rear == MAXSIZE`, preventing new enqueues, even if there is empty space at the beginning of the array from previous dequeues.
>   *当 `Q.rear == MAXSIZE` 时，即使数组前端因出队操作而有空闲空间，也无法再入队新元素。*

###### **B. 循环队列 (Circular Queue)**

> **Concept:** Solves false overflow by treating the array as a circle. The most common method sacrifices one array slot to distinguish between a full and empty queue.
> *概念：* 将数组看作一个环，以解决假溢出问题。最常用的方法是牺牲一个数组空间来区分队满和队空状态。

> **State Conditions (状态判断条件):**
> - **Empty:** `Q.front == Q.rear`
>   *队空：* `Q.front == Q.rear`
> - **Full:** `(Q.rear + 1) % MAXSIZE == Q.front`
>   *队满：* `(Q.rear + 1) % MAXSIZE == Q.front`

> **Core Algorithms:**
> *核心算法：*
> ```c
> // Enqueue (入队)
> status encycque(sequeuetp Q, elemtype x) {
>     if ((Q.rear + 1) % MAXSIZE == Q.front) {
>         return error; // Queue is full (队满)
>     }
>     Q.queue[Q.rear] = x;
>     Q.rear = (Q.rear + 1) % MAXSIZE; // Rear pointer moves forward circularly
>     return OK;
> }
> 
> // Dequeue (出队)
> status delcycque(sequeuetp &Q, elemtype &e) {
>     if (Q.front == Q.rear) {
>         return(NULL); // Queue is empty (队空)
>     }
>     e = Q.queue[Q.front];
>     Q.front = (Q.front + 1) % MAXSIZE; // Front pointer moves forward circularly
>     return OK;
> }
> ```

##### **3.2 链式存储实现 (Linked Implementation)**

> **Concept:** Uses a linked list with a head node. `front` points to the head node, and `rear` points to the last actual element node (the tail).
> *概念：* 使用带头结点的链表实现。`front` 指针指向头结点，`rear` 指针指向最后一个真实元素节点（队尾）。

> **C Language Definition:**
> *C 语言定义：*
> ```c
> // Node Structure (节点结构)
> typedef struct qnode {
>     elemtype data;
>     struct qnode *next;
> } *queueptr;
> 
> // Queue Structure (队列结构)
> typedef struct {
>     queueptr front;
>     queueptr rear;
> } linkqueue;
> ```

> **Core Algorithms:**
> *核心算法：*
> ```c
> // Initialization (初始化)
> void initqueue(linkqueue &Q) {
>     Q.front = (queueptr)malloc(sizeof(qnode)); // Create head node (创建头结点)
>     if (!Q.front) exit(OVERFLOW);
>     Q.rear = Q.front;
>     Q.front->next = NULL;
> }
> 
> // Destroy Queue (销毁队列)
> Status DestroyQueue(LinkQueue &Q) {
>     while(Q.front) {
>         Q.rear = Q.front->next;
>         free(Q.front);
>         Q.front = Q.rear;
>     }
>     return OK;
> }
> 
> // Enqueue (入队)
> void enqueue(linkqueue &Q, elemtype x) {
>     p = (queueptr)malloc(sizeof(qnode)); // Create new node (创建新节点)
>     if (!p) exit(OVERFLOW);
>     p->data = x;
>     p->next = NULL;
>     Q.rear->next = p; // Link the new node to the tail (将新节点链接到队尾)
>     Q.rear = p;       // Update rear pointer (更新队尾指针)
> }
> 
> // Dequeue (出队)
> status delqueue(linkqueue Q) {
>     if (Q.front == Q.rear) return NULL; // Queue is empty (队空)
>     
>     p = Q.front->next;         // p points to the first element (p 指向第一个元素)
>     x = p->data;               // Store its data (保存其数据)
>     Q.front->next = p->next;   // Unlink the node (将节点从链中断开)
>     
>     // If the queue becomes empty after deletion, reset the rear pointer
>     // 如果删除后队列变空，重置 rear 指针
>     if (Q.rear == p) {
>         Q.rear = Q.front;
>     }
>     
>     free(p); // Release memory (释放内存)
>     return OK;
> }
> ```

---

#### **4. 应用：k阶斐波那契序列 (Application: k-order Fibonacci sequence)**

> **Problem:** Use a circular queue to compute the k-order Fibonacci sequence.
> *问题：* 使用循环队列计算k阶斐波那契序列。
>
> **Definition (定义):**
> - f₀=0, f₁=0, ..., fₖ₋₂=0, fₖ₋₁=1
> - fₙ = fₙ₋₁ + fₙ₋₂ + ... + fₙ₋ₖ  (for n ≥ k)
>
> **Simplified Formula (简化公式):** `fᵢ₊₁ = 2*fᵢ - fᵢ₋ₖ`

> **Method 1: Summation (Capacity k)**
> *方法1: 求和法 (队列容量为 k)*
> ```c
> void fb(int k, int max) {
>     for(i=0; i<=k-2; i++) { f[i]=0; cq.elem[i]=0; }
>     cq.elem[k-1]=1; cq.rear=k-1; n=k;
>     while(cq.elem[cq.rear] < max) {
>         f[n]=0;
>         for(j=0; j<k; j++) f[n] = f[n] + cq.elem[j];
>         cq.rear = (cq.rear + 1) % k;
>         cq.elem[cq.rear] = f[n];
>         n++;
>     }
>     if(cq.elem[cq.rear] > max) n=n-2; else n=n-1;
>     if (max==1) {n=k; f[k]=1;}
> }
> ```

> **Method 2: Simplified Formula (Capacity k+1)**
> *方法2: 简化公式法 (队列容量为 k+1)*
> ```c
> void fb(int k, int max) {
>     for(i=0; i<=k-2; i++) { f[i]=0; cq.elem[i]=0; }
>     cq.elem[k-1] = cq.elem[k] = 1;
>     cq.rear=k; n=k+1; f[k-1]=f[k]=1;
>     while(cq.elem[cq.rear] < max) {
>         j = (cq.rear + 1) % (k+1);
>         f[n] = cq.elem[cq.rear]*2 - cq.elem[j];
>         cq.elem[j] = f[n];
>         cq.rear = j;
>         n++;
>     }
>     if(cq.elem[cq.rear] > max) n=n-2; else n=n-1;
>     if (max==1) {n=k; f[k]=1;}
>     if (max==0) n=k-2;
> }
> ```