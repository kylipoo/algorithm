#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int get(int x) {
    if (x <= 9) {
        return x + '0';
    } else {
        return x - 10 + 'A';
    }
}

string base(int n, int b) {
    string s;
    while (n) {
        s += get(n % b);
        n /= b;
    }
    return s;
}

bool check(string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=m+1, j=0; j<n; i++) {
        int count = 0;
        for (int k = 2; k <= 10 & count < 2; k++) {
            string num1 = base(i, k);
            if (check(num1)) {
                count++;
            }
        }
        if(count >=2) {
            cout << i << endl;
            j++;
        }
    }

    return 0;
}