#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1e5+10;
struct Range{
    int l, r;
    bool operator <(const Range &w) const {
        return l < w.l;
    }
}range[N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &range[i].l, &range[i].r);
    }
    sort(range, range+n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i=0; i<n; i++) {
        if(heap.empty() || heap.top() >= range[i].l) {
            heap.push(range[i].r);
        } else {
            heap.pop();
            heap.push(range[i].r);
        }
    }
    printf("%d", heap.size());
    return 0;

}