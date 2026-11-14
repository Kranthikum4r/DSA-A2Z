# Single Number II
[Problem Link](https://leetcode.com/problems/single-number-ii/)

## Problem Statement
Given an integer array `nums`, every element appears exactly three times except for one element, which appears exactly once.

Find and return the element that appears only once.

## Approach: Bit Manipulation (Bit Counting)

### Intuition
Instead of using a hash map, we can solve this problem by counting the set bits at each bit position.

Since every number except one appears three times:

- Count how many numbers have the ith bit set.
- If the count is divisible by 3, that bit belongs to the repeating numbers.
- Otherwise, the remaining bit belongs to the unique number.

By checking all 32 bit positions, we can reconstruct the unique number.

### Algorithm
1. Initialize `ans = 0`.
2. Iterate through all 32 bit positions (`i = 0` to `31`).
3. Initialize `sum = 0` for each bit position.
4. Traverse the entire array:
   - Right-shift each number by `i`.
   - Apply `& 1` to check whether the ith bit is set.
   - Add the result to `sum`.
5. If `sum % 3 != 0`, set the ith bit in `ans` using `ans | (1 << i)`.
6. Return `ans`.

## C++ Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < 32; i++) {
            int sum = 0;

            // Count numbers having the ith bit set
            for(int x : nums) {
                sum += ((x >> i) & 1);
            }

            if(sum % 3 != 0) {
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
};
```

## Dry Run

**Input:**
```text
nums = [2, 2, 3, 2]
```

Binary representation (4-bit illustration):

```text
2 = 0010
2 = 0010
3 = 0011
2 = 0010
```

Count the set bits at each position:

| Bit Position | Set Bit Count | Count % 3 | Result |
|---|---:|---:|---|
| 0 | 1 | 1 | Set |
| 1 | 4 | 1 | Set |
| 2 | 0 | 0 | Not set |
| 3 | 0 | 0 | Not set |

The remaining bits form:

```text
0011 = 3
```

**Output:**
```text
3
```

## Complexity Analysis

Let N be the number of elements in the array.

- **Time Complexity:** O(32 × N) = O(N), because we check all 32 bit positions for every element.
- **Space Complexity:** O(1), because we use only a constant amount of extra space.

## Key Takeaways

1. Bit counting helps identify bits belonging to a unique number.
2. Modulo 3 eliminates contributions from numbers appearing three times.
3. The same technique can be extended to problems where elements appear K times except one element appearing once.

**Core Logic:**

`sum % 3 != 0` means the corresponding bit must be set in the unique number.

**Note:** This implementation assumes a 32-bit `int` and uses signed right shifts. For standard LeetCode constraints, it works with the usual two's-complement behavior. When handling negative integers portably, use an unsigned integer for bit extraction and explicitly handle the sign bit when reconstructing the result.
