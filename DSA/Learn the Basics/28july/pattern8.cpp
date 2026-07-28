#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pattern8(int N) {
        for (int i = 0; i < N; i++) {
            
            for (int j = 0; j < i; j++) {
                cout << " ";
            }

            // Formula: total stars = 2*N - (2*i + 1)
            for (int j = 0; j < 2 * N - (2 * i + 1); j++) {
                cout << "*";
            }

            for (int j = 0; j < i; j++) {
                cout << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    Solution sol;
    int N = 5;
    sol.pattern8(N);
    return 0;
}