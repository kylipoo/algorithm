#include <iostream>
#include <vector>

using namespace std;
typedef vector<string> VS;
int n;

void mirror(VS& s) {
    for(int i=0; i<n; i++) {
        for(int j=0, k=n-1; j<k; j++, k--) {
            swap(s[i][j], s[i][k]);
        }
    }
}

void rotate(VS& s) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            swap(s[i][j], s[j][i]);
        }
    }
    mirror(s);
}

int check(VS& a, VS& b) {
    auto c = a;
    for(int i=1; i<=3; i++) {
        rotate(c);
        if(c == b) {
            return i;
        }
    }
    c = a;
    mirror(c);
    if(c == b) return 4;
    for(int i=1; i<=3; i++) {
        rotate(c);
        if(c == b) {
            return 5;
        }
    }
    if(a == b) return 6;
    return 7;
}

int main() {
    cin >> n;
    VS a, b;
    string line;
    for(int i=0; i<n; i++) cin >> line, a.push_back(line);
    for(int i=0; i<n; i++) cin >> line, b.push_back(line);
    cout << check(a, b) << endl;
    return 0;
}
