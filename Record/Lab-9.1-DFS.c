#include <stdio.h>

#define MAX 10

int a[MAX][MAX], vis[MAX], n;

void dfs(int v);
int isConnected();

void main() {
    int i, j;

    printf("Enter Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDFS Traversal: ");

    if (isConnected()) {
        printf("\nThe graph is connected.\n");
    } else {
        printf("\nThe graph is disconnected.\n");
    }

    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }

    printf("DFS Traversal: ");
    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    printf("\n");
}

void dfs(int v) {
    printf("%d ", v);
    vis[v] = 1;

    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && vis[i] == 0) {
            dfs(i);
        }
    }
}

int isConnected() {
    int i;

    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }

    dfs(0);

    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            return 0;
        }
    }
    return 1;
}
