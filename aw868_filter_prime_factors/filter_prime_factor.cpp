#include <iostream>

const int N = 1e6+10;
int primes[N], cnt;
bool st[N];

void filter(int x) {
    for (int i = 2; i <= x ; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
        }
        for(int j=i+i; j<=x; j+=i) {
            st[j] = true;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    filter(n);
    printf("%d", cnt);
    return 0;
}