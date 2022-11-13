#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;
int f[N], a[N];

int main() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) {
       cin >> a[i];
   }
   vector<int> stk;
   stk.push_back(a[0]);
   for(int i=1; i<n; i++) {
       if(a[i] > stk.back()) {
           stk.push_back(a[i]);
       } else {
           *lower_bound(stk.begin(), stk.end(), a[i]) = a[i];
       }
   }
   cout << stk.size() << endl;
   return 0;
}