#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;
const int N = 6;
string A, B;
string a[N], b[N];
int n;

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[]) {
    int d = da[q.front()];
    while(q.size() && da[q.front()] == d) {
        auto t = q.front();
        q.pop();
        for(int i=0; i<n; i++) {
            for(int j=0; j<t.size(); j++) {
                if(t.substr(j, a[i].size()) == a[i]) {
                    string r = t.substr(0, j) + b[i] + t.substr(j+a[i].size());
                    if(db.count(r)) return da[t] + db[r] + 1;
                    if(da.count(r)) continue;
                    q.push(r);
                    da[r] = da[t] + 1;
                }
            }
        }
    }
    return 11;
}

int bfs() {
    if(A==B) return 0;
    unordered_map<string, int> da, db;
    queue<string> qa, qb;
    qa.push(A), qb.push(B);
    da[A] = 0, da[B] = 0;
    int step = 0;
    while(qa.size() && qb.size() ){
        int distance = 0;
        if(qa.size() > qb.size()) {
            distance = extend(qa, da, db, a, b);
        } else {
            distance = extend(qb, db, da, b, a);
        }
        if(distance<=10) return distance;
        if(++step >= 10) return -1;
    }
    return -1;
}

int main() {
    cin >> A >> B;
    while(cin >> a[n] >> b[n]) n++;
    int step = bfs();
    if(step == -1) puts("NO ANSWER!");
    else cout << step << endl;
    return 0;
}