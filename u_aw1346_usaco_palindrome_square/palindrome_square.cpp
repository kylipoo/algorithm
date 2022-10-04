#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int get(int x) {
    if(x <=9) {
        return x + '0';
    } else{
        return x- 10 + 'A';
    }
}

string base(int num, int b) {
    string str;
    while(num) {
        str += get(num%b);
        num/=b;
    }
    reverse(str.begin(), str.end());
    return str;
}

bool check(string s) {
    int n = s.size();
    for(int i=0, j=n-1; i<j; i++, j--) {
        if(s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=300; i++) {
        string str = base(i*i, n);
        if(check(str)) {
            cout << base(i, n) << " " << str << endl;
        }
    }
    return 0;
}
