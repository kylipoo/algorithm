#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<char, string> PII;
const int N = 9;
queue<string> q;
unordered_map<string, PII> pre;
unordered_map<string, int> dist;
char g[2][4];

void set(string state) {
    for(int i=0; i<4; i++) {
        g[0][i] = state[i];
    }
    for(int i=7, j=0; i>3; i--, j++) {
        g[1][j] = state[i];
    }
}

string get() {
    string res;
    for(int i=0; i<4; i++) {
        res += g[0][i];
    }
    for(int j=3; j>=0; j--) {
        res += g[1][j];
    }
    return res;
}

string move0(string state) {
    set(state);
    for(int i=0; i<4; i++) {
        swap(g[0][i], g[1][i]);
    }
    return get();
}

string move1(string state) {
    set(state);
    int v0 = g[0][3], v1 = g[1][3];
    for(int i=0; i<2; i++) {
        for(int j=3;j>=0; j--) {
            g[i][j] = g[i][j-1];
        }
    }
    g[0][0] = v0, g[1][0] = v1;
    return get();
}

string move2(string state) {
    set(state);
    int v = g[0][2];
    g[0][2] = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = v;
    return get();
}

int bfs(string start, string end) {
    if(start == end) return 0;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        string t = q.front();
        q.pop();
        string m1 = move0(t);
        if(!dist.count(m1)) {
            dist[m1] = dist[t] + 1;
            pre[m1] = {'A', t};
            q.push(m1);
            if(m1 == end) return dist[m1];
        }
        string m2 = move1(t);
        if(!dist.count(m2)) {
            dist[m2] = dist[t] + 1;
            pre[m2] = {'B', t};
            q.push(m2);
            if(m2 == end) return dist[m2];
        }
        string m3 = move2(t);
        if(!dist.count(m3)) {
            dist[m3] = dist[t] + 1;
            pre[m3] = {'C', t};
            q.push(m3);
            if(m3 == end) return dist[m3];
        }
    }
    return -1;
}
int main() {
    string end;
    int c;
    for(int i=0; i<8; i++) {
        cin >> c;
        end += c + '0';
    }
    string start = "12345678";
    int step = bfs(start, end);
    cout << step << endl;
    string res;
    while(start!=end) {
        res += pre[end].x;u
        end = pre[end].y;
    }
    reverse(res.begin(), res.end());
    if(step>0) cout << res << endl;
}