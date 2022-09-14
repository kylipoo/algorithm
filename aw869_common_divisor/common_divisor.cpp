#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getDivisors(int x) {
    vector<int> res;
    for (int i = 1; i <= x/i ; ++i) {
        if( x%i == 0) {
            res.push_back(i);
            if(x/i != i) {
                res.push_back(x/i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        vector<int> v = getDivisors(x);
        for(auto e : v) {
            printf("%d ", e);
        }
        puts("");
    }
    return 0;
}