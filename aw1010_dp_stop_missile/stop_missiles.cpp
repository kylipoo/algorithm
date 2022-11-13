#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
const int N = 1010;
int f[N], g[N], a[N];
int n=0;
int main() {
    string line;
    getline(cin, line);
    stringstream ssin(line);
    while(ssin >> a[n]) n++;
    int res1 = 0;
    int res2 = 0;
    for(int i=0; i<n; i++) {
        f[i] = 1;
        g[i] = 1;
        for(int j=0; j<i; j++) {
            if(a[j]>=a[i]) {
                f[i] = max(f[i], f[j] + 1);
            } else {
                g[i] = max(g[i], g[j] + 1);
            }
        }
        res1 = max(res1, f[i]);
        res2 = max(res2, g[i]);
    }
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}