Subsequence with Sum K - [Link here](https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1)
##Brute Force:
###Complexity
- Time: O(2^n) in the worst case.
- Auxiliary space: O(n) for the recursion stack.
```
class Solution {
  public:
    bool traverse(int i, int sum, vector<int>& arr, int k) {
        if(sum == k) return true;
        if(i == arr.size()) return false;
        
        if(traverse(i + 1, sum + arr[i], arr, k))
            return true;
        if(traverse(i + 1, sum, arr, k))
            return true;
            
        return false;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // if sum > k -> pop
        // else add 
        return traverse(0, 0, arr, k);
    }
};
```
##Optimal:
###Complexity
- Time: O(2^n) in the worst case.
- Auxiliary space: O(n) for the recursion stack.

```
class Solution {
  public:
    bool traverse(int i, int sum, vector<int>& arr, int k) {
        if(sum == k) return true;
        if(i == arr.size() || sum > k) return false;
        
        return traverse(i + 1, sum + arr[i], arr, k) || 
        traverse(i + 1, sum, arr, k);
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return traverse(0, 0, arr, k);
    }
};
```
