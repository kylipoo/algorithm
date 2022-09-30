#include <iostream>
#include <queue>

using namespace std;
const int N = 10010;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    while(n--) {
        int a;
        cin >> a;
        heap.push(a);
    }
    int res = 0;
    while(heap.size()>1) {
        int x = heap.top();
        heap.pop();
        int y = heap.top();
        heap.pop();
        res += x+y;
        heap.push(res);
    }
    cout << heap.top() << endl;
    return 0;
}