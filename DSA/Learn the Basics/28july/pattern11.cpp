#include <bits/stdc++.h>
using namespace std;

void pattern11(int N) {
    int start = 1;
    
    for (int i = 0; i < N; i++) {
        // If the row index is even, print 1 first in that row
        if (i % 2 == 0) start = 1;
        
        // If the row index is odd, print 0 first in that row
        else start = 0;
        
        // Inner loop to print alternating 1's and 0's in each row
        for (int j = 0; j <= i; j++) {
            cout << start;
            // Alternate between 1 and 0
            start = 1 - start;
        }

        // Move to the next line after each row is printed
        cout << endl;
    }
}

int main() {
    int N = 5;
    pattern11(N);
    return 0;
}