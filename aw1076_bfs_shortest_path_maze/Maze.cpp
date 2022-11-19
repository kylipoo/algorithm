#include <iostream>
#include <cstring>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N*N;
int g[N][N];
PII q[M];
PII pre[N][N];
int n;

void bfs(int sx, int sy) {
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    q[0] = {sx, sy};
    int hh=0, tt=0;
    memset(pre, -1, sizeof pre);
    pre[sx][sy] = {0,0};
    while(hh<=tt) {
        PII t = q[hh++];
        for(int i=0; i<4; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(pre[nx][ny].x != -1) continue;
            if(g[nx][ny] == 1) continue;
            q[++tt] = {nx, ny};
            pre[nx][ny] = t;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    bfs(n-1, n-1);
    PII end = {0, 0};
    while(true) {
        printf("%d %d\n", end.x, end.y);
        if(end.x == n-1 && end.y == n-1) break;
        end = pre[end.x][end.y];
    }

}