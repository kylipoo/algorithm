#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 55, M=N*N;
int g[N][N];
bool st[N][N];
PII q[M];
int n, m;

int bfs(int x, int y) {
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    q[0] = {x, y};
    int hh = 0, tt = 0;
    st[x][y] = true;
    int area = 0;
    while(hh<=tt) {
        auto t = q[hh++];
        area++;
        for(int i=0; i<4; i++) {
            int nx = t.x + dx[i], ny = t.y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(st[nx][ny]) continue;
            if(g[t.x][t.y] >> i & 1) continue;
            q[++tt] = {nx, ny};
            st[nx][ny] = true;
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> g[i][j];
        }
    }
    int area = 0, cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!st[i][j]) {
                area =max(area, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    cout << area << endl;
}