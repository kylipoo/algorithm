#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;
int q[N], temp[N];
int n;

void mergeSort(int q[], int l, int r) {
    if(l >= r) {
        return;
    }
    int mid = l + r >> 1;
    mergeSort(q, l, mid), mergeSort(q, mid+1, r);
    int k=0, i=l, j = mid+1;
    while(i<=mid && j<=r) {
        if(q[i] <= q[j]) {
            temp[k++] = q[i++];
        } else {
            temp[k++] = q[j++];
        }
    }
    while(i<=mid) {
        temp[k++] = q[i++];
    }
    while(j<=r) {
        temp[k++] = q[j++];
    }
    for(i=l, j=0; i<=r; i++, j++) {
        q[i] = temp[j];
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &q[i]);
    }
    mergeSort(q, 0, n-1);
    for(int i=0; i<n; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}