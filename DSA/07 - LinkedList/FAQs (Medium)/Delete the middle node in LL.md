# Delete the Middle Node in a Linked List
[Problem Link](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

## Problem Statement

Given the head of a singly linked list, delete the middle node and return the head of the modified linked list.

- If the number of nodes is odd, delete the exact middle node.
- If the number of nodes is even, delete the second middle node.

### Example 1

**Input:** `1 -> 2 -> 3 -> 4 -> 5`

**Output:** `1 -> 2 -> 4 -> 5`

**Explanation:** The middle node `3` is deleted.

### Example 2

**Input:** `1 -> 2 -> 3 -> 4 -> 5 -> 6`

**Output:** `1 -> 2 -> 3 -> 5 -> 6`

**Explanation:** The second middle node `4` is deleted.

### Example 3

**Input:** `1`

**Output:** `NULL`

**Explanation:** Since there is only one node, deleting the middle node results in an empty linked list.

---

## Approach: Slow and Fast Pointer

We use the **Slow and Fast Pointer (Tortoise and Hare)** technique to find the middle node.

- `slow`: Moves one node at a time.
- `fast`: Moves two nodes at a time.
- `prev`: Stores the node immediately before `slow`.

Once the fast pointer reaches the end, the slow pointer will point to the middle node.

We then delete the middle node by connecting `prev` to `slow->next`.

### Algorithm

1. If the linked list contains only one node, return `NULL`.
2. Initialize `slow` and `fast` to `head`.
3. Initialize `prev` to `NULL`.
4. Traverse while `fast` and `fast->next` are not NULL:
   - Set `prev = slow`.
   - Move `slow` one step forward.
   - Move `fast` two steps forward.
5. Once the loop terminates, `slow` points to the middle node.
6. Delete the middle node by updating `prev->next = slow->next`.
7. Return `head`.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};
```

---

## Dry Run

**Input:** `1 -> 2 -> 3 -> 4 -> 5`

| Iteration | Prev | Slow | Fast |
|---|---|---|---|
| Initial | NULL | 1 | 1 |
| 1 | 1 | 2 | 3 |
| 2 | 2 | 3 | 5 |

Now `fast->next == NULL`, so the loop terminates.

- `slow` points to node `3`.
- `prev` points to node `2`.

Delete the middle node:

```cpp
prev->next = slow->next;
```

The connection becomes:

`2 -> 4`

**Final Output:** `1 -> 2 -> 4 -> 5`

---

## Complexity Analysis

- **Time Complexity:** O(N) – We traverse the linked list once.
- **Auxiliary Space Complexity:** O(1) – Only three pointers are used.

## Edge Cases

| Input | Output |
|---|---|
| `1` | `NULL` |
| `1 -> 2` | `1` |
| `1 -> 2 -> 3` | `1 -> 3` |
| `1 -> 2 -> 3 -> 4` | `1 -> 2 -> 4` |
| `1 -> 2 -> 3 -> 4 -> 5` | `1 -> 2 -> 4 -> 5` |

## Key Takeaways

- The slow and fast pointer technique finds the middle node in one traversal.
- Maintaining a `prev` pointer helps access the node before the middle.
- `prev->next = slow->next` removes the middle node from the linked list.
- Always handle the single-node linked list separately.
- Deleting the removed node using `delete slow` releases its dynamically allocated memory.

**Pattern:** Linked List – Slow and Fast Pointers + Node Deletion
