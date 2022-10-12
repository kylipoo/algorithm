#include <iostream>

using namespace std;

typedef long long LL;
const int N = 410;
LL dp[N];
int n;

int main() {
    cin >> n;
    int m = n*(n+1)/2;
    if(m%2) puts("0");
    else {
        m/=2;
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= i; j--) {
                dp[j] += dp[j-i];
            }
        }
        cout << dp[m]/2 << endl;
    }

    return 0;

}