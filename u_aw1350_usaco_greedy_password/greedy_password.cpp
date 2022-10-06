#include <iostream>

using namespace std;

const int N = 10;
bool st[N];
int checkLen(int x) {
    return to_string(x).size();
}
bool checkin(int x) {
    while(x) {
        int d = x%10;
        if(!st[d]) return false;
        x /=10;
    }
    return true;
}
bool check(int a, int b) {
    int c = a * (b%10);
    int d = a * (b/10);
    int e = a * b;
    if(!checkin(a) || !checkin(b) || !checkin(c) || !checkin(d) || !checkin(e)) {
        return false;
    }
    if(checkLen(c)!=3 || checkLen(d)!=3 || checkLen(e)!=4) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }
    int res = 0;
    for(int a=100; a<=999; a++) {
        for(int b=10; b<=99; b++) {
            if(check(a, b)) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
