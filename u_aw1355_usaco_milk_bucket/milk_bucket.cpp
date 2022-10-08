#include <iostream>

using namespace std;

const int N = 21;
bool st[N][N][N];
int A, B, C;
struct Node{
    int a, b, c;
}q[N*N*N];
int hh, tt;

void insert(int a, int b, int c) {
    if(!st[a][b][c]) {
        st[a][b][c] = true;
        q[++tt] = {a, b, c};
    }
}
bool bfs() {
    q[0] = {0,0,C};
    st[0][0][C] = true;
    while(hh<=tt) {
        auto t = q[hh++];
        int a = t.a, b=t.b, c=t.c;
        insert(a-min(a, B-b), min(B, b+a), c);
        insert(a-min(a, C-c), b, min(C, c+a));
        insert(min(A, a+b), b-min(b, A-a), c);
        insert(a, b-min(b, C-c), min(C, b+c));
        insert(min(a+c, A), b, c-min(A-a, c));
        insert(a, min(b+c, B), c-min(B-b, c));
    }

}
int main() {
   cin >> A >> B >> C;
   bfs();
   for(int c=0; c<=C; c++) {
       for(int b=0; b<=B; b++) {
           if(st[0][b][c]) {
               printf("%d ", c);
               break;
           }
       }
   }
   return 0;
}