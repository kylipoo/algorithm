#include <iostream>
#include <cstring>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N*N;
PII q[M];
char g[N][N];
int dist[N][N];
int n, m;

void bfs() {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    memset(dist, -1, sizeof dist);
    int hh=0, tt = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j] == '1') {
                q[++tt] = {i, j};
                dist[i][j] = 0;
            }
        }
    }
    while(hh<=tt) {
        auto t = q[hh++];
        for(int i=0; i<4; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny] !=-1) continue;
            q[++tt] = {nx, ny};
            dist[nx][ny] = dist[t.x][t.y] + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> g[i];
    }
    bfs();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }


}