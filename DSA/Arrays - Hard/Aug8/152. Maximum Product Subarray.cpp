class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        int minPro = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(minPro, maxPro);
            }

            minPro = min(nums[i], minPro * nums[i]);
            maxPro = max(nums[i], maxPro * nums[i]);

            ans = max(ans, maxPro);
        }
        return ans;
    }
};
