#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;
const int N = 110, mod = 1e9+7;
typedef long long LL;
unordered_map<int, int> primes;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        for(int i=2; i<=x/i; i++) {
            while(x%i == 0) {
                    x /=i;
                    primes[i]++;
            }
        }
        if(x>1) primes[x]++;
    }
    LL res = 1;
    for(auto e : primes) {
        LL t = 1;
        int a = e.first, b=e.second;
        while(b--) {
            t = (t * a + 1) % mod;
        }
        res = res *  t % mod;
    }
    cout << res << endl;
    return 0;
}


