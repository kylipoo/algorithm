#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10, base = 131;
int p[N], hl[N], hr[N];

int get(int h[], int l, int r) {
    return h[r] - h[l-1]*p[r-l+1];
}

int main() {
    string str;
    cin >> str;
    int n = str.size();
    p[0] = 1;
    //make sure map to start 1 index
    for(int i = 1, j = n-1; i <= n; i ++, j --) {
        p[i] = p[i - 1] * base;
        hl[i] = hl[i - 1] * base + str[i-1];
        hr[i] = hr[i - 1] * base + str[j];
    }
    for(int i=n; i; i--) {
        if(get(hl, 1, i) == get(hr,n-i+1, n) ){
            auto pre = str.substr(i);
            reverse(pre.begin(), pre.end());
            cout <<  pre+str << endl;
            break;
        }
    }
    return 0;

}