这是一份基于《Graph Theory and Its Algorithms》课件的**超详细综合学习笔记**。我将概念解析与核心代码进行了深度整合，完全保留了课件中的逻辑结构、算法思想及C语言实现细节。

---

# 学习笔记：图论及其算法 (Graph Theory and Algorithms)
**主讲人:** Haiyang Liu (2025)

---

## 第一部分：图的基本概念 (Basic Concepts)

### 1.1 定义与分类
*   **图 (Graph):** 数据结构 $G=(V, VR)$，其中：
    *   $V$: 顶点(Vertices)的有穷非空集合。
    *   $VR$: 两个顶点之间的关系集合（弧或边）。
*   **有向图 (Directed Graph):** 边有方向，表示为 $<v, w>$。$v$ 为弧尾(tail)，$w$ 为弧头(head)。
*   **无向图 (Undirected Graph):** 边无方向，表示为 $(v, w)$，即 $(v, w)等同于(w, v)$。
*   **网 (Network):** 边/弧上带有数值（权值 Weight）的图。

### 1.2 关键术语
1.  **邻接 (Adjacency):** 若存在边 $(v, w)$ 或 $<v, w>$，则称 $v$ 和 $w$ 邻接。
2.  **度 (Degree):**
    *   **无向图:** 顶点 $v$ 的度 $TD(v)$ = 连接该顶点的边数。
    *   **有向图:** $TD(v)$ = 入度 $ID(v)$ (指向v) + 出度 $OD(v)$ (指出v)。
3.  **路径 (Path):** 顶点序列，相邻顶点间存在边。
    *   **简单路径:** 序列中顶点不重复出现。
    *   **回路/环 (Loop/Cycle):** 起点和终点相同的路径。
4.  **连通性 (Connectivity):**
    *   **连通图:** 无向图中任意两点间均有路径。
    *   **强连通图:** 有向图中任意两点双向可达。
    *   **连通分量:** 非连通图中的极大连通子图。
5.  **完全图 (Complete Graph):**
    *   无向：$n$ 个顶点有 $n(n-1)/2$ 条边。
    *   有向：$n$ 个顶点有 $n(n-1)$ 条弧。
6.  **生成树 (Spanning Tree):** 连通图的极小连通子图（$n$ 个顶点，仅 $n-1$ 条边）。

---

## 第二部分：图的存储结构 (Storage Structures)

### 2.1 预定义常量
```c
#define INFINITY INF_MAX       // 定义无穷大
#define MAX_VERTEX_NUM 20      // 最大顶点数
// 图的类型：{有向图, 有向网, 无向图, 无向网}
typedef enum {DG, DN, UDG, UDN} GraphKind;
```

### 2.2 邻接矩阵 (Adjacency Matrix)
*   **特点:** 使用二维数组存储。适用于**稠密图**。
*   **性质:** 无向图矩阵对称；有向图行和为出度，列和为入度。
*   **代码定义:**
```c
typedef struct ArcCell {
    VRType adj;      // 顶点关系类型。无权图用1/0，带权图存权值
    InfoType *info;  // 指向该弧相关信息的指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
    AdjMatrix arcs;                  // 邻接矩阵
    int vexnum, arcnum;              // 当前顶点数和弧数
    GraphKind kind;                  // 图的种类
} MGraph;
```

### 2.3 邻接表 (Adjacency List)
*   **特点:** 数组(头结点) + 链表(邻接点)。适用于**稀疏图**，节省空间。
*   **性质:** 容易求出度；求入度需遍历全表（或使用逆邻接表）。
*   **代码定义:**
```c
// 1. 边结点 (Arc Node)
typedef struct ArcNode {
    int adjvex;                 // 该弧指向的顶点位置(下标)
    struct ArcNode *nextarc;    // 指向下一条弧的指针
    InfoType *info;             // 弧的相关信息(如权值)
} ArcNode;

// 2. 顶点结点 (Vertex Node)
typedef struct VNode {
    VertexType data;            // 顶点信息
    ArcNode *firstarc;          // 指向第一条依附该顶点的弧
} VNode, AdjList[MAX_VERTEX_NUM];

// 3. 图结构
typedef struct {
    AdjList vertices;           // 头结点向量
    int vexnum, arcnum;         // 顶点数和弧数
    int kind;                   // 图种类
} ALGraph;
```

