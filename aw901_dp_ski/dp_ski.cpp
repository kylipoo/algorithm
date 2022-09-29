#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;
int fd[N][N], dp[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool st[N];
int n, m;

int ski(int x, int y) {
    int &v = dp[x][y];
    if(v != -1) {
        return v;
    }
    v = 1;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx < n && ny>=0 && ny<m && fd[x][y] > fd[nx][ny]) {
            v = max(v, ski(nx, ny)+1);
        }
    }
    return v;
}


int main() {
    scanf("%d%d", &n, &m);
    memset(dp, -1, sizeof dp);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &fd[i][j]);
        }
    }
    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            res = max(res, ski(i, j));
        }
    }
    printf("%d", res);
    return 0;
}