# Single Number III
[Problem Link](https://leetcode.com/problems/single-number-iii/)

## Problem Statement
Given an integer array `nums`, every element appears exactly twice except for two elements that appear only once.

Find and return the two unique elements in any order.

## Approach: XOR + Bit Manipulation

### Intuition
We can solve this problem using XOR properties without using extra data structures.

Important XOR properties:

1. `a ^ a = 0` — XOR of two identical numbers is zero.
2. `a ^ 0 = a` — XOR with zero returns the same number.
3. XOR is commutative and associative.

Since every element appears twice except two unique numbers (`a` and `b`), XORing all elements gives:

```text
xr = a ^ b
```

Because `a` and `b` are different, their XOR must contain at least one set bit.

We use this set bit to separate the numbers into two groups.

### Algorithm

**Step 1: XOR all elements**

```cpp
int xr = 0;
for(int x : nums) {
    xr ^= x;
}
```

After this operation:

```text
xr = a ^ b
```

**Step 2: Find the rightmost set bit**

```cpp
unsigned int mask = static_cast<unsigned int>(xr);
mask &= -mask;
```

- Convert `xr` into an unsigned integer.
- `mask &= -mask` extracts the rightmost set bit.
- This unsigned operation avoids signed integer overflow when `xr` is `INT_MIN`.

**Step 3: Divide elements into two groups**

```cpp
if(num & mask)
    ans[0] ^= num;
else
    ans[1] ^= num;
```

- Group 1 contains numbers whose selected bit is set.
- Group 2 contains numbers whose selected bit is not set.

The two unique numbers must belong to different groups because their XOR has that selected bit set.

**Step 4: XOR each group**

All duplicate elements cancel each other, leaving one unique number in each group.

Return the two elements.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums;

        int xr = 0;
        for(int x : nums) xr ^= x;

        vector<int> ans = {0, 0};

        // Get the rightmost set bit
        unsigned int mask = static_cast<unsigned int>(xr);
        mask &= -mask;

        for(int num : nums) {
            if(static_cast<unsigned int>(num) & mask)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        }

        return ans;
    }
};
```

## Dry Run

**Input:**
```text
nums = [1, 2, 1, 3, 2, 5]
```

### Step 1: XOR all elements

```text
xr = 1 ^ 2 ^ 1 ^ 3 ^ 2 ^ 5

xr = 3 ^ 5

xr = 6
```

Binary representation:

```text
6 = 0110
```

### Step 2: Extract the rightmost set bit

```cpp
mask &= -mask;
```

```text
 6  = 0110
-6  = 1010  (4-bit illustration)
      ----
      0010
```

Therefore:

```text
mask = 2
```

### Step 3: Divide into two groups

Check whether `num & mask` is non-zero.

| Number | Binary | num & mask | Group |
|---|---|---|---|
| 1 | 0001 | 0 | Group 2 |
| 2 | 0010 | 2 | Group 1 |
| 1 | 0001 | 0 | Group 2 |
| 3 | 0011 | 2 | Group 1 |
| 2 | 0010 | 2 | Group 1 |
| 5 | 0101 | 0 | Group 2 |

### Step 4: XOR within each group

Group 1:

```text
2 ^ 3 ^ 2 = 3
```

Group 2:

```text
1 ^ 1 ^ 5 = 5
```

**Output:**
```text
[3, 5]
```

## Complexity Analysis

- **Time Complexity:** O(N) — Two traversals of the array.
- **Space Complexity:** O(1) — Only a constant number of auxiliary variables are used. The output vector is excluded.

## Key Takeaways

1. XORing all elements cancels the duplicates.
2. The XOR result contains different bits between the two unique numbers.
3. Extracting the rightmost set bit helps separate the two unique numbers.
4. XORing each group independently gives the required answers.
5. Using `unsigned int` for `x & -x` avoids signed integer overflow at `INT_MIN`.

**Core Bit Manipulation Formula:**

```cpp
mask = x & -x;
```

This extracts the rightmost set bit of a non-zero integer `x` when performed using unsigned arithmetic.
