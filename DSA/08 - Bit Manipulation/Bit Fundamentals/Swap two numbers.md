# Swap Two Numbers
[Problem Link](https://takeuforward.org/practice/dsa/swap-two-numbers)

**Topic:** Bit Manipulation  
**Approach:** XOR (Bitwise Exclusive OR)

## Approach

We can swap two numbers without using a temporary variable by applying the XOR (`^`) operation.

The XOR operation follows these properties:

- `a ^ a = 0`
- `a ^ 0 = a`
- `a ^ b = b ^ a` (Commutative property)

Using these properties, we can swap two numbers in three steps:

1. `a = a ^ b` – Stores the XOR of both numbers in `a`.
2. `b = a ^ b` – Recovers the original value of `a` into `b`.
3. `a = a ^ b` – Recovers the original value of `b` into `a`.

## C++ Solution

```cpp
class Solution {
public:
    void swap(int &a, int &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};
```

## Example Dry Run

**Input:**
```cpp
a = 5, b = 7
```

Binary representation:

- `a = 0101`
- `b = 0111`

| Step | Operation | a | b |
|---|---|---|---|
| Initial | — | 0101 (5) | 0111 (7) |
| 1 | `a = a ^ b` | 0010 (2) | 0111 (7) |
| 2 | `b = a ^ b` | 0010 (2) | 0101 (5) |
| 3 | `a = a ^ b` | 0111 (7) | 0101 (5) |

**Output:**
```cpp
a = 7, b = 5
```

## Complexity Analysis

- **Time Complexity:** `O(1)` – Only three XOR operations are performed.
- **Space Complexity:** `O(1)` – No additional variable is used.

## Important Note

- XOR swapping works for distinct variables.
- If `a` and `b` refer to the same memory location, the operations will make the value `0`.
- In production C++ code, using `std::swap(a, b)` is generally preferable for readability and safety.

## Key Takeaway

XOR allows us to swap two numbers without using a temporary variable by exploiting the property that `x ^ x = 0`.

**Pattern to Remember:** Bit Manipulation – XOR properties and swapping without a temporary variable.
