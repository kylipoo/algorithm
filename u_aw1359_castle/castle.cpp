#include <iostream>

using namespace std;

const int N = 50;
int g[N][N];
int p[N * N], sz[N * N];
int m, n;

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    //init sets and area
    for (int i = 0; i < n * m; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    int cnt = n * m, max_area = 1;
    int dx[2] = {-1, 0}, dy[2] = {0, 1}, dw[2] = {2, 4};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int u = 0; u < 2; u++) {
                if (!(g[i][j] & dw[u])) {
                    int nx = i + dx[u];
                    int ny = j + dy[u];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    int a = i * m + j, b = nx * m + ny;
                    a = find(a), b = find(b);
                    if (a != b) {
                        cnt--;
                        sz[b] += sz[a];
                        p[a] = b;
                        max_area = max(max_area, sz[b]);
                    }
                }
            }
        }
    }
    cout << cnt << endl << max_area << endl;
    max_area = 0;
    int rx, ry, rw;
    for(int j=0; j<m; j++) {
        for(int i=n-1; i>=0; i--) {
            for(int u=0; u<2; u++) {
                if ((g[i][j] & dw[u])) {
                    int nx = i + dx[u];
                    int ny = j + dy[u];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    int a = i * m + j, b = nx * m + ny;
                    a = find(a), b = find(b);
                    if (a != b) {
                        int area = sz[a] + sz[b];
                        if(area > max_area) {
                            max_area = area;
                            rx = i, ry = j, rw = u;
                        }
                    }
                }
            }
        }
    }
    cout << max_area << endl;
    cout << rx + 1 << " " << ry + 1<< " " << (rw ? "E" : "N");
    return 0;
}