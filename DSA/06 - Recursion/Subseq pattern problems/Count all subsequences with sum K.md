1498. Number of Subsequences That Satisfy the Given Sum Condition - [Link here](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

```
class Solution{
public:    	
    int count(int i, int sum, vector<int>& nums, int k) {
        if(sum == k) return 1;
        if(i == nums.size() || sum > k) return 0;

        int pick = count(i + 1, sum + nums[i], nums, k); // pick element
        int skip = count(i + 1, sum, nums, k); // skip element and continue

        return pick + skip;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        return count(0, 0, nums, k);
    }
};
```
