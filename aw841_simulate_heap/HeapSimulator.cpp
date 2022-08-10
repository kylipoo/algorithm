#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
const int N = 1e5+10;
int hp[N], ph[N], h[N];
int cnt, m;

void heapSwap(int a, int b) {
    //ph[k] keep the index of the kth inserted number
    //hp[k] keep in the index k of heap, ?th when it is inserted
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if(2*u <= cnt && h[2*u] < h[t]) t = 2*u;
    if(2*u+1 <= cnt && h[2*u+1] < h[t]) t = 2*u+1;
    if(u!=t) {
        heapSwap(t, u);
        down(t);
    }
}

void up(int u) {
    while(u/2 && h[u] < h[u/2]) {
        heapSwap(u, u/2);
        u >>= 1;
    }
}

int main() {
    int n, m=0;
    cin >> n;
    while(n--) {
        char op[5];
        int k, x;
        scanf("%s", op);
        if(!strcmp(op, "I")) {
            scanf("%d", &x);
            cnt++;
            m++;
            ph[m] = cnt;
            hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        } else if(!strcmp(op, "PM")) {
            printf("%d\n", h[1]);
        } else if(!strcmp(op, "DM")) {
            heapSwap(1, cnt);
            cnt--;
            down(1);
        } else if(!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heapSwap(k, cnt);
            cnt--;
            up(k);
            down(k);
        } else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

}