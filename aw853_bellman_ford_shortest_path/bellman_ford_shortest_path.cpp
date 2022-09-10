#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;
int dist[N], last[N];
int n, m, k;

struct Edge {
    int a, b, w;
}edges[M];

void belllman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; ++i) {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; ++j) {
           auto x = edges[j];
           dist[x.b] = min(dist[x.b], last[x.a]+x.w);
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    belllman_ford();
    if(dist[n] > 0x3f3f3f3f/2) puts("impossible");
    else cout<<dist[n];
}