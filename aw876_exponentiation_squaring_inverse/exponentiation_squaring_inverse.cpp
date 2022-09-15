#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1 % p;
    while (b) {
        if(b & 1) res = res * a % p;
        a = a * (LL)a %p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int a, p;
        scanf("%d%d", &a, &p);
        //note when a can mod p, that means a doesn't have invervse
        if (a % p == 0) puts("impossible");
        else printf("%lld\n", qmi(a, p - 2, p));
    }
    return 0;
}