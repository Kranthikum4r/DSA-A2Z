class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int l = 1, h = *max_element(nums.begin(), nums.end());
        if(threshold == n) {
            return h;
        }
        
        int ans;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            int sum = 0;
            for(int i = 0; i < n; i++) {
               sum += (nums[i]+mid-1) / mid;
            }

            if(sum <= threshold) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
