class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i+1; j < n; j++) {

                if(j > i+1 && nums[j-1] == nums[j]) continue;

                int left = j+1, right = n-1;
                while(left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && (nums[left-1] == nums[left])) 
                            left++;
                        while(left < right && (nums[right] == nums[right+1])) 
                            right--;
                    }
                    else if(sum > target) right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};
