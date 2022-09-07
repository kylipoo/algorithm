#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

queue<string> q;
unordered_map<string, int> d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0,  1};

int bfs(string start) {
    string end = "12345678x";
    q.push(start);
    d[start] = 0;
    int distance = 0;
    while(q.size()) {
        string t = q.front();
        q.pop();
        distance = d[t];
        if(t == end) {
            return distance;
        }
        int idx = t.find('x');
        int x = idx/3, y = idx%3;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx < 3 && ny>=0 && ny < 3) {
                swap(t[idx], t[nx*3+ny]);
                if(!d.count(t)) {
                    q.push(t);
                    d[t] = distance + 1;
                }
                swap(t[idx], t[nx*3+ny]);
            }
        }
    }
    return -1;
}
int main() {
    string start="";
    for(int i=0; i<9; i++) {
        string s;
        cin >> s;
        start +=s;
    }
    cout << bfs(start) << endl;
    return 0;
}
