#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int N = 100;
int a[3], b[3];
int n;


int overlap() {
    if(n<5) {
        return n*n*n;
    }
    int res = 1;
    for(int i=0; i<3; i++) {
        int x = a[i], y = b[i];
        int d = abs(x - y);
        res *= max(0, 5-d) + max(0, 5-(n-d));
    }
    return res;
}


int single()
{
    int res = 1;
    for (int i = 0; i < 3; i ++ ) res *= min(n, 5);
    return res;
}

int main() {
    cin >> n;
    for(int i=0; i<3; i++) cin >> a[i];
    for(int i=0; i<3; i++) cin >> b[i];
    int res = single()*2 - overlap();
    cout << res << endl;
    return 0;
}