#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 510, M = N*N, Null = 0x3f3f3f3f;
int dist[N][N];
char g[N][N];
int n, m;
bool st[N][N];

int bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
    char cs[] = "\\/\\/";
    deque<PII> q;
    q.push_back({0,0});

    dist[0][0] = 0;
    while(!q.empty()) {
        auto t = q.front();
        q.pop_front();
        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        for(int i=0; i<4; i++) {
            int nx = dx[i] + t.x, ny = dy[i] + t.y;
            if(nx<0 || nx > n || ny<0 || ny>m) continue;
            int cx = ix[i] + t.x, cy = iy[i] + t.y;
            int d = dist[t.x][t.y] + (g[cx][cy] !=cs[i]);
            if(d<dist[nx][ny]) {
                dist[nx][ny] = d;
                if(g[cx][cy]!=cs[i]) q.push_back({nx, ny});
                else q.push_front({nx, ny});
            }
        }
    }
    return dist[n][m];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> g[i];
        }
        int step = bfs();
        if(step == Null) cout << "NO SOLUTION" << endl;
        else cout << step << endl;
    }
    return 0;
}