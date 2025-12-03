#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义最大顶点数，防止溢出
#define MAX_VERTICES 20

/* 
 * ========================================================
 * 第一部分：数据结构定义 (Data Structures)
 * 就像盖房子要有图纸，存图先要定义结构。
 * ========================================================
 */

// --- 1. 邻接矩阵 (Adjacency Matrix) ---
// 原理：用一个二维表格存图。1代表通，0代表不通。
// 图例：
//    0 1 2
// 0 [0 1 1]  <- 0和1连，0和2连
// 1 [1 0 1]
// 2 [1 1 0]
typedef struct {
    int vertices[MAX_VERTICES];           // 存顶点的名字（比如0, 1, 2...）
    int edge[MAX_VERTICES][MAX_VERTICES]; // 二维数组，edge[i][j]=1 表示 i和j 有边
    int numVertices;                      // 顶点总数
    int numEdges;                         // 边总数
} GraphMatrix;

// --- 2. 邻接表 (Adjacency List) ---
// 原理：数组+链表。每个人领一个名单，写着他的朋友。
// 图例：
// [0] -> 1 -> 2 -> NULL  (0的朋友是1和2)
// [1] -> 0 -> 2 -> 3 -> NULL
typedef struct Node {
    int dest;             // 邻居的编号
    struct Node* next;    // 指向下一个邻居
} Node;

typedef struct {
    Node* head;           // 链表的头指针
} AdjList;

typedef struct {
    AdjList array[MAX_VERTICES]; // 这是一个数组，每个格子存一个链表头
    int numVertices;
    int numEdges;
} GraphList;

// --- 3. 队列 (Queue) ---
// 用于 BFS (广度优先搜索)。就像排队买饭，先来先服务。
typedef struct {
    int items[MAX_VERTICES];
    int front; // 队头
    int rear;  // 队尾
} Queue;

// 全局变量：记录顶点是否被访问过，防止转圈圈
// visited[0] = true 表示顶点0已经去过了
bool visited[MAX_VERTICES];

/* 
 * ========================================================
 * 第二部分：辅助工具函数 (Helper Functions)
 * ========================================================
 */

// 重置 visited 数组，每次遍历前都要把记录清零
void resetVisited() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }
}

// --- 队列操作 (不用深究，知道是排队就行) ---
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

// 入队 (排队)
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// 出队 (叫号)
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

/* 
 * ========================================================
 * 第三部分：邻接矩阵的相关操作
 * ========================================================
 */

// 初始化矩阵：先把所有格子填0
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
    g->edge[src][dest] = 1; // src -> dest 有路
    g->edge[dest][src] = 1; // dest -> src 也有路 (因为是无向图)
    g->numEdges++;
}

