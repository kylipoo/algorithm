#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int a[N], f[N];

int main() {
    int m;
    cin >> m;
    while(m--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            f[i] = 1;
            for(int j=0; j<i; j++) {
                if(a[j] < a[i]) {
                    f[i] = max(f[j]+1, f[i]);
                }
            }
            res = max(res, f[i]);
        }
        memset(f, 0, sizeof f);
        for(int i=n-1; i>=0; i--) {
            f[i] = 1;
            for(int j=n-1; j>i; j--) {
                if(a[j]<a[i]) {
                    f[i] = max(f[j]+1, f[i]);
                }
            }
            res = max(res, f[i]);
        }
        cout << res << endl;
    }
    return 0;
}