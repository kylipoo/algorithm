#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;
char p[N], s[N];
int ne[N];
int n, m;

int main() {
   cin >> n >> p+1 >> m >> s+1;
   for(int i=2, j=0; i<=n; i++) {
       while(j && p[i]!=p[j+1]) j = ne[j];
       if(p[i] == p[j+1]) j++;
       ne[i] = j;
   }
   for(int i=1, j=0; i<=m; i++) {
       while(j && s[i]!=p[j+1]) j=ne[j];
       if(s[i] == p[j+1]) j++;
       if(n == j) {
           printf("%d ", i-n);
           j = ne[j];
       }
   }
   return 0;
}