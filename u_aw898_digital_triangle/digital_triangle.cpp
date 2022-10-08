#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
const int N = 510;
int dp[N][N], t[N][N];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> t[i][j];
        }
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=i; j++) {
            dp[i][j] = t[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}