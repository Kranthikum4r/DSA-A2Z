// Link - https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1. Ignore leading spaces
        while(i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Convert digits
        long long result = 0;

        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            result = result * 10 + digit;

            // 4. Check overflow
            if(sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }

            if(sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * result;
    }
};
