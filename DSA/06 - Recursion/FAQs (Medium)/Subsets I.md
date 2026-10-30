# 78. Subsets

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topics:** Recursion, Backtracking, Arrays, Pick / Not Pick Pattern

## Problem Statement

Given an integer array `nums` of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

Return the solution in any order.

## Approach: Recursion (Include / Exclude)

We solve this problem using recursion and the Pick / Not Pick pattern.

At every index, we have two choices:

1. **Include:** Add the current element to the current subset and move to the next index.
2. **Exclude:** Remove the current element (backtracking) and move to the next index without including it.

We continue making these choices until all elements have been processed.

### Base Condition

When `i == nums.size()`:

- We have considered every element.
- Add the current subset to the answer.
- Return from the recursive function.

### Backtracking

After exploring the Include choice, we use `pop_back()` to remove the last inserted element.

This allows us to explore the Exclude choice without affecting the previously generated subsets.

## C++ Solution

```cpp
class Solution {
public:
    void generate(int i, vector<int>& nums, vector<int>& curr,
                  vector<vector<int>>& ans) {

        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include the current element
        curr.push_back(nums[i]);
        generate(i + 1, nums, curr, ans);

        // Backtrack (Exclude the current element)
        curr.pop_back();
        generate(i + 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(0, nums, curr, ans);

        return ans;
    }
};
```

## Example

**Input:**

```text
nums = [1, 2, 3]
```

**Output:**

```text
[
    [],
    [3],
    [2],
    [2, 3],
    [1],
    [1, 3],
    [1, 2],
    [1, 2, 3]
]
```

**Explanation:**

For every element, we have two choices: Include or Exclude.

For an array of 3 elements, the total number of possible subsets is:

\[
2^3 = 8
\]

The empty subset `[]` is also included.

## Recursion Tree

For `nums = [1, 2]`:

```text
                  []
                /    \
           Include 1  Exclude 1
              [1]       []
             /  \      /  \
         Include Exclude Include Exclude
           2       2      2       2
         [1,2]   [1]    [2]      []
```

The four subsets are:

```text
[1, 2]
[1]
[2]
[]
```

## Complexity Analysis

Let `N` be the number of elements in the input array.

**Time Complexity:** `O(N * 2^N)`

- There are `2^N` possible subsets.
- Each subset takes up to `O(N)` time to copy into the answer.

**Auxiliary Space Complexity:** `O(N)`

- Recursion stack: `O(N)`.
- Current subset: `O(N)`.
- Output space is excluded.

## Key Learnings

- Include / Exclude recursion pattern.
- Generating all possible subsets.
- Backtracking using `push_back()` and `pop_back()`.
- Understanding recursion tree structures.
- Every element has exactly two choices.

## Important Observations

- An array with `N` elements has exactly `2^N` subsets.
- The empty subset is always part of the answer.
- Each element is considered only once.
- No sorting or duplicate-skipping logic is required because the input contains unique elements.

**Pattern:** Include → Recursive Call → Backtrack → Exclude → Recursive Call.
