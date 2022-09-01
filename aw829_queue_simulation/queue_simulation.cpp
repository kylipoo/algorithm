#include <iostream>

using namespace std;

const int N = 1e5+10;

int q[N], hh, tt=-1, n, x;

void push(int x) {
    q[++tt] = x;
}
int query() {
    return q[hh];
}
int pop() {
    hh++;
}
string isEmpty() {
    if(hh<=tt) return "NO";
    else return "YES";
}
int main() {
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push") {
            cin >> x;
            push(x);
        } else if(op == "query") {
            cout << query() << endl;
        } else if(op == "pop") {
            pop();
        } else {
            cout << isEmpty() << endl;
        }
    }

}