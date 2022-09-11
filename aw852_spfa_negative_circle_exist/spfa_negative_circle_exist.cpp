#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5+10;
int dist[N];
int h[N], e[N], ne[N], idx, w[N];
int cnt[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <=n; ++i) {
        q.push(i);
        st[i] = true;
    }
    while(q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i=h[t]; i!=-1; i=ne[i]) {
            int x = e[i];
            if(dist[x] > dist[t] + w[i]) {
                dist[x] = dist[t] + w[i];
                cnt[x] = cnt[t] + 1;
                if(cnt[x] >= n) {return true;}
                if(!st[x]) {
                    q.push(x);
                    st[x] = true;
                }
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if(spfa()) puts("Yes");
    else puts("No");
    return 0;
}