#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 1e5+10;
int h[N], e[M], ne[M], idx;
bool st[N];
bool match[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool find(int u) {
    for(int i=h[u]; i!=-1; i=ne[i]) {
        int x = e[i];
        if(!st[x]) {
            st[x] = true;
            if(match[x] == 0 || find(match[x])) {
                match[x] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    int n1, n2, m;
    scanf("%d%d%d", &n1, &n2, &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int res = 0;
    for(int i=1; i<=n1; i++) {
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    printf("%d\n", res);
    return 0;
}