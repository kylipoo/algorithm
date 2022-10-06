#include <iostream>
#include <algorithm>

using namespace std;
const int N = 210;
int code[N], gap[N];

int main() {
    int m, s, c;
    cin >> m >> s >> c;
    for(int i=0; i<c; i++) cin >> code[i];
    sort(code, code+c);
    int res = code[c-1] - code[0] + 1;
    for(int i=1; i<c; i++) {
        gap[i-1] = code[i] - code[i-1]-1;
    }
    sort(gap, gap+c-1, greater<int>());
    for(int i=0; i<m-1 && i<c; i++) {
        res -= gap[i];
    }
    cout << res << endl;
    return 0;
}