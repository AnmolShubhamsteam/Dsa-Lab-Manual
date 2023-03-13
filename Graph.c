#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 50

int adj_matrix[MAX_CITIES][MAX_CITIES]; 
int visited[MAX_CITIES]; 

void add_edge(int start, int end) {
    adj_matrix[start][end] = 1;
}

void create_graph(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    int num_edges;
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the starting and ending vertices of each edge:\n");
    for (i = 0; i < num_edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        add_edge(start, end);
    }
}
void printarray(int n){
    printf("____\n");
    printf("matrix rep \n");
    for (int i =0;i<n; i++)
    {
        for (int j = 0;j<n;j++)
        {
            printf("%d",adj_matrix[i][j]);
        }
        printf("\n");
    }    
}
void dfs(int start, int n) {
    visited[start] = 1;
    printf("%d ", start);
    int i;
    for (i = 0; i < n; i++) {
        if (adj_matrix[start][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int start, int n) {
    int queue[MAX_CITIES], front = -1, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (front != rear) {
        int node = queue[++front];
        printf("%d ", node);
        int i;
        for (i = 0; i < n; i++) {
            if (adj_matrix[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n, start;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    create_graph(n);
    printarray(n);
    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("Nodes reachable from starting node %d using DFS method: ", start);
    dfs(start, n);
    printf("\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Nodes reachable from starting node %d using BFS method: ", start);
    bfs(start, n);
    printf("\n");
    return 0;
}