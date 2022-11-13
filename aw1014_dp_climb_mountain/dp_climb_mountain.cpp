#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int f[N], g[N], a[N];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<n; i++) {
        f[i] = 1;
        for(int j=0; j<i; j++) {
            if(a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        g[i] = 1;
        for(int j=n-1; j>i; j--) {
            if(a[i] > a[j]) {
                g[i] = max(g[i],g[j] + 1);
            }
        }
    }
    int res=0;
    for(int i=0; i<n; i++) {
        res = max(res, f[i]+g[i] -1);
    }
    cout << res << endl;
    return 0;

}