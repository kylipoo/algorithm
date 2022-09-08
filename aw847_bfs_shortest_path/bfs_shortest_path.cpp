#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;
int e[N], ne[N], h[N], d[N], idx, q[N];
int n, m;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int bfs() {
    int hh=0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = 1;
    d[1] = 0;
    while(hh<=tt) {
        int t = q[hh++];
        for(int i=h[t]; i!=-1; i=ne[i]) {
            int x = e[i];
            if(d[x] == -1) {
                d[x] = d[t] + 1;
                q[++tt] = x;
            }
        }
    }
    return d[n];
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}