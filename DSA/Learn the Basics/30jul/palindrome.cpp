class Solution {
public:
    bool palindrome(int i, string& s) {
        if(i >= s.length() / 2) return true;

        if(s[i] != s[s.length() - i - 1]) return false;

        return palindrome(i + 1, s);
    }
    bool isPalindrome(string s) {
        return palindrome(0, s);
    }
};