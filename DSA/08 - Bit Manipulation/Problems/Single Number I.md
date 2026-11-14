# Single Number I
[Problem Link](https://leetcode.com/problems/single-number/)

## Problem Statement
Given a non-empty array of integers `nums`, every element appears twice except for one element that appears exactly once.

Find and return the element that appears only once.

## Approach: XOR

### Intuition
We can solve this problem efficiently using the XOR (`^`) bitwise operator.

Important XOR properties:

1. `a ^ a = 0` — XOR of the same numbers is zero.
2. `a ^ 0 = a` — XOR with zero returns the same number.
3. XOR is commutative: `a ^ b = b ^ a`.
4. XOR is associative: `(a ^ b) ^ c = a ^ (b ^ c)`.

Since every element appears twice, their XOR becomes zero. The remaining element is the answer.

### Algorithm
1. Initialize `xr = 0`.
2. Traverse the array using a range-based for loop.
3. XOR each element with `xr`.
4. After processing all elements, return `xr`.

## C++ Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;

        for(int x : nums) {
            xr ^= x;
        }

        return xr;
    }
};
```

## Dry Run

**Input:**
```text
nums = [4, 1, 2, 1, 2]
```

| Element | XOR Operation | xr |
|---|---|---|
| 4 | 0 ^ 4 | 4 |
| 1 | 4 ^ 1 | 5 |
| 2 | 5 ^ 2 | 7 |
| 1 | 7 ^ 1 | 6 |
| 2 | 6 ^ 2 | 4 |

**Output:**
```text
4
```

The duplicate elements cancel each other because `a ^ a = 0`.

## Complexity Analysis

- **Time Complexity:** O(N) — We traverse the array exactly once.
- **Space Complexity:** O(1) — We use only one extra variable (`xr`).

## Key Takeaway

XOR is particularly useful for problems involving pairs of identical numbers.

When every element appears twice except one:

**Single Number = XOR of all array elements.**
