# Set the Rightmost Unset Bit

**Approach:** Bit Manipulation

## Approach

The objective is to set the rightmost unset bit (change the first `0` from the right into `1`).

We can solve this using bitwise operations.

1. Start traversing the bits from the rightmost position.
2. Check whether the current bit is unset using `(n & (1 << i)) == 0`.
3. If an unset bit is found, set it using `n | (1 << i)`.
4. Return the modified number.
5. If all bits are set, return the original number.

## C++ Solution (Optimized)

```cpp
class Solution {
public:
    int setBit(int n) {
        int i = 0;

        while(n & (1 << i)) {
            i++;
        }

        return n | (1 << i);
    }
};
```

## Example Dry Run

**Input:** `n = 10`

Binary representation: `1010`

| Bit Position | Bit Value | Operation |
|---|---|---|
| 0 | 0 | Set this bit to 1 |
| 1 | 1 | Already set |

Result:

`1010` → `1011`

**Output:** `11`

## Complexity Analysis

- **Time Complexity:** `O(log n)` – In the worst case, we traverse all consecutive set bits from the right.
- **Space Complexity:** `O(1)` – No extra space is used.

## Key Takeaway

- `n & (1 << i)` checks whether the bit at position `i` is set.
- `n | (1 << i)` sets the bit at position `i` to `1` without changing other bits.
- Always be careful with operator precedence when combining bitwise and comparison operators.

**Pattern to Remember:** Bit Manipulation – Finding and setting the rightmost unset bit.
