#include <iostream>

const int N = 1e5+10;
int q[N];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &q[i]);
    }
    while(k--) {
        int x;
        scanf("%d", &x);
        int l = 0, r = n-1;
        while(l<r) {
            int mid = l+r >> 1;
            if(q[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(q[l]!=x) {
            printf("%d %d\n", -1, -1);
        } else {
            printf("%d ", l);
            l = 0, r = n-1;
            while(l < r) {
                int mid = l+r+1 >> 1;
                if(q[mid] <=x) {
                    l = mid;
                } else {
                    r = mid-1;
                }
            }
            printf("%d\n", l);
        }
    }
    return 0;
}


