#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e6+10;
int primes[N], eulers[N], cnt;
bool st[N];


void getEuler(int x) {
    eulers[1] = 1;
    for (int i = 2; i <=x; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
            eulers[i] = i-1;
        }
        for (int j = 0; primes[j] <= x/i; ++j) {
            int t = primes[j] * i;
            st[t] = true;
            if(i % primes[j] == 0) {
                eulers[t] = eulers[i] * primes[j];
                break;
            }
            eulers[t] = eulers[i] * (primes[j]-1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getEuler(n);
    LL res = 0;
    for(int i=1; i<=n; i++) {
        res +=eulers[i];
    }
    cout << res << endl;
    return 0;
}