#include <iostream>

using namespace std;

const int N = 1e5+10;
int n, m;
int p[N], sz[N];

int find(int x) {
    if(p[x] != x) {
        p[x]=find(p[x]);
        return p[x];
    }
}
int main() {
    //input
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for(int i=0; i<m; i++) {
        char op[5];
        int a, b;
        scanf("%s", op);
        if(op[0] == 'C'){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) {
                continue; //a and b are same node
            }
            sz[find(b)] +=sz[find(a)];
            p[find(a)] = find(b);
        } else if(op[1] == '1') {
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) {
                puts("Yes");
            } else {
                puts("No");
            }
        } else {
            scanf("%d", &a);
            printf("%d\n", sz[find(a)]);
        }
    }
    return 0;
}
