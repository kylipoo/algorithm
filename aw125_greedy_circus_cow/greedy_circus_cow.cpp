#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

const int N = 50000;
PII t[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        t[i] = {x+y, y};
    }
    sort(t, t+n);
    int risk = -2e9, sum = 0;
    for(int i=0; i<n; i++) {
        int w = t[i].first - t[i].second;
        int s = t[i].second;
        risk = max(risk, sum-s);
        sum +=w;
    }
    cout << risk << endl;
    return 0;

}