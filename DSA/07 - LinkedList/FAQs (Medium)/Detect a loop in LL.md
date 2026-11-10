# Detect a Loop in a Linked List
[Problem Link](https://leetcode.com/problems/linked-list-cycle/)

## Problem Statement

Given the head of a singly linked list, determine whether the linked list contains a cycle (loop).

A cycle exists when a node's `next` pointer points back to a previously visited node, creating an infinite traversal.

Return:
- `true` if a cycle exists.
- `false` if no cycle exists.

### Example 1

**Input:** `1 -> 2 -> 3 -> 4 -> 2 ...`

**Output:** `true`

**Explanation:** The last node points back to the node containing `2`, forming a cycle.

### Example 2

**Input:** `1 -> 2 -> 3 -> 4 -> NULL`

**Output:** `false`

**Explanation:** The linked list terminates at NULL, so there is no cycle.

---

## Approach: Floyd's Cycle Detection Algorithm

We use the **Slow and Fast Pointer (Tortoise and Hare)** technique.

- **Slow Pointer:** Moves one node at a time.
- **Fast Pointer:** Moves two nodes at a time.

### Algorithm

1. Initialize both `slow` and `fast` pointers to `head`.
2. Traverse the linked list while `fast` and `fast->next` are not NULL.
3. Move `slow` one step forward.
4. Move `fast` two steps forward.
5. Check whether both pointers point to the same node.
   - If `slow == fast`, a cycle exists. Return `true`.
6. If the fast pointer reaches NULL, no cycle exists. Return `false`.

### Why Does It Work?

If a cycle exists, the fast pointer moves faster than the slow pointer and eventually catches up with it inside the cycle.

If no cycle exists, the fast pointer eventually reaches the end of the linked list (`NULL`).

---

## C++ Solution

```cpp
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};
```

---

## Dry Run

**Input:** `1 -> 2 -> 3 -> 4 -> 5`

Assume node `5` points back to node `2`.

Cycle:

`2 -> 3 -> 4 -> 5 -> 2 ...`

| Iteration | Slow | Fast |
|---|---|---|
| Initial | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |
| 3 | 4 | 3 |
| 4 | 5 | 5 |

Both pointers meet at node `5`.

**Final Output:** `true`

---

## Complexity Analysis

- **Time Complexity:** O(N)
  - In the absence of a cycle, the fast pointer reaches NULL.
  - If a cycle exists, the two pointers eventually meet.

- **Auxiliary Space Complexity:** O(1)
  - Only two pointers are used.
  - No additional data structures are required.

---

## Edge Cases

| Linked List | Output |
|---|---|
| `NULL` | `false` |
| `1 -> NULL` | `false` |
| `1 -> 2 -> 3 -> NULL` | `false` |
| `1 -> 1 ...` (self-loop) | `true` |
| `1 -> 2 -> 3 -> 2 ...` | `true` |
| `1 -> 2 -> 3 -> 4 -> 1 ...` | `true` |

---

## Key Takeaways

- Floyd's Cycle Detection Algorithm is also called the Tortoise and Hare Algorithm.
- Slow moves one step while fast moves two steps.
- If both pointers meet, a cycle exists.
- Always check `fast && fast->next` before moving the fast pointer.
- Comparing pointers (`slow == fast`) checks whether they refer to the same node in memory, not whether their values are equal.

**Pattern:** Linked List – Slow and Fast Pointers (Floyd's Cycle Detection)
