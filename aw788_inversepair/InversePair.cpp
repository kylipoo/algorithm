#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e6+10;
int q[N], tmp[N];

LL mergeSort(int q[], int l, int r) {
    if(l >= r) return 0;
    int mid = l+r>>1;
    LL res = mergeSort(q, l, mid) + mergeSort(q, mid+1, r);
    int i=l, j=mid+1, k=0;
    while(i <= mid && j<=r) {
        if(q[i] <=q[j]) {
            tmp[k++] = q[i++];
        } else{
            tmp[k++] = q[j++];
            res += mid-i+1;
        }
    }
    while(i<=mid) {
        tmp[k++] = q[i++];
    }
    while(j<=r) {
        tmp[k++] = q[j++];
    }
    for(int i=l, j=0; i<=r; i++, j++) {
        q[i] = tmp[j];
    }
    return res;
}


int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &q[i]);
    }
    cout<<mergeSort(q, 0, n-1);
    return 0;
}

