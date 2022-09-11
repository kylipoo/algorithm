#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9;
int d[N][N];
int m, n, Q;

void floyd() {
    for (int k = 1; k <=n; ++k) {
        for (int i = 1; i <=n ; ++i) {
            for (int j = 1; j <=n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &Q);
    //initialization
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m ; ++j) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    // add nodes and edges
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //remove duplicates edges and self loop
        d[a][b] = min(d[a][b], c);
    }
    floyd();
    while(Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int t = d[a][b];
        if(t > INF/2) puts("impossible");
        else printf("%d\n", t);
    }

}
