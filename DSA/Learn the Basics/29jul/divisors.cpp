#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getDivisors(int n) {
        vector<int> d;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                d.push_back(i);
                
                if(n / i != i)
                    d.push_back(n/i);
            }
        }
        sort(d.begin(), d.end());
        return d;
    }
};

int main() {
    Solution s;
    vector<int> res = s.getDivisors(45);
    for(int x : res) {
        cout << x << " ";
    }
    return 0;
}