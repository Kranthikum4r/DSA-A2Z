# Power of Two
[Problem Link](https://leetcode.com/problems/power-of-two/)

**LeetCode Problem:** [231. Power of Two](https://leetcode.com/problems/power-of-two/)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

## Approach: Bit Manipulation

A number is a power of two if it contains exactly **one set bit (1)** in its binary representation.

Examples:
- `1` → `0001` → Power of 2
- `2` → `0010` → Power of 2
- `4` → `0100` → Power of 2
- `8` → `1000` → Power of 2
- `6` → `0110` → Not a power of 2

### Key Observation

For every positive power of two:

`n & (n - 1) == 0`

**Why does this work?**

- A power of two has exactly one set bit.
- Subtracting `1` flips that set bit to `0` and changes all trailing bits to `1`.
- Performing bitwise AND between `n` and `n - 1` results in `0`.

## C++ Solution

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(1)` – Only one bitwise AND operation is performed.
- **Space Complexity:** `O(1)` – No extra space is used.

## Edge Cases

| Input | Output | Explanation |
|---|---|---|
| `1` | `true` | 2⁰ = 1 |
| `2` | `true` | 2¹ = 2 |
| `16` | `true` | 2⁴ = 16 |
| `0` | `false` | Not positive |
| `-8` | `false` | Negative number |
| `6` | `false` | Not a power of two |

## Key Takeaway

The expression `n & (n - 1)` removes the rightmost set bit of a number. If the result is `0` and `n` is positive, the number is a power of two.

**Pattern to Remember:** Bit Manipulation – Checking whether a number has exactly one set bit.
