# Count Set Bits
[Problem Link](https://leetcode.com/problems/number-of-1-bits/)

**Topic:** Bit Manipulation  
**Approach:** Right Shift + Bitwise AND

## Approach

The goal is to count the number of set bits (`1`s) in the binary representation of a given number.

We can achieve this using two bitwise operations:

1. **Bitwise AND (`n & 1`):**
   - Checks whether the last bit of `n` is set.
   - If the result is `1`, increment the counter.

2. **Right Shift (`n >>= 1`):**
   - Removes the last bit by shifting all bits one position to the right.
   - Repeat until `n` becomes `0`.

## C++ Solution

```cpp
class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;
        
        while(n) {
            if(n & 1) cnt++;
            n >>= 1;
        }

        return cnt;
    }
};
```

## Example Dry Run

**Input:** `n = 13`

Binary representation of 13 = `1101`

| Iteration | n (Binary) | n & 1 | cnt |
|---|---|---|---|
| 1 | 1101 | 1 | 1 |
| 2 | 0110 | 0 | 1 |
| 3 | 0011 | 1 | 2 |
| 4 | 0001 | 1 | 3 |

**Output:** `3`

## Complexity Analysis

- **Time Complexity:** `O(log n)` – We process each bit of the number once.
- **Space Complexity:** `O(1)` – Only a counter variable is used.

## Key Takeaway

- `n & 1` checks whether the last bit is `1`.
- `n >> 1` removes the last bit.
- Count the number of set bits by repeatedly checking and shifting.

**Pattern to Remember:** Bit Manipulation – Counting set bits using right shift.
