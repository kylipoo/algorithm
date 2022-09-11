#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5+10;
int dist[N];
int h[N], e[N], ne[N], idx, w[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i=h[t]; i!=-1; i=ne[i]) {
            int x = e[i];
            if(dist[x] > dist[t] + w[i]) {
                dist[x] = dist[t] + w[i];
                if(!st[x]) {
                    q.push(x);
                    st[x] = true;
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    if(dist[n] == 0x3f3f3f3f) puts("impossible");
    else cout << dist[n];
    return 0;
}