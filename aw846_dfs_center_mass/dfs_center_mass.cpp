#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
const int M = 2*N;
//need to times 2 as no direction has two ways
int h[N], e[M], ne[M], idx;
bool st[N];
int n;
int ans = N;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dfs(int u) {
    st[u] = true;
    int sum = 1, res = 0;
    for(int i=h[u]; i!=-1; i=ne[i]) {
        int x = e[i];
        if(!st[x]) {
            int s = dfs(x);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n-sum);
    ans = min(ans, res);
    return sum;
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    int m = n-1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b,a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}