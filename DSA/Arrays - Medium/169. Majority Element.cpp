class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int target;
        for(int num : nums) {
            if(count == 0) {
                target = num;
            }
            count += (target == num) ? 1 : -1;
        }
        return target;
    }
};