### 2.4 十字链表 (Orthogonal List)
*   **特点:** 有向图的优化存储，结合了邻接表和逆邻接表。容易同时求入度和出度。
*   **代码定义:**
```c
// 弧结点
typedef struct ArcBox {
    int tailvex, headvex;          // 弧尾、弧头位置
    InfoType *info;
    struct ArcBox *tlink, *hlink;  // tlink: 同弧尾的下一条; hlink: 同弧头的下一条
} ArcBox;

// 顶点结点
typedef struct VexNode {
    VertexType data;
    ArcBox *firstin, *firstout;    // firstin: 第一条入弧; firstout: 第一条出弧
} VexNode;

// 图结构
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM]; 
    int vexnum, arcnum;
} OLGraph;
```

---

## 第三部分：图的遍历 (Graph Traversal)
**核心:** 设置辅助数组 `visited[n]` 防止重复访问。

### 3.1 深度优先搜索 (DFS)
*   **思想:** 类比树的先序遍历。一条路走到黑，不通则回溯。
*   **代码实现:**
```c
// 全局辅助变量或参数
Boolean visited[MAX_VERTEX_NUM]; 

// 遍历主函数
void DFSTraverse(Graph G, Status (*Visit)(int v)) {
    VisitFunc = Visit; 
    for (v=0; v<G.vexnum; ++v) 
        visited[v] = FALSE; // 初始化
    
    for (v=0; v<G.vexnum; ++v) 
        if (!visited[v]) 
            DFS(G, v); // 对未访问节点调用DFS
}

// DFS递归核心
void DFS(Graph G, int v) {
    VisitFunction(v); visited[v] = TRUE; // 访问并标记
    
    // FirstAdjVex/NextAdjVex 为抽象的基本操作
    for (w = FirstAdjVex(G, v); w != 0; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) 
            DFS(G, w); // 递归
    }
}
```
*   **DFS应用:** 寻找简单路径 (DFS变种)
```c
void DFSearch(int v, int s, char *PATH) {
    visited[v] = TRUE; 
    Append(PATH, getVertex(v)); // 加入路径
    
    for (w=FirstAdjVex(v); w!=0 && !found; w=NextAdjVex(v,w)) {
        if (w == s) { 
            found = TRUE; Append(PATH, w); 
        } else if (!visited[w]) {
            DFSearch(w, s, PATH);
        }
    }
    if (!found) Delete(PATH); // 回溯清理
}
```

### 3.2 广度优先搜索 (BFS)
*   **思想:** 类比树的层序遍历。使用**队列**。
*   **代码实现:**
```c
void BFSTraverse(Graph G, Status (*Visit)(int v)) {
    for (v=0; v<G.vexnum; ++v) visited[v] = FALSE;
    InitQueue(Q); 
    
    for (v=0; v<G.vexnum; ++v) {
        if (!visited[v]) {
            visited[v] = TRUE; Visit(v);
            EnQueue(Q, v);
            
            while (!QueueEmpty(Q)) {
                DeQueue(Q, u);
                // 访问 u 的所有邻接点
                for(w=FirstAdjVex(G, u); w!=0; w=NextAdjVex(G, u, w)) {
                    if (!visited[w]) {
                        visited[w] = TRUE; Visit(w);
                        EnQueue(Q, w);
                    }
                }
            }
        }
    }
}
```

---

## 第四部分：最小生成树 (Minimum Spanning Tree)
**目标:** 连通网中权值之和最小的生成树。

### 4.1 Prim 算法 (普里姆算法)
*   **策略:** 加点法。适合**稠密图**。时间复杂度 $O(n^2)$。
*   **辅助结构 `closedge`:** 记录 V-U 集合中各顶点到 U 集合的最小权值边。
```c
struct {
    VertexType adjvex;  // U集合中的顶点下标
    VRType lowcost;     // 权值
} closedge[MAX_VERTEX_NUM];

void MiniSpanTree_P(MGraph G, VertexType u) {
    k = LocateVex(G, u);
    // 1. 初始化 closedge
    for (j=0; j<G.vexnum; ++j) 
        if (j!=k) closedge[j] = { u, G.arcs[k][j].adj };
    
    closedge[k].lowcost = 0; // 初始 U={u}
    
    // 2. 循环找 n-1 个顶点
    for (i=1; i<G.vexnum; ++i) {
        k = minimum(closedge); // 找权值最小的边所连的顶点 k
        printf(closedge[k].adjvex, G.vexs[k]); // 输出边
        
        closedge[k].lowcost = 0; // 将 k 加入 U
        
        // 3. 更新 closedge (关键步骤)
        for (j=0; j<G.vexnum; ++j) {
            if (G.arcs[k][j].adj < closedge[j].lowcost)
                closedge[j] = { G.vexs[k], G.arcs[k][j].adj };
        }
    }
}
```

### 4.2 Kruskal 算法 (克鲁斯卡尔算法)
*   **策略:** 加边法。适合**稀疏图**。时间复杂度 $O(e \log e)$。
*   **逻辑:** 将边按权值排序，依次选择不构成回路的最小边加入生成树。

---

## 第五部分：最短路径 (Shortest Paths)

### 5.1 单源最短路径 (Dijkstra 算法)
*   **策略:** 贪心策略，按路径长度递增次序产生最短路径。
*   **核心逻辑:**
    1.  初始化 `Dist[]` 数组。
    2.  选出 `Dist` 最小的未处理顶点 $j$。
    3.  **松弛操作 (Relaxation):** 检查经过 $j$ 到达 $k$ 是否更近。
        `if (Dist[j] + G.arcs[j][k] < Dist[k]) Dist[k] = Dist[j] + G.arcs[j][k];`
    4.  重复直到所有点被处理。

---

## 第六部分：拓扑排序 (Topological Sorting)

### 6.1 AOV 网 (Active On Vertex)
*   **定义:** 有向无环图 (DAG)，顶点代表活动，边代表优先关系。
*   **用途:** 判环、确定工序。

### 6.2 算法实现
*   **方法:** 维护一个**入度为0**的顶点栈。
```c
Status TopologicalSort(ALGraph G) {
    FindInDegree(G, indegree); // 统计入度
    InitStack(S);
    // 1. 所有入度为0的顶点入栈
    for (i=0; i<G.vexnum; ++i)
        if (!indegree[i]) Push(S, i);
        
    count = 0;
    while (!StackEmpty(S)) {
        Pop(S, v); 
        ++count; printf(v); // 输出
        
        // 2. 遍历邻接点，减小入度
        for (p=G.vertices[v].firstarc; p; p=p->nextarc) {
            k = p->adjvex;
            if (!(--indegree[k])) Push(S, k); // 入度变0则入栈
        }
    }
    return (count < G.vexnum) ? ERROR : OK; // count < n 说明有环
}
```

---

## 第七部分：关键路径 (Critical Path)

### 7.1 AOE 网 (Active On Edge)
*   **定义:** 带权有向无环图。边代表活动(持续时间)，顶点代表事件。
*   **关键概念:**
    *   **关键路径:** 从源点到汇点的最长路径。
    *   $ve(k)$: 事件最早发生时间 (拓扑序推导，取 Max)。
    *   $vl(k)$: 事件最迟发生时间 (逆拓扑序推导，取 Min)。
    *   $e(i)$: 活动最早开始 = 弧尾的 $ve$。
    *   $l(i)$: 活动最迟开始 = 弧头的 $vl$ - 活动持续时间。
    *   **关键活动:** $e(i) == l(i)$ 的活动。

### 7.2 算法实现
需要先修改拓扑排序算法以输出拓扑序列栈 `T`。

```c
Status CriticalPath(ALGraph G) {
    // 1. 拓扑排序求 ve，并获取拓扑序列栈 T
    if (!TopologicalOrder(G, T)) return ERROR; 
    
    // 初始化 vl 为汇点的 ve
    for (i=0; i<G.vexnum; i++) vl[i] = ve[G.vexnum-1]; 
        
    // 2. 逆拓扑排序求 vl
    while (!StackEmpty(T)) {
        for (Pop(T, j), p=G.vertices[j].firstarc; p; p=p->nextarc) {
            k = p->adjvex; dut = *(p->info);
            if (vl[k] - dut < vl[j]) vl[j] = vl[k] - dut; // 取最小值
        }
    }
    
    // 3. 判断关键活动
    for (j=0; j<G.vexnum; ++j) {
        for (p=G.vertices[j].firstarc; p; p=p->nextarc) {
            k = p->adjvex; dut = *(p->info);
            ee = ve[j];          // 活动最早
            el = vl[k] - dut;    // 活动最迟
            tag = (ee == el) ? '*' : ' '; // 相等即为关键活动
            printf(j, k, dut, ee, el, tag);
        }
    }
    return OK;
}
```