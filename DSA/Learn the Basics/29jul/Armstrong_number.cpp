#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        int k = to_string(n).size();
        int s = 0;
        for (int x = n; x; x /= 10) {
            s += round(pow(x % 10, k));
        }
        return s == n;
    }
};

int main() {
    Solution s;
    cout << s.isArmstrong(153);
    return 0;
}