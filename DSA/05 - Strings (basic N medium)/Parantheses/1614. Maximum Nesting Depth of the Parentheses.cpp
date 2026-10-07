// Link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;

        for(char c : s) {
            if(c == '(') {
                st.push(c);
                ans = max(ans, (int)st.size();
            }
            else if(c == ')') {
                st.pop();
            }
        }
        return ans;
    }
};
