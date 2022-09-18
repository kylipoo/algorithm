#include <iostream>
#include <vector>

using namespace std;

const int N = 5010;
int primes[N], cnt;
bool st[N];
int sum[N];

void getPrimes(int x) {
    for(int i=2; i<=x; i++) {
        if(!st[i]) primes[cnt++] = i;
        for(int j=i+i; j<=x; j+=i) {
            st[j] = true;
        }
    }
}
int get(int x, int p) {
    int res = 0;
    while(x) {
        res += x/p;
        x /=p;
    }
    return res;
}

vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); ++i) {
        t += a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(t) {
        c.push_back(t%10);
        t /=10;
    }
    return c;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    getPrimes(a);
    for (int i = 0; i < cnt; ++i) {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a-b, p);
    }
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < sum[i]; ++j) {
            res = mul(res, primes[i]);
        }
    }
    for (int i = res.size()-1; i >=0 ; i--) {
        printf("%d", res[i]);
    }
    puts("");
    return 0;

}