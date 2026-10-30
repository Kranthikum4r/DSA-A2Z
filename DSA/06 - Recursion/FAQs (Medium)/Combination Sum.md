# 39. Combination Sum

[Link here](https://leetcode.com/problems/combination-sum/)

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topic:** Recursion, Backtracking, Pick / Not Pick Pattern

## Problem Statement

Given an array of distinct integers `candidates` and a target integer `target`, return all unique combinations of candidates where the chosen numbers sum to `target`.

You may choose the same number an unlimited number of times.

The combinations should be returned in any order.

## Approach: Recursion (Pick / Not Pick)

We solve this problem using recursion and backtracking.

At every index, we have two choices:

1. **Pick:** Include the current element in the combination. Since repetition is allowed, we stay at the same index.
2. **Not Pick:** Skip the current element and move to the next index.

### Base Conditions

- If `sum == target`, we have found a valid combination. Add the current combination to the answer.
- If `sum > target`, stop exploring that recursive path.
- If `i == arr.size()`, all candidates have been processed.

### Backtracking

After exploring the Pick condition, we remove the last inserted element using `pop_back()` before exploring the Not Pick condition.

This ensures that the current combination remains correct for other recursive branches.

## C++ Solution

```cpp
class Solution {
public:
    void findcomb(int i, int sum, int target, vector<int>& arr,
                  vector<int>& cur, vector<vector<int>>& ans) {

        if(sum == target) {
            ans.push_back(cur);
            return;
        }

        if(sum > target || i == arr.size()) return;

        // Pick the current element (repetition allowed)
        cur.push_back(arr[i]);
        findcomb(i, sum + arr[i], target, arr, cur, ans);

        // Backtrack
        cur.pop_back();

        // Not Pick the current element
        findcomb(i + 1, sum, target, arr, cur, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        findcomb(0, 0, target, candidates, cur, ans);

        return ans;
    }
};
```

## Example

**Input:**
```text
candidates = [2, 3, 6, 7]
target = 7
```

**Output:**
```text
[[2, 2, 3], [7]]
```

**Explanation:**

- `2 + 2 + 3 = 7`
- `7 = 7`

Both combinations satisfy the target.

## Complexity Analysis

Let:
- `N` = Number of candidates.
- `T` = Target value.
- `M` = Minimum candidate value.

**Time Complexity:** Exponential in the worst case, approximately `O(2^(T/M + N))` as a loose upper bound on the recursion tree, excluding the cost of copying stored combinations.

**Space Complexity:** `O(T/M + N)` auxiliary recursion and current-combination space, excluding the output.

## Key Learnings

- Pick / Not Pick recursion pattern.
- Reusing an element by keeping the same index.
- Moving to the next index when skipping an element.
- Backtracking using `push_back()` and `pop_back()`.
- Pruning unnecessary recursive calls using base conditions.

**Important:** This implementation assumes all candidate values are positive integers.
