# Intersection of Two Linked Lists
[Problem Link](https://leetcode.com/problems/intersection-of-two-linked-lists/)

## Problem Statement

Given the heads of two singly linked lists, return the node at which the two linked lists intersect.

If the two linked lists do not intersect, return `NULL`.

**Important:** The intersection is based on the node's memory address, not its value. Two nodes with the same value are not necessarily the same node.

### Example 1

**Input:**

List A: `4 -> 1 -> 8 -> 4 -> 5`

List B: `5 -> 6 -> 1 -> 8 -> 4 -> 5`

**Output:** Intersection node with value `8`.

### Example 2

**Input:**

List A: `1 -> 2 -> 3`

List B: `4 -> 5`

**Output:** `NULL`

---

## Approach: Two Pointers (Pointer Switching)

We use two pointers, `d1` and `d2`, to traverse both linked lists.

The main idea is to eliminate the difference in lengths between the two lists by switching their starting heads.

### Algorithm

1. Initialize two pointers:
   - `d1 = headA`
   - `d2 = headB`
2. Traverse both linked lists simultaneously.
3. When `d1` reaches the end of List A, redirect it to `headB`.
4. When `d2` reaches the end of List B, redirect it to `headA`.
5. Continue until both pointers meet.
6. Return the meeting node.

If there is no intersection, both pointers eventually become `NULL` at the same time.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;

        while(d1 != d2) {
            d1 = d1 == NULL ? headB : d1->next;
            d2 = d2 == NULL ? headA : d2->next;
        }

        return d1;
    }
};
```

---

## Dry Run

Consider:

List A: `4 -> 1 -> 8 -> 4 -> 5`

List B: `5 -> 6 -> 1 -> 8 -> 4 -> 5`

Both lists intersect at node `8`.

| Iteration | d1 | d2 |
|---|---|---|
| Initial | 4 | 5 |
| 1 | 1 | 6 |
| 2 | 8 | 1 |
| 3 | 4 | 8 |
| 4 | 5 | 4 |
| 5 | 5 (List B) | 5 |
| 6 | 6 | NULL |
| 7 | 1 | 4 (List A) |
| 8 | 8 | 1 |
| 9 | 4 | 8 |
| 10 | 5 | 4 |
| 11 | 5 | 5 |

The pointers eventually meet at the same intersection node (same memory address), not merely at a node with the same value.

---

## Why Does Pointer Switching Work?

Suppose:

- Length of List A = `a + c`
- Length of List B = `b + c`

Where:
- `a` = non-intersecting portion of List A.
- `b` = non-intersecting portion of List B.
- `c` = common intersecting portion.

Pointer `d1` travels:

`List A + List B = (a + c) + (b + c)`

Pointer `d2` travels:

`List B + List A = (b + c) + (a + c)`

Both pointers travel the same total distance.

Therefore, they either meet at the intersection node or reach `NULL` together if no intersection exists.

---

## Complexity Analysis

- **Time Complexity:** O(N + M)
  - Each pointer traverses both linked lists at most once.
  - N = Length of List A.
  - M = Length of List B.

- **Auxiliary Space Complexity:** O(1)
  - Only two pointers are used.
  - No additional data structures are required.

---

## Edge Cases

| List A | List B | Result |
|---|---|---|
| `1 -> 2 -> 3` | `4 -> 5` | `NULL` |
| `1 -> 2 -> 3` | `1 -> 2 -> 3` (same nodes) | Node `1` |
| `1 -> 2 -> 3 -> 4` | `5 -> 3 -> 4` | Node `3` |
| `1` | `2` | `NULL` |
| `1 -> 2` | `3 -> 2` | Depends on whether the final nodes are actually shared |

---

## Key Takeaways

- Intersection means two pointers refer to the exact same node in memory.
- Comparing node values is not sufficient.
- Pointer switching balances the difference in linked-list lengths.
- Both pointers traverse the same total distance.
- No need to calculate the lengths of the linked lists separately.

**Pattern:** Linked List – Two Pointers + Pointer Switching
