#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5+10;
int e[N], ne[N], idx, h[N];
int q[N], d[N];
int n, m;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool toposort() {
    int hh=0, tt=-1;
    for (int i = 1; i <= n; ++i) {
        if(!d[i]) {
            q[++tt] = i;
        }
    }
    while(hh<=tt) {
        int t = q[hh++];
        for(int i = h[t]; i!=-1; i=ne[i]) {
            int x = e[i];
            if(--d[x] == 0) {
                q[++tt] = x;
            }
        }
    }
    return tt == n-1;
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }
    if(toposort()) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", q[i]);
        }
        puts("");
    } else {
        cout << -1 << endl;
    }
    return 0;
}
