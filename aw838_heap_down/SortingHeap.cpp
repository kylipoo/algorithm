#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int h[N], size;
int n, m;

void down(int u) {
    int t = u;
    if(2*u < size && h[2*u] < h[u]) {
        t = 2*u;
    }
    if(2*u+1 < size && h[2*u+1] < h[u]) {
        t = 2*u+1;
    }
    if(t != u) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    size = n;
    for(int i=1; i<=n; i++) {
        cin >> h[i];
    }
    for(int i=n/2; i; i--) {
        down(i);
    }
    while(m--) {
        printf("%d ", h[1]);
        h[1] = h[size];
        size--;
        down(1);
    }
}