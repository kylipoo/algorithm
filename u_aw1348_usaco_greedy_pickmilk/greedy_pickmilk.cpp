#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
struct Milk{
    int p, a;
    bool operator<(const Milk &m) const {
        return p < m.p;
    }
}milk[N];
int main() {
    int total, n;
    cin >> total >> n;
    for(int i=0; i<n; i++) {
        cin >> milk[i].p >> milk[i].a;
    }
    sort(milk, milk+n);
    int res = 0;
    for(int i=0; i<n && total; i++) {
        int cur = min(total, milk[i].a);
        total -= cur;
        res += milk[i].p * cur;
    }
    cout << res << endl;
    return 0;
}