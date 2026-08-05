class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 1;
        for(auto it : s) {
            if(!s.count(it-1)) {
                int len = 1;
                int x = it;
                while(s.count(x+1)) {
                    x++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
