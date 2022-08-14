#include <iostream>
#include <cstring>

const int N = 2*1e5+3, null = 0x3f3f3f3f;
int h[N];

using namespace std;
int find(int x) {
   int k = (x % N + N) % N;
   while(h[k]!=null && h[k]!=x) {
       k++;
       if(k == N) k=0;
   }
   return k;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);
    while(n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if(*op == 'I') {
            h[k] = x;
        } else {
            if(h[k] != null) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }

    return 0;
}
