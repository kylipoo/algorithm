#include <iostream>

using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;


void dfs(int u) {
    if(u == n) {
        for (int i = 0; i < n; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i <n; ++i) {
        if(!st[i]) {
            st[i] = true;
            path[u] = i+1;
            dfs(u+1);
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;

}