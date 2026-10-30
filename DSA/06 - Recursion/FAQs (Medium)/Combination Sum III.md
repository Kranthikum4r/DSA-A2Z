# 216. Combination Sum III
[Problem Link](https://leetcode.com/problems/combination-sum-iii/description/)

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topics:** Recursion, Backtracking, Pick / Not Pick Pattern

## Problem Statement

Find all valid combinations of `k` numbers that sum up to `n` such that:

- Only numbers from `1` to `9` are used.
- Each number can be used at most once.
- Every combination must contain exactly `k` numbers.

Return all possible valid combinations.

## Approach: Recursion (Pick / Not Pick)

We solve this problem using recursion and backtracking.

At every index, we have two choices:

1. **Pick:** Include the current number in the combination and move to the next number.
2. **Not Pick:** Skip the current number and move to the next number.

We start from `1` and explore numbers up to `9`.

### Base Conditions

1. If `curr.size() == k`:
   - Check whether `sum == n`.
   - If true, add the current combination to the answer.
   - Return because we cannot select more than `k` elements.

2. If `sum > n`, stop exploring that recursive path because all remaining numbers are positive.

3. If `i > 9`, stop because only numbers from `1` to `9` are allowed.

### Backtracking

After exploring the Pick condition, remove the last inserted element using `pop_back()`.

This allows us to explore the Not Pick condition without affecting the current combination.

## C++ Solution

```cpp
class Solution {
public:
    void findcomb(int i, int sum, int n, int k,
                  vector<int>& curr, vector<vector<int>>& ans) {

        if(curr.size() == k) {
            if(sum == n) {
                ans.push_back(curr);
            }
            return;
        }

        if(sum > n || i > 9) return;

        // Pick
        curr.push_back(i);
        findcomb(i + 1, sum + i, n, k, curr, ans);

        // Backtrack
        curr.pop_back();

        // Not Pick
        findcomb(i + 1, sum, n, k, curr, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        findcomb(1, 0, n, k, curr, ans);

        return ans;
    }
};
```

## Example

**Input:**

```text
k = 3
n = 7
```

**Output:**

```text
[[1, 2, 4]]
```

**Explanation:**

We need exactly 3 distinct numbers whose sum is 7.

The valid combination is:

```text
1 + 2 + 4 = 7
```

## Another Example

**Input:**

```text
k = 3
n = 9
```

**Output:**

```text
[
    [1, 2, 6],
    [1, 3, 5],
    [2, 3, 4]
]
```

## Recursion Pattern

At every index, we make two choices:

```text
                Current Index (i)
                 /           \
              Pick          Not Pick
               |               |
          Include i        Skip i
               |               |
          sum + i           sum unchanged
               |               |
            i + 1            i + 1
```

## Complexity Analysis

Let `N = 9`, since we have exactly nine possible numbers.

**Time Complexity:** `O(2^9 * k)`

- Each number has two choices: Pick or Not Pick.
- There are at most `2^9` possible subsets.
- Copying a valid combination takes `O(k)` time.

**Auxiliary Space Complexity:** `O(9) = O(1)`

- Recursion stack: At most 9 levels.
- Current combination: At most `k` elements.
- Output space is excluded.

## Key Learnings

- Pick / Not Pick recursion pattern.
- Generating combinations with exactly `k` elements.
- Maintaining the current sum during recursion.
- Backtracking using `push_back()` and `pop_back()`.
- Using pruning to avoid unnecessary recursive calls.
- Ensuring every number is selected at most once.

## Important Observations

1. Start recursion from `1`, not `0`.
2. Only numbers from `1` to `9` are allowed.
3. Use `i + 1` in both recursive calls because repetition is not allowed.
4. Check `curr.size() == k` before adding a combination.
5. Reaching `k` elements must terminate that branch, even if the target sum is not achieved.
6. No sorting or duplicate-skipping logic is required because numbers from `1` to `9` are unique.

## Related Problems

- [LeetCode 39 – Combination Sum](https://leetcode.com/problems/combination-sum/)
- [LeetCode 40 – Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
- [LeetCode 78 – Subsets](https://leetcode.com/problems/subsets/)
- [LeetCode 90 – Subsets II](https://leetcode.com/problems/subsets-ii/)

**Pattern:** Pick → Recursive Call → Backtrack → Not Pick → Recursive Call.
