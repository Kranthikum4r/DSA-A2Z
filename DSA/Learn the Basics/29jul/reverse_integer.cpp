#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        if(x < INT_MIN || x > INT_MAX) return 0;

        long long rev = 0;
        while(x != 0) {
            int d = x % 10;
            rev = (rev * 10) + d;
            if(rev > INT_MAX || rev < INT_MIN) return 0;
            x /= 10;
        }
        if(rev > INT_MAX || rev < INT_MIN) return 0;
        return rev;
    }
};

int main() {
    Solution s;
    cout << s.reverse(-123);
    return 0;
}