
bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize) {
    int graph[2001][2001] = {0};
    int color[2001] = {0};
    int queue[2001];

    for (int i = 0; i < dislikesSize; i++) {
        int a = dislikes[i][0];
        int b = dislikes[i][1];
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] != 0)
            continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 1;

        while (front < rear) {
            int u = queue[front++];

            for (int v = 1; v <= n; v++) {
                if (graph[u][v]) {
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        queue[rear++] = v;
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}