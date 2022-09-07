#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int p[N][N], d[N][N];
PII q[N*N];
int n, m;

int bfs() {
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    int hh = 0, tt = 0;
    q[0] = {0,0};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    while(hh<=tt) {
        auto pr = q[hh++];
        for (int i = 0; i < 4; ++i) {
            int nx = pr.first + dx[i];
            int ny = pr.second + dy[i];
            if(nx >=0 && nx < n && ny >=0 && ny<m && p[nx][ny] == 0 && d[nx][ny] == -1) {
                d[nx][ny] = d[pr.first][pr.second] + 1;
                q[++tt] = {nx, ny};
            }
        }
    }
    return d[n-1][m-1];
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <m ; ++j) {
            scanf("%d", &p[i][j]);
        }
    }
    cout << bfs() << endl;
    return 0;
}