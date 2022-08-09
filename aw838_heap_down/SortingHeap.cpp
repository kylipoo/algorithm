#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
int h[N];
int n, m, arrSize;

void down(int u) {
    int t = u;
    if(2*u <= arrSize && h[2*u] < h[t]) {
        t = 2*u;
    }
    if(2*u+1 <= arrSize && h[2*u+1] < h[t]) {
        t = 2*u+1;
    }
    if(t!=u) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) cin >> h[i];
    arrSize = n;
    for(int i=n/2; i; i--) down(i);
    while(m--) {
        printf("%d ", h[1]);
        h[1] = h[arrSize];
        arrSize--;
        down(1);
    }
    return 0;
}