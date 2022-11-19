#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int q[N];
int dist[N];
int g[N];
int n, k;

int bfs() {
    q[0] = n;
    memset(dist, -1,sizeof dist);
    dist[n] = 0;
    int hh=0, tt = 0;
    while(hh<=tt) {
        int t = q[hh++];
        if(t == k) return dist[k];
        if(t-1>=0 && dist[t-1] ==-1) {
            // pay attention to update dist then q as it is rely on tt
            dist[t-1] = dist[t] + 1;
            q[++tt] = t-1;
        }
        if(t+1<N && dist[t+1] ==-1) {
            dist[t+1] = dist[t] + 1;
            q[++tt] = t+1;
        }
        if(2*t < N && dist[2*t] == -1) {
            dist[2*t] = dist[t] + 1;
            q[++tt] = 2*t;
        }
    }
    return -1;
}

int main() {
    cin >> n >> k;
    cout << bfs() << endl;
}