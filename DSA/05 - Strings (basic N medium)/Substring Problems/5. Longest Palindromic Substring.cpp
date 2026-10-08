// Link - https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;

        int maxlen = 1, start = 0;
        int l, r;
        for(int i = 0; i < n; i++) {

            l = i, r = i; // odd length
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--; r++;
            }
        }

        for(int i = 0; i < n; i++) {
            l = i, r = i + 1; // even length
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxlen) {
                    maxlen = r - l + 1;
                    start = l;
                }
                l--; r++;
            }
        }

        return s.substr(start, maxlen);
    }
};
