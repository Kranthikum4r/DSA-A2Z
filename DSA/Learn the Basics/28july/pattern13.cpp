#include <bits/stdc++.h>
using namespace std;

void pattern13(int N) {
    int num = 1;

    for (int i = 1; i <= N; i++) {

        // Inner loop to print numbers increasing by 1 in each row
        for (int j = 1; j <= i; j++) {
            cout << num << " ";  // Print the current number followed by a space
            num = num + 1;  // Increment the number for the next print
        }

        // Move to the next line after printing the current row
        cout << endl;
    }
}

int main() {
    int N = 5;
    pattern13(N);

    return 0;
}