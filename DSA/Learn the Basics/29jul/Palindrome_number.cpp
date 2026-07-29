#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int org = x;
        long long rev = 0;
        while(x > 0) {
            int d = x % 10;
            rev = rev * 10 + d;
            x /= 10;
        }
        return rev == org;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(1221);
    return 0;
}