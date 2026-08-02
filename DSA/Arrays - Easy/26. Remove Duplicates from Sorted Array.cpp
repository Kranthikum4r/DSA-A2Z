class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, j = 0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=nums[j]) {
                count+=1;
                j+=1;
                nums[j]=nums[i];
            }
        }
        return count;
    }
};
