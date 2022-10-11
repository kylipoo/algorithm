#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N =15, M=25;
int needs[M], s[N][M], sum[M];
int n, m;

int main() {
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> needs[i];
    }
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> res;
    for(int i=0; i<1<<n; i++) {
        memset(sum, 0, sizeof sum);
        vector<int> t;
        for(int j=0; j<n; j++) {
            if(i >> j & 1) {
                t.push_back(j);
                for(int k=0; k<m; k++) {
                    sum[k] +=s[j][k];
                }
            }
        }
        bool flag = true;
        for(int i=0; i<m; i++) {
            if(sum[i] < needs[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(res.empty() || res.size() > t.size() || res.size() == t.size() && res > t) {
                res = t;
            }
        }
    }
    cout << res.size() <<" ";
    for(auto e: res) {
        cout << e + 1 << " ";
    }
    cout << endl;
    return 0;
}