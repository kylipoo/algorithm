#include <iostream>

using namespace std;

const int N = 1e5+10;

int st[N], tt;

int main() {
    int n;
    cin >> n;
    int x;
    while(n--){
        cin >> x;
        while(tt>0 && x < st[tt]) {
            tt--;
        }
        if(tt==0) {
            cout << "-1 ";
        } else {
            cout << st[tt] << " ";
        }
        st[++tt] = x;
    }
    return 0;
}