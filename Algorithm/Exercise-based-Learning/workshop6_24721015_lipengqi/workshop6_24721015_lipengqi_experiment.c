#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 为了能用 true 和 false

// 定义图里最多能存多少个顶点。
// 就像定义教室里最多坐20个学生，防止后面数组越界。
#define MAX_VERTICES 20

/* 
 * ========================================================
 * 第一部分：定义数据结构 (就像画建筑图纸)
 * ========================================================
 */

// --- 1. 邻接矩阵 (Adjacency Matrix) ---
// 原理：用一个二维表格存图。1代表通，0代表不通。
// 优点：找邻居快。缺点：点多边少时浪费空间。
typedef struct {
    int vertices[MAX_VERTICES];           // 存顶点的名字（比如0, 1, 2...）
    int edge[MAX_VERTICES][MAX_VERTICES]; // 二维数组，edge[i][j]=1 表示 i和j 连通
    int numVertices;                      // 现在图里一共有几个点
    int numEdges;                         // 现在图里一共有几条边
} GraphMatrix;

// --- 2. 邻接表 (Adjacency List) ---
// 原理：每个顶点领一个“小本本”（链表），上面写着所有朋友的名字。
// 优点：省空间。

// 链表的小节点
typedef struct Node {
    int dest;             // 邻居的编号
    struct Node* next;    // 指向下一个邻居的指针
} Node;

// 链表的头（小本本的封面）
typedef struct {
    Node* head;           // 指向链表第一个节点的指针
} AdjList;

// 邻接表图的主体
typedef struct {
    AdjList array[MAX_VERTICES]; // 一个数组，每个格子存一个链表头
    int numVertices;             // 顶点数
    int numEdges;                // 边数
} GraphList;

// --- 3. 队列 (Queue) ---
// 用于 BFS (广度优先搜索)。就像食堂打饭排队，先来先服务。
typedef struct {
    int items[MAX_VERTICES]; // 存排队的人
    int front;               // 队头（出口）
    int rear;                // 队尾（入口）
} Queue;

// --- 全局变量 ---
// 记录顶点是否被访问过，防止在图里转圈圈（死循环）。
// visited[0] = true 表示顶点0已经去过了。
bool visited[MAX_VERTICES];

/* 
 * ========================================================
 * 第二部分：辅助工具函数 (打杂的)
 * ========================================================
 */

// 每次开始新的遍历前，都要把“已访问”的记录清零，假装大家都没去过。
void resetVisited() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }
}

// --- 队列操作 (不用死记，知道是排队就行) ---

// 初始化队列
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 检查队伍是不是空的
bool isEmpty(Queue* q) {
    return q->rear == -1;
}

// 入队 (Enqueue)：有人来排队了
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return; // 队伍满了，不让进了
    if (q->front == -1) q->front = 0;        // 如果是第一个人，要把队头指针也设好
    q->rear++;
    q->items[q->rear] = value;               // 放到队尾
}

// 出队 (Dequeue)：叫号，队头的人走
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) return -1;               // 没人了
    item = q->items[q->front];               // 拿出队头的人
    q->front++;
    // 如果队头超过了队尾，说明人都走光了，重置队列
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

/* 
 * ========================================================
 * 第三部分：邻接矩阵的操作 (最直观的方法)
 * ========================================================
 */

// 初始化矩阵：先把所有格子填0，表示现在谁也不认识谁
void initGraphMatrix(GraphMatrix* g, int vertices) {
    g->numVertices = vertices;
    g->numEdges = 0;
    for (int i = 0; i < vertices; i++) {
        g->vertices[i] = i; // 顶点编号就是 0, 1, 2...
        for (int j = 0; j < vertices; j++) {
            g->edge[i][j] = 0; // 0 表示没边
        }
    }
}

// 加边：在表格里打钩 (设为1)
void addEdgeMatrix(GraphMatrix* g, int src, int dest) {
    // 因为是无向图，我有路到你，你也有路到我
    g->edge[src][dest] = 1; 
    g->edge[dest][src] = 1; 
    g->numEdges++;
}

