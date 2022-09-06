#include <iostream>

using namespace std;
const int N = 20;
char p[N][N];
int n;
bool col[N], df[N], udf[N];
void dfs(int u) {
    if(u == n) {
        for(int i=0; i<n; i++) {
            puts(p[i]);
        }
        puts("");
    }
    for(int i=0; i<n; i++) {
        if(!col[i] && !df[u+i] && !udf[n+i-u]) {
            col[i] = df[u+i] = udf[n+i-u] = true;
            p[u][i] = 'Q';
            dfs(u+1);
            col[i] = df[u+i] = udf[n+i-u] = false;
            p[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            p[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}