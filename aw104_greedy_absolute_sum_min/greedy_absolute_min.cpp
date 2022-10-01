#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000 ;
int t[N];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t[i];
    }
    sort(t, t+n);
    int res = 0;
    for(int i=0; i<n; i++) {
        res +=abs(t[i] - t[n/2]);
    }
    cout<< res << endl;
    return 0;
}