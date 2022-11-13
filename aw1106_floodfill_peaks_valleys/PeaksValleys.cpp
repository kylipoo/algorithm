#include <iostream>
#include <cstring>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 1010, M=N*N;
int h[N][N];
bool st[N][N];
PII q[M];
int n;

void bfs(int x, int y, bool &has_lower, bool &has_higher) {
    q[0]= {x, y};
    st[x][y] = true;
    int hh=0, tt=0;
    while(hh<=tt) {
        auto t = q[hh++];
        for(int i=t.x-1; i<=t.x+1; i++) {
            for(int j=t.y-1; j<=t.y+1; j++) {
                if(i<0 || i>=n || j<0 || j>=n) continue;
                if(t.x == i && t.y == j) continue;
                if(h[i][j] != h[t.x][t.y]) {
                    if(h[t.x][t.y] > h[i][j]) has_lower = true;
                    else has_higher = true;
                } else {
                    if(st[i][j]) continue;
                    q[++tt] = {i, j};
                    st[i][j] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> h[i][j];
        }
    }
    int peak = 0, valley = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!st[i][j]) {
                bool has_lower=false, has_higher=false;
                bfs(i, j, has_lower, has_higher);
                if(!has_lower) valley++;
                if(!has_higher) peak++;
            }
        }
    }
    cout << peak << " " << valley << endl;
}

