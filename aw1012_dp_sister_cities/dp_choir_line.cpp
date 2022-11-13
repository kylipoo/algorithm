#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;
int f[N];
struct Cities {
    int x, y;
    bool operator<(const Cities &w) const {
        return x < w.x;
    }
}cities[N];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> cities[i].x >> cities[i].y;
    }
    sort(cities, cities+n);
    int res = 0;
    for(int i=0; i<n; i++) {
        f[i] = 1;
        for(int j=0; j<i; j++) {
            if(cities[i].y > cities[j].y) {
                f[i] = max(f[i], f[j]+1);
            }
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}