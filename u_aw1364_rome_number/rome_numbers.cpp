#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string names[13] = {
            "M", "CM", "D", "CD", "C", "XC", "L",
            "XL", "X", "IX", "V", "IV", "I"
    };
    int nums[13] = {
            1000, 900, 500, 400, 100, 90, 50, 40,
            10, 9, 5, 4, 1
    };   unordered_map<char, int> cnt;
    for(int i=1; i<=n; i++) {
        for(int j=0, x = i; j<13; j++) {
            while(x >= nums[j]) {
                x -= nums[j];
                for(auto c: names[j]) {
                    cnt[c]++;
                }
            }
        }
    }
    string cs = "IVXLCDM";
    for (auto c: cs)
        if (cnt[c])
            cout << c << ' ' << cnt[c] << endl;
    return 0;
}