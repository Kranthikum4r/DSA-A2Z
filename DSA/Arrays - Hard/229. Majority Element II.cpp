class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        for(int num:nums) {
            if(num == el1) cnt1++;
            else if(num == el2) cnt2++;
            else if(cnt1 == 0) {
                cnt1 = 1;
                el1 = num;
            }
            else if(cnt2 == 0) {
                cnt2 = 1;
                el2 = num;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(int num:nums) {
            if(num == el1) cnt1++;
            if(num == el2) cnt2++;
        }
        vector<int> ans;
        int n = nums.size() / 3;
        if(cnt1 > n) ans.push_back(el1); 
        if(cnt2 > n) ans.push_back(el2);
        return ans;
    }
};
