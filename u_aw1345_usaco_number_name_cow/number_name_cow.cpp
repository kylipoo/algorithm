#include <iostream>

using namespace std;
int get(char c) {
    if(c <= 'O') {
        return (c-'A')/3 + 2;
    } else if(c <= 'S') {
        return 7;
    } else if(c <= 'V') {
        return 8;
    }
    return 9;
}

int main() {
    string num, str;
    cin >> num;
    int cnt=0;
    while(cin >> str) {
        string cur;
        for(auto c: str) {
            if(c=='Q' || c=='Z') {
                cur = "";
                break;
            }
            cur += get(c) + '0';
        }
        if(cur == num) {
            cout << str << endl;
            cnt++;
        }
    }
    if(!cnt) {
       cout << "NONE" << endl;
    }
    return 0;
}