#include <iostream>

using namespace std;

const int N = 1e5+10;

int st[N], tt=0, n, x;

void insert(int x) {
    st[++tt] = x;
}
int query() {
    return st[tt];
}
int pop() {
    tt--;
}
string isEmpty() {
    if(tt >0) return "NO";
    else return "YES";
}
int main() {
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push") {
            cin >> x;
            insert(x);
        } else if(op == "query") {
            cout << query() << endl;
        } else if(op == "pop") {
            pop();
        } else {
            cout << isEmpty() << endl;
        }
    }

}