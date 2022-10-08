#include <iostream>
#include <algorithm>

using namespace std;
const int N = 250*250*2+10;
bool st[N];
struct Seq{
    int a, d;
    bool operator<(const Seq &t) const {
        if(d!=t.d) return d<t.d;
        return a<t.a;
    }
}seq[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=m; j++) {
            st[i*i+j*j] = true;
        }
    }
    int S = m*m*2, cnt = 0;
    for(int i=0; i<=S; i++) {
        if(st[i]) {
            for (int j = i + 1; j <= S; j++) {
                if(st[j]) {
                    int d = j-i, last = i + (n-1)*d;
                    if(last>S) break;
                    bool flag = true;
                    for(int k=j+d;  k<=last; k+=d) {
                        if(!st[k]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        seq[cnt++] = {i, d};
                    }
                }
            }
        }
    }
    if(!cnt) puts("NONE");
    else{
        sort(seq, seq+cnt);
        for(int i=0; i<cnt; i++){
            printf("%d %d\n", seq[i].a, seq[i].d);
        }
    }
    return 0;
}