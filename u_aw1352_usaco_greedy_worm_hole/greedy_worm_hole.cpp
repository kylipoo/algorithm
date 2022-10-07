#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 12;
bool used[N][2], cur[N][2];
bool st[N];
int to1[N], to2[N];
int n, ans;

struct Point{
    int x, y;
    bool operator< (const Point &w) const {
        if(y!=w.y) return y<w.y;
        return x<w.x;
    }
}p[N];

bool dfs_c(int a, int b) {
    if(cur[a][b]) return true;
    if(used[a][b]) return false;
    cur[a][b] = used[a][b] = true;
    bool res = false;
    if(!b) {
        if(dfs_c(to2[a], 1)) return true;
    } else {
        if(to1[a]!=-1 && dfs_c(to1[a], 0)) return true;
    }
    cur[a][b] = false;
    return res;
}

bool check() {
    memset(used, false, sizeof used);
    memset(cur, false, sizeof cur);
    for(int i=0; i<n; i++) {
        for(int j=0; j<2; j++) {
            if(!used[i][j]) {
                if (dfs_c(i, j)) return true;
            }
        }
    }
    return false;
}

void dfs(int u) {
    if(u == n/2) {
        if(check()) {
            ans++;
        }
        return;
    }
    for(int i=0; i<n; i++) {
        if(!st[i]) {
            for(int j=i+1; j<n; j++) {
                if(!st[j]) {
                    st[i] = st[j] = true;
                    to2[i]=j, to2[j]=i;
                    dfs(u+1);
                    st[i] = st[j] = false;
                    to2[i]=j, to2[j] = -1;
                }
                break;
            }
        }
    }
}

int main() {
    cin >> n;
    memset(to1, -1, sizeof to1);
    memset(to1, -1, sizeof to2);
    for(int i=0; i<n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p+n);
    for(int i=1; i<n; i++) {
        if(p[i].y == p[i-1].y) {
            to1[i-1] = i;
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}