#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5+10;
struct Range {
    int l, r;
    bool operator<(const Range &w) const {
        return l < w.l;
    }
}range[N];
int main() {
    int start, end;
    cin >> start >> end;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range+n);
    int res = 0;
    bool isSuccess = false;
    for(int i=0; i<n; i++) {
        int j=i, rMax = -2e9;
        while(j<n && range[j].l <=start ){
            rMax = max(rMax, range[j].r);
            j++;
        }
        res++;
        if(rMax < start) {
            res = -1;
            isSuccess = false;
            break;
        }
        if(rMax >=end) {
            isSuccess = true;
            break;
        }
        i = j-1;
        start = rMax;
    }
    if(!isSuccess) res = -1;
    printf("%d", res);
    return 0;
}