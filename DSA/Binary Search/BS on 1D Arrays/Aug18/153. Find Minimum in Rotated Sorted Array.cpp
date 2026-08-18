class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, mid;
        while(l < h) {
            mid = (l + h) / 2;
            if(nums[mid] > nums[h]) // starting in right half
                l = mid + 1;
            else
                h = mid;
        }
        return nums[l];
    }
};