// 打印矩阵：把二维数组打印出来给老师看
void printGraphMatrix(GraphMatrix* g) {
    printf("1. Adjacency Matrix Output (矩阵输出):\n");
    // 打印表头
    printf("   ");
    for(int i=0; i<g->numVertices; i++) printf("%d ", i);
    printf("\n");
    // 打印每一行
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i); // 行号
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->edge[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// --- 矩阵的 DFS (深度优先搜索) ---
// 核心思想：不撞南墙不回头。一条路走到黑，没路了再退回来。
void DFS_Matrix(GraphMatrix* g, int vertex) {
    // 1. 到了这个点，先标记“来过了”并打印
    visited[vertex] = true;
    printf("%d ", vertex); 

    // 2. 看看谁是我的邻居 (遍历这一行)
    for (int i = 0; i < g->numVertices; i++) {
        // 如果 edge[vertex][i]是1 (是邻居) 且 !visited[i] (还没去过)
        if (g->edge[vertex][i] == 1 && !visited[i]) {
            DFS_Matrix(g, i); // 【关键】递归调用：去那个邻居家里看看
        }
    }
}

// --- 矩阵的 BFS (广度优先搜索) ---
// 核心思想：地毯式搜索。先把周围一圈朋友看完，再看朋友的朋友。
void BFS_Matrix(GraphMatrix* g, int startVertex) {
    Queue q;
    initQueue(&q);

    // 1. 起点先标记，然后去排队
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("3. BFS Traverse (Matrix): ");
    
    // 只要队伍里还有人
    while (!isEmpty(&q)) {
        // 2. 叫号，取出队头的人
        int current = dequeue(&q);
        printf("%d ", current);

        // 3. 把他的所有“没去过”的邻居都拉进队伍
        for (int i = 0; i < g->numVertices; i++) {
            if (g->edge[current][i] == 1 && !visited[i]) {
                visited[i] = true; // 进队前就要标记，防止别人重复拉他进队
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

/* 
 * ========================================================
 * 第四部分：邻接表的操作 (省空间的方法)
 * ========================================================
 */

// 初始化邻接表：把所有链表的头指针都设为 NULL (空)
void initGraphList(GraphList* g, int vertices) {
    g->numVertices = vertices;
    g->numEdges = 0;
    for (int i = 0; i < vertices; i++) {
        g->array[i].head = NULL;
    }
}

// 这是一个造人的工厂：创建一个新的链表节点
Node* createNode(int dest) {
    // malloc 向电脑申请一块内存空间
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest; // 填上邻居的号码
    newNode->next = NULL; // 后面暂时没人
    return newNode;
}

// *** 加边：这里使用了最简单的【头插法】 ***
// 就像插队一样，新来的直接站到最前面。
// 注意：这样打印出来的邻居顺序是反的（后进先出），但这在图论里是完全正确的！
void addEdgeList(GraphList* g, int src, int dest) {
    // 1. 处理 src -> dest (把 dest 加到 src 的名单上)
    Node* newNode = createNode(dest);
    newNode->next = g->array[src].head; // 新节点的下家指向原来的第一名
    g->array[src].head = newNode;       // 原来的第一名变成了新节点

    // 2. 处理 dest -> src (无向图，对面也要加)
    newNode = createNode(src);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;

    g->numEdges++;
}

// 打印邻接表：顺藤摸瓜
void printGraphList(GraphList* g) {
    printf("4. Adjacency List Output (邻接表输出):\n");
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->array[i].head; // 拿到第i个人的名单头
        printf("Vertex %d:", i);
        // 只要后面还有人
        while (temp) {
            printf(" -> %d", temp->dest); // 打印名字
            temp = temp->next;            // 往后找下一个
        }
        printf(" -> NULL\n"); // 打印结束标志
    }
    printf("\n");
}

// --- 邻接表的 DFS ---
void DFS_List(GraphList* g, int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    // 顺着链表找邻居，找到一个没去过的就钻进去
    Node* temp = g->array[vertex].head;
    while (temp) {
        if (!visited[temp->dest]) {
            DFS_List(g, temp->dest); // 递归
        }
        temp = temp->next;
    }
}

// --- 邻接表的 BFS ---
void BFS_List(GraphList* g, int startVertex) {
    Queue q;
    initQueue(&q);

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("6. BFS Traverse (List): ");
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        // 邻接表的BFS和矩阵唯一的区别就是找邻居的方式不一样
        // 这里是顺着链表找邻居
        Node* temp = g->array[current].head;
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = true;
                enqueue(&q, temp->dest);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

/* 
 * ========================================================
 * 第五部分：主函数 (MAIN) - 程序的入口
 * ========================================================
 */
int main() {
    // 1. 准备工作：设置图的大小（这里设为5个点，编号0-4）
    int numVertices = 5;
    
    GraphMatrix gMatrix; // 声明矩阵图变量
    GraphList gList;     // 声明链表图变量
    
    // 初始化，把里面清空
    initGraphMatrix(&gMatrix, numVertices);
    initGraphList(&gList, numVertices);

    // 2. 构造图数据：这里我们硬编码一个示例图
    // 图的形状：
    //      0
    //    /   \
    //   1 --- 2
    //    \   /
    //      3
    //      |
    //      4
    // 边的集合：(0,1), (0,2), (1,2), (1,3), (2,3), (3,4)
    int edges[][2] = {
        {0, 1}, {0, 2}, 
        {1, 2}, {1, 3}, 
        {2, 3}, 
        {3, 4}
    };
    int edgeCount = 6;

    // 循环加边，同时往两种结构里加，方便后面做对比
    for (int i = 0; i < edgeCount; i++) {
        addEdgeMatrix(&gMatrix, edges[i][0], edges[i][1]);
        addEdgeList(&gList, edges[i][0], edges[i][1]);
    }

    printf("=== Graph Structure Experiment (图结构实验) ===\n\n");

    // Task 1 & 2: 矩阵的打印和DFS
    // ----------------------------------------------------
    printGraphMatrix(&gMatrix); // 打印矩阵样子
    
    resetVisited(); // 注意！只要重新遍历，一定要清空之前的访问记录！
    printf("2. DFS Traverse (Matrix): ");
    DFS_Matrix(&gMatrix, 0); // 从点0开始跑
    printf("\n\n");

    // Task 3: 矩阵的BFS
    // ----------------------------------------------------
    resetVisited(); // 清空记录
    BFS_Matrix(&gMatrix, 0);
    printf("\n\n");

    // Task 4 & 5: 邻接表的打印和DFS
    // ----------------------------------------------------
    printGraphList(&gList); // 打印链表样子
    
    resetVisited(); // 清空记录
    printf("5. DFS Traverse (List): ");
    DFS_List(&gList, 0);
    printf("\n\n");

    // Task 6: 邻接表的BFS
    // ----------------------------------------------------
    resetVisited(); // 清空记录
    BFS_List(&gList, 0);
    printf("\n");

    return 0; // 程序愉快地结束了
}