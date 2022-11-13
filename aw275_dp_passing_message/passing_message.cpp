#include <iostream>
#include <algorithm>

using namespace std;
const int N = 55;
int f[N*2][N][N], w[N][N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=n ; ++j) {
            cin >> w[i][j];
        }
    }
    for(int k=2; k<=n+m; k++) {
        for (int i1 = 1; i1 <= n; ++i1) {
            for (int i2 = 1; i2 <= m; ++i2) {
                int j1 = k-i1, j2=k-i2;
                if(j1>=1 && j1<=n && j2>=1 && j2<=n) {
                    int t = w[i1][j1];
                    if(i1!=i2) {
                        t+=w[i2][j2];
                    }
                    int &x = f[k][i1][j1];
                    x = max(x, f[k-1][i1-1][i2-1] + t);
                    x = max(x, f[k-1][i1][i2-1] + t);
                    x = max(x, f[k-1][i1-1][i2] + t);
                    x = max(x, f[k-1][i1][i2] + t);
                }
            }
        }
    }
    printf("%d", f[n+m][n][m]);
    return 0;
}