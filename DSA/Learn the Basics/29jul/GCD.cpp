#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};

int main() {
    Solution s;
    cout << s.gcd(5, 10);
    return 0;
}

