[Link here](https://leetcode.com/problems/subsets-ii/description/)

# 90. Subsets II (Important for revision)

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topics:** Recursion, Backtracking, Sorting, Duplicate Handling

## Problem Statement

Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

Return the solution in any order.

## Approach: Backtracking (For Loop Pattern)

We solve this problem using recursion and backtracking with a `for` loop.

Instead of using the traditional Include / Exclude approach, we use a loop to explore all possible choices starting from the current index.

### Steps

1. Sort the input array so that duplicate elements become adjacent.
2. Add the current subset to the answer at the beginning of every recursive call.
3. Use a `for` loop starting from index `i` to explore possible elements.
4. Skip duplicate elements at the same recursion level.
5. Include the current element in the subset.
6. Recursively call the function with `j + 1` to ensure each element is used only once.
7. Backtrack using `pop_back()` to explore other possibilities.

### Handling Duplicates

The important condition is:

```cpp
if(j > i && nums[j] == nums[j - 1]) continue;
```

**Explanation:**

- `j > i` ensures we skip duplicates only at the same recursion level.
- `nums[j] == nums[j - 1]` checks whether the current element is equal to the previous element.
- `continue` skips the duplicate element.

This prevents generating duplicate subsets without using a `set`.

## C++ Solution

```cpp
class Solution {
public:
    void generate(int i, vector<int>& curr, vector<int>& nums,
                  vector<vector<int>>& ans) {

        // Store the current subset
        ans.push_back(curr);

        // Explore all possible choices
        for(int j = i; j < nums.size(); j++) {

            // Skip duplicates at the same recursion level
            if(j > i && nums[j] == nums[j - 1]) continue;

            // Pick
            curr.push_back(nums[j]);

            // Recursive call
            generate(j + 1, curr, nums, ans);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        // Sort to bring duplicates together
        sort(nums.begin(), nums.end());

        generate(0, curr, nums, ans);

        return ans;
    }
};
```

## Example

**Input:**

```text
nums = [1, 2, 2]
```

**Output:**

```text
[
    [],
    [1],
    [1, 2],
    [1, 2, 2],
    [2],
    [2, 2]
]
```

**Explanation:**

The input contains duplicate elements (`2` appears twice).

The algorithm generates all possible unique subsets while avoiding duplicate combinations.

Total unique subsets = `6`.

## Recursion Tree

For `nums = [1, 2, 2]`:

```text
                       []
                    /       \
                  [1]        [2]
                 /   \         |
             [1,2]  (skip)   [2,2]
               |
           [1,2,2]
```

The duplicate `2` is skipped when it appears as another choice at the same recursion level.

## Complexity Analysis

Let `N` be the number of elements in the input array.

**Time Complexity:** `O(N * 2^N)`

- Sorting takes `O(N log N)`.
- There can be at most `2^N` subsets.
- Copying each subset into the answer takes up to `O(N)` time.

**Auxiliary Space Complexity:** `O(N)`

- Recursion stack: `O(N)`.
- Current subset: `O(N)`.
- Output space is excluded.

## Key Learnings

- Backtracking using the For Loop pattern.
- Sorting to handle duplicate elements.
- Skipping duplicates at the same recursion level.
- Using `j + 1` to avoid reusing an element.
- Backtracking using `push_back()` and `pop_back()`.
- Generating unique subsets without using a `set`.

## Difference Between Subsets (78) and Subsets II (90)

| Feature | Subsets (78) | Subsets II (90) |
|---|---|---|
| Input | Unique elements | Duplicate elements possible |
| Pattern | Include / Exclude | For Loop + Backtracking |
| Sorting | Not required | Required for this approach |
| Duplicate handling | Not required | Required |
| Recursive index | `i + 1` | `j + 1` |

## Important Observations

1. Every recursive call represents one valid subset.
2. `ans.push_back(curr)` is placed at the beginning of the recursive function.
3. Sorting makes duplicate detection easier.
4. The condition `j > i` ensures that duplicates are skipped only at the current recursion level, not across different levels.
5. No separate base condition is necessary because the `for` loop naturally stops when all elements are processed.

**Pattern:** Sort → Store Current Subset → For Loop → Skip Duplicates → Pick → Recursion → Backtrack.
