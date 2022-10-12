#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int m, ans = 1e9;
bool st[N], used[N];
string path;

bool check() {
    memset(used, 0, sizeof used);
    for(int i=0, j=0; i<path.size(); i++) {
        j+=path[j] -'0';
        j %=path.size();
        if(used[j]) return false;
        used[j] = true;
    }
    return true;
}
void dfs() {
    if(path.size()) {
        int n = stoi(path);
        if(n>m && check()) {
            ans = min(n, ans);
        }
    }
    for(int i=1; i<=9; i++) {
        if(!st[i]) {
            st[i] = true;
            path += i + '0';
            dfs();
            path.pop_back();
            st[i] = false;
        }
    }
}
int main() {
    cin >> m;
    dfs();
    cout << ans << endl;
    return 0;
}
