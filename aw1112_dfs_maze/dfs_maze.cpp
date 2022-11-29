#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 110;
bool st[N][N];
char g[N][N];
int xa, ya, xb, yb;
int n;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

bool dfs(int x, int y) {
    if (g[x][y] == '#') return false;
    if (x == xb && y == yb) return true;
    st[x][y] = true;

    for(int i=0; i<4; i++) {
        int nx = dx[i] + x, ny = dy[i]+y;
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(st[nx][ny]) continue;
        if(dfs(nx, ny)) return true;
    }
    return false;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin >> n;
        memset(st, 0, sizeof st);
        for(int i=0; i<n; i++) {
            cin >> g[i];
        }
        cin >> xa >> ya >> xb >> yb;
        if(dfs(xa, ya)) puts("YES");
        else puts("NO");
    }
}