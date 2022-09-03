#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;
int son[N][26], cnt[N], idx;

void insert(string str) {
    int p = 0;
    for(int i=0; i<str.size(); i++) {
        int u = str[i]-'a';
        if(!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str) {
    int p = 0;
    for(int i=0; i<str.size(); i++) {
        int u = str[i] - 'a';
        //cout<< son[p][u] << endl;
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    char op;
    string str;
    while(n--) {
        cin >> op >> str;
        if(op == 'I') {
            insert(str);
        } else {
            cout << query(str) << endl;
        }
    }
    return 0;
}