// 打印矩阵给老师看
void printGraphMatrix(GraphMatrix* g) {
    printf("1. Adjacency Matrix Output:\n");
    printf("   ");
    for(int i=0; i<g->numVertices; i++) printf("%d ", i);
    printf("\n");
    // 打印每一行
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->edge[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// --- 矩阵的 DFS (深度优先) ---
// 策略：一条道走到黑，撞墙了再回头。用“递归”实现。
void DFS_Matrix(GraphMatrix* g, int vertex) {
    // 1. 到了这个点，先标记“来过了”
    visited[vertex] = true;
    printf("%d ", vertex); // 打印出来

    // 2. 看看谁是我的邻居 (遍历这一行)
    for (int i = 0; i < g->numVertices; i++) {
        // 如果 edge[vertex][i]是1 (是邻居) 且 !visited[i] (没去过)
        if (g->edge[vertex][i] == 1 && !visited[i]) {
            DFS_Matrix(g, i); // 递归：去那个邻居家里看看
        }
    }
}

// --- 矩阵的 BFS (广度优先) ---
// 策略：先把周围一圈邻居看完，再看邻居的邻居。用“队列”实现。
void BFS_Matrix(GraphMatrix* g, int startVertex) {
    Queue q;
    initQueue(&q);

    // 1. 起点进队
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("3. BFS Traverse (Matrix): ");
    
    while (!isEmpty(&q)) {
        // 2. 取出队头的人
        int current = dequeue(&q);
        printf("%d ", current);

        // 3. 把他的所有没去过的邻居都拉进队伍
        for (int i = 0; i < g->numVertices; i++) {
            if (g->edge[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

/* 
 * ========================================================
 * 第四部分：邻接表的相关操作
 * ========================================================
 */

// 初始化邻接表：把头指针都设为 NULL
void initGraphList(GraphList* g, int vertices) {
    g->numVertices = vertices;
    g->numEdges = 0;
    for (int i = 0; i < vertices; i++) {
        g->array[i].head = NULL;
    }
}

// 创建一个新的链表节点
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 加边：向链表里加人
// 为了让结果好看（按从小到大排序），这里稍微写复杂了一丢丢
// 如果不管顺序直接插头，代码会简单，但打印出来是倒序的 (比如 0->2->1)
void addEdgeList(GraphList* g, int src, int dest) {
    // 1. 处理 src -> dest
    Node* newNode = createNode(dest);
    // 找到合适的位置插入（按从小到大排序），为了让作业输出好看
    if (g->array[src].head == NULL || g->array[src].head->dest >= dest) {
        newNode->next = g->array[src].head;
        g->array[src].head = newNode;
    } else {
        Node* current = g->array[src].head;
        while (current->next != NULL && current->next->dest < dest) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // 2. 处理 dest -> src (无向图，对面也要加)
    newNode = createNode(src);
    if (g->array[dest].head == NULL || g->array[dest].head->dest >= src) {
        newNode->next = g->array[dest].head;
        g->array[dest].head = newNode;
    } else {
        Node* current = g->array[dest].head;
        while (current->next != NULL && current->next->dest < src) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    g->numEdges++;
}

// 打印邻接表
void printGraphList(GraphList* g) {
    printf("4. Adjacency List Output:\n");
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->array[i].head;
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
    printf("\n");
}

// --- 邻接表的 DFS ---
void DFS_List(GraphList* g, int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    // 只要顺着链表找邻居就行了
    Node* temp = g->array[vertex].head;
    while (temp) {
        if (!visited[temp->dest]) {
            DFS_List(g, temp->dest);
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
    // 1. 设置图的大小（5个点）
    int numVertices = 5;
    
    GraphMatrix gMatrix; // 声明矩阵图
    GraphList gList;     // 声明链表图
    
    // 初始化
    initGraphMatrix(&gMatrix, numVertices);
    initGraphList(&gList, numVertices);

    // 2. 构造图数据
    // 我们手动把那个“风筝”形状的边加进去
    // (0,1), (0,2), (1,2), (1,3), (2,3), (3,4)
    int edges[][2] = {
        {0, 1}, {0, 2}, 
        {1, 2}, {1, 3}, 
        {2, 3}, 
        {3, 4}
    };
    int edgeCount = 6;

    // 循环加边，同时加到矩阵和链表里
    for (int i = 0; i < edgeCount; i++) {
        addEdgeMatrix(&gMatrix, edges[i][0], edges[i][1]);
        addEdgeList(&gList, edges[i][0], edges[i][1]);
    }

    printf("=== Graph Structure Experiment ===\n\n");

    // Task 1 & 2: 矩阵的打印和DFS
    printGraphMatrix(&gMatrix); // 打印矩阵
    
    resetVisited(); // 只要重新遍历，一定要清空访问记录！
    printf("2. DFS Traverse (Matrix): ");
    DFS_Matrix(&gMatrix, 0); // 从点0开始
    printf("\n\n");

    // Task 3: 矩阵的BFS
    resetVisited();
    BFS_Matrix(&gMatrix, 0);
    printf("\n\n");

    // Task 4 & 5: 邻接表的打印和DFS
    printGraphList(&gList); // 打印链表
    
    resetVisited();
    printf("5. DFS Traverse (List): ");
    DFS_List(&gList, 0);
    printf("\n\n");

    // Task 6: 邻接表的BFS
    resetVisited();
    BFS_List(&gList, 0);
    printf("\n");

    return 0;
}