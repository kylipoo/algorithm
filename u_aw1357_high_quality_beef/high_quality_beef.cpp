#include <iostream>

using namespace std;

int digits;
bool is_prime(int n) {
    for(int i=2; i<=n/i; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int n, int k) {
    if(!is_prime(n)) return;
    if(k == digits) cout<<n<<endl;
    else{
        int d[4] = {1, 3, 7, 9};
        for(int i=0; i<4; i++) {
            dfs(n * 10 + d[i], k+1);
        }
    }
}

int main() {
    cin >> digits;
    dfs(2, 1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
    return 0;
}