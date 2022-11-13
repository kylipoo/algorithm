#include <iostream>
#include <cstring>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010, M = N*N;
PII q[M];
char g[N][N];
bool st[N][N];
int n, m;

void bfs(int x, int y) {
    int hh=0, tt=0;
    q[0] = {x, y};
    st[x][y] = true;
    while(hh<=tt) {
        auto t = q[hh++];
        if(hh == M) hh = 0;
        for(int i=t.x-1; i<=t.x+1; i++) {
            for(int j=t.y-1; j<=t.y+1; j++) {
                if(t.x ==i && t.y ==j) continue;
                if(st[i][j] || g[i][j] == '.') continue;
                if(i<0 || i>=n || j<0 || j>=m) continue;
                q[++tt] = {i, j};
                st[i][j] = true;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
