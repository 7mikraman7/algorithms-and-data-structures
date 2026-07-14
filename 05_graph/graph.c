#include <stdio.h>
#include <stdlib.h>
#include "err.h"
#include "graph.h"
#include "lqueue.h"

#define EXIT_IF(cond) if (cond) exit(0)

/* ================== структура ================== */
struct GraphRecord {
    int adj[max][max];
    int visited[max];
    int nodes;
};

/* ================== 1. CreateGraph ================== */
Graph CreateGraph(int NodesCount) {
    if (NodesCount <= 0 || NodesCount > max)
        return NULL;

    Graph G = (Graph)malloc(sizeof(struct GraphRecord));
    if (!G) return NULL;

    G->nodes = NodesCount;
    for (int i = 0; i < max; i++) {
        G->visited[i] = 0;
        for (int j = 0; j < max; j++)
            G->adj[i][j] = 0;
    }
    return G;
}

/* ================== 2. DisposeGraph ================== */
void DisposeGraph(Graph G) {
    if (G) free(G);
}

/* ================== 3. buildadjm ================== */
void buildadjm(Graph G) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    int val;
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            if (scanf("%d", &val) != 1) val = 0;
            if (val != 0 && val != 1) val = 0;
            if (i == j) val = 0;
            G->adj[i][j] = val;
        }
    }
}

/* ================== 4. printadjm ================== */
void printadjm(Graph G) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            if (j) printf(" ");
            printf("%d", G->adj[i][j]);
        }
        printf("\n");
    }
}

/* ================== 5. ClearVisited ================== */
void ClearVisited(Graph G) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    for (int i = 0; i < G->nodes; i++)
        G->visited[i] = 0;
}

/* ================== 6. dfs ================== */
void dfs(Graph G, int v0) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    EXIT_IF(v0 < 0 || v0 >= G->nodes);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] < 0 || G->visited[i] > 2)
            G->visited[i] = 0;
        for (int j = 0; j < G->nodes; j++) {
            if (G->adj[i][j] != 0 && G->adj[i][j] != 1)
                G->adj[i][j] = 0;
            if (i == j)
                G->adj[i][j] = 0;
        }
    }

    ClearVisited(G);
    dfs2(G, v0);

    for (int i = 0; i < G->nodes; i++)
        if (G->visited[i] == 0)
            dfs2(G, i);
}

/* ================== 7. dfs2 ================== */
void dfs2(Graph G, int v) {
    G->visited[v] = 1;
    printf("The node opened: %d\n", v);
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0)
            dfs2(G, w);
    }
    G->visited[v] = 2;
}

/* ================== 8. dfsst ================== */
void dfsst(Graph G, int v0) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    EXIT_IF(v0 < 0 || v0 >= G->nodes);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] < 0 || G->visited[i] > 2)
            G->visited[i] = 0;
        for (int j = 0; j < G->nodes; j++) {
            if (G->adj[i][j] != 0 && G->adj[i][j] != 1)
                G->adj[i][j] = 0;
            if (i == j)
                G->adj[i][j] = 0;
        }
    }

    ClearVisited(G);
    dfsst2(G, v0);

    for (int i = 0; i < G->nodes; i++)
        if (G->visited[i] == 0)
            dfsst2(G, i);
}

/* ================== 9. dfsst2 ================== */
void dfsst2(Graph G, int v) {
    G->visited[v] = 1;
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge: (%d,%d)\n", v, w);
            dfsst2(G, w);
        }
    }
    G->visited[v] = 2;
}

/* ================== 10. bfs ================== */
void bfs(Graph G, int v0) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    EXIT_IF(v0 < 0 || v0 >= G->nodes);

    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 1;

    while (!IsEmptyQueue(Q)) {
        int v = FrontAndDequeue(Q);
        printf("The node opened: %d\n", v);
        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                Enqueue(w, Q);
                G->visited[w] = 1;
            }
        }
        G->visited[v] = 2;
    }
    RemoveQueue(&Q);

    for (int s = 0; s < G->nodes; s++) {
        if (G->visited[s] != 0) continue;
        Q = CreateQueue();
        Enqueue(s, Q);
        G->visited[s] = 1;
        while (!IsEmptyQueue(Q)) {
            int v = FrontAndDequeue(Q);
            printf("The node opened: %d\n", v);
            for (int w = 0; w < G->nodes; w++) {
                if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                    Enqueue(w, Q);
                    G->visited[w] = 1;
                }
            }
            G->visited[v] = 2;
        }
        RemoveQueue(&Q);
    }
}

/* ================== 11. bfsst ================== */
void bfsst(Graph G, int v0) {
    EXIT_IF(G == NULL);
    EXIT_IF(G->nodes <= 0 || G->nodes > max);
    EXIT_IF(v0 < 0 || v0 >= G->nodes);

    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 1;

    while (!IsEmptyQueue(Q)) {
        int v = FrontAndDequeue(Q);
        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                printf("Edge: (%d,%d)\n", v, w);
                Enqueue(w, Q);
                G->visited[w] = 1;
            }
        }
        G->visited[v] = 2;
    }
    RemoveQueue(&Q);

    for (int s = 0; s < G->nodes; s++) {
        if (G->visited[s] != 0) continue;
        Q = CreateQueue();
        Enqueue(s, Q);
        G->visited[s] = 1;
        while (!IsEmptyQueue(Q)) {
            int v = FrontAndDequeue(Q);
            for (int w = 0; w < G->nodes; w++) {
                if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                    printf("Edge: (%d,%d)\n", v, w);
                    Enqueue(w, Q);
                    G->visited[w] = 1;
                }
            }
            G->visited[v] = 2;
        }
        RemoveQueue(&Q);
    }
}
