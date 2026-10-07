// Link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;

        for(char c : s) {
            if(c == '(') {
                st.push(c);
                int x = st.size();
                ans = max(ans, x);
            }
            else if(c == ')') {
                st.pop();
            }
        }
        return ans;
    }
};
