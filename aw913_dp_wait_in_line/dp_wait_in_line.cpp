#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5+10;
int t[N];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t, t+n+1);
    LL res = 0;
    for(int i=1; i<n; i++) {
        res += t[i] * (n-i);
    }
    cout << res << endl;
    return 0;
}