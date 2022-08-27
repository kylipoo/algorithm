#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 3e5+10;
int a[N], s[N];
vector<int> alli;
vector<PII> addV, queryV;

int find(int x) {
    int l = 0;
    int r = alli.size()-1;
    while(l<r) {
        int mid = l + r >> 1;
        if(x <= alli[mid]) r = mid;
        else l = mid + 1;
    }
    return l+1;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x, c;
        cin >> x >> c;
        alli.push_back(x);
        addV.push_back({x, c});
    }
    for(int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        alli.push_back(l);
        alli.push_back(r);
        queryV.push_back({l, r});
    }
    sort(alli.begin(), alli.end());
    alli.erase(unique(alli.begin(), alli.end()), alli.end());
    // insert the x and c into a array, note this a array idx has already mapped through find function.
    for(auto p : addV) {
        int x = find(p.first);
        a[x] += p.second;
    }
    for(int i=1; i<=alli.size(); i++) {
        s[i] = s[i-1] + a[i];
    }
    for(auto p : queryV) {
        int l = find(p.first);
        int r = find(p.second);
        printf("%d\n", s[r] - s[l-1]);
    }
    return 0;
}
