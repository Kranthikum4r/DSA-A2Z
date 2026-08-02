class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j=0,n=nums.size();
        for(i=0;i<n;i++) {
            if(nums[i]!=0){
                nums[j] = nums[i];
                j++;
            }
        }
        while(j<n) {
            nums[j] = 0;
            j++;
        }
    }
};
