#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
int son[N][2], idx, n, a[N];

void insert(int x) {
    int p = 0;
    for(int i=30; i>=0; i--) {
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0;
    int res = 0;
    for(int i=30; i>=0; i--) {
        int u = x >> i & 1;
        if(son[p][!u]) {
            res += 1 << i;
            p = son[p][!u];
        } else {
            p = son[p][u];
        }
    }
    return res;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    int maxNum = 0;
    for(int i=0; i<n; i++) {
        maxNum = max(maxNum, query(a[i]));
    }
    cout << maxNum << endl;
}