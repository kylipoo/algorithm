#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

struct Range {
    int l, r;
    bool operator<(const Range &w) const {
        return r < w.r;
    }
}range[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &range[i].l, &range[i].r);
    }
    sort(range, range+n);
    int res = 0, ed = -2e9;
    for(int i=0; i<n; i++) {
        if(range[i].l > ed) {
            res++;
            ed = range[i].r;
        }
    }
    cout<<res<<endl;
    return 0;
}