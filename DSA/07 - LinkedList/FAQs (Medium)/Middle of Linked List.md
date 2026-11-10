# Middle of the Linked List
[Problem Link](https://leetcode.com/problems/middle-of-the-linked-list/submissions/2028495625/)

## Problem Statement

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes (when the number of nodes is even), return the **second middle node**.

### Example 1

**Input:** `1 -> 2 -> 3 -> 4 -> 5`

**Output:** `3 -> 4 -> 5`

**Explanation:** The middle node is `3`.

### Example 2

**Input:** `1 -> 2 -> 3 -> 4 -> 5 -> 6`

**Output:** `4 -> 5 -> 6`

**Explanation:** There are two middle nodes (`3` and `4`). We return the second middle node, `4`.

---

## Approach: Slow and Fast Pointer (Tortoise and Hare)

We use two pointers that move at different speeds.

- **Slow Pointer:** Moves one node at a time.
- **Fast Pointer:** Moves two nodes at a time.

When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle.

### Algorithm

1. Initialize both `slow` and `fast` pointers to `head`.
2. Traverse the linked list while `fast` and `fast->next` are not NULL.
3. Move `slow` one step forward.
4. Move `fast` two steps forward.
5. When the loop terminates, return `slow`.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```

---

## Dry Run

**Input:** `1 -> 2 -> 3 -> 4 -> 5`

| Iteration | Slow | Fast |
|---|---|---|
| Initial | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |

Now `fast->next == NULL`, so the loop terminates.

**Middle Node:** `3`

### Even-Length Example

**Input:** `1 -> 2 -> 3 -> 4 -> 5 -> 6`

| Iteration | Slow | Fast |
|---|---|---|
| Initial | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |
| 3 | 4 | NULL |

**Middle Node:** `4` (second middle).

---

## Complexity Analysis

- **Time Complexity:** O(N) – We traverse approximately half of the linked list using the fast pointer.
- **Auxiliary Space Complexity:** O(1) – We use only two pointers.

## Edge Cases

| Input | Output |
|---|---|
| `1` | `1` |
| `1 -> 2` | `2` |
| `1 -> 2 -> 3` | `2` |
| `1 -> 2 -> 3 -> 4` | `3` |
| `1 -> 2 -> 3 -> 4 -> 5` | `3` |

## Key Takeaways

- The slow and fast pointer technique is also called the **Tortoise and Hare Algorithm**.
- It helps find the middle node in a single traversal.
- The condition `fast && fast->next` prevents accessing a NULL pointer.
- Initializing both pointers at `head` ensures that the second middle node is returned for even-length linked lists.

**Pattern:** Two Pointers – Slow and Fast Pointer Technique
