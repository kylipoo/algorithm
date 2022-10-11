#include <iostream>

using namespace std;

const int N = 256;
bool g[N][N];
int path[N];
int n, b, d;

int get_one(int x) {
    int res = 0;
    while(x) {
        res += x&1;
        x>>=1;
    }
    return res;
}
bool dfs(int u, int start) {
    if(u == n) {
        for(int i=0; i<n; i++) {
            cout << path[i];
            if((i+1)%10) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        return true;
    }
    for(int i=start; i<1<<b; i++) {
        bool flag = true;
        for(int j=0; j<u; j++) {
            if(!g[i][path[j]]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            path[u] = i;
            if(dfs(u+1, i+1)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> b >> d;
    for(int i=0; i<1<<b; i++) {
        for(int j=0; j<1<<b; j++) {
            if(get_one(i^j)>=d) {
                g[i][j] = true;
            }
        }
    }
    dfs(1, 1);
    return 0;
}