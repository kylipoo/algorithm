#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;
int q[N];
int n, k;

int quickSelect(int q[], int l, int r, int k) {
    if(l == r) {
        return q[l];
    }
    int x = q[l], i = l-1, j=r+1;
    while(i < j) {
        do i++; while (q[i] < x);
        do j--; while(q[j] > x);
        if(i<j) {
            swap(q[i],q[j]);
        }
    }
    int s1 = j-l+1;
    if(k<=s1) {
        return quickSelect(q, l, j, k);
    } else {
        return quickSelect(q, j+1, r, k-s1);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &q[i]);
    }
    cout << quickSelect(q, 0, n-1, k);
    return 0;
}