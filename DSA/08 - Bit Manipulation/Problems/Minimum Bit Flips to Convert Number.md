# Minimum Bit Flips to Convert Number
[Problem Link](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)

## Problem Statement
Given two integers `start` and `goal`, find the minimum number of bit flips required to convert `start` into `goal`.

A bit flip changes:
- `0` to `1`
- `1` to `0`

## Approach: XOR + Counting Set Bits

### Intuition
We can use the XOR (`^`) operator to identify the positions where the bits of `start` and `goal` differ.

- XOR returns `0` when both bits are equal.
- XOR returns `1` when both bits are different.

Therefore, the minimum number of bit flips is equal to the number of set bits (`1`s) in `start ^ goal`.

### Algorithm
1. Calculate `x = start ^ goal`.
2. Initialize `flips = 0`.
3. Iterate while `x` is greater than zero:
   - Add `x & 1` to `flips` to count the last bit.
   - Right-shift `x` by one position.
4. Return `flips`.

## C++ Solution

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int flips = 0;

        while(x) {
            flips += (x & 1);
            x >>= 1;
        }

        return flips;
    }
};
```

## Dry Run

**Input:**
```text
start = 10
goal = 7
```

**Binary Representation:**
```text
start = 1010
goal  = 0111
--------------
XOR   = 1101
```

Counting the set bits:

| Iteration | x (Binary) | x & 1 | flips |
|---|---|---|---|
| 1 | 1101 | 1 | 1 |
| 2 | 110 | 0 | 1 |
| 3 | 11 | 1 | 2 |
| 4 | 1 | 1 | 3 |

**Output:**
```text
3
```

## Complexity Analysis

- **Time Complexity:** O(log N) — We iterate through the bits of the XOR result.
- **Space Complexity:** O(1) — Only a constant amount of extra space is used.

## Key Takeaway

XOR is useful for comparing two binary numbers because it identifies all positions where their bits differ.

**Minimum Bit Flips = Number of Set Bits in (start ^ goal).**
