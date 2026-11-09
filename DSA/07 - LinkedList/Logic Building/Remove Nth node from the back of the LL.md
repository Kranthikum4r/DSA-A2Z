# Remove Nth Node From End of List
[Problem Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

## Problem Statement

Given the head of a singly linked list, remove the `n`th node from the end of the list and return the modified linked list.

## Approach: Dummy Node + Slow and Fast Pointers

We use a **Dummy Node** along with two pointers (`slow` and `fast`) to remove the target node in a single traversal.

The dummy node is added before the head to handle all deletion cases, including deleting the first node.

### Algorithm

1. Create a dummy node with value `0` and connect it to the original head.
2. Initialize two pointers:
   - `slow = dummy`
   - `fast = dummy`
3. Move the `fast` pointer `n + 1` positions ahead.
   - This maintains a gap of `n + 1` nodes between `slow` and `fast`.
4. Move both pointers one step at a time until `fast` becomes `NULL`.
5. Now, `slow` points to the node just before the node that needs to be deleted.
6. Store the target node:
   - `del = slow->next`
7. Update the connection:
   - `slow->next = del->next`
8. Delete the target node using `delete del`.
9. Return `dummy->next`, which points to the new head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node
        ListNode* dummy = new ListNode(0, head);

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n + 1 positions ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast becomes NULL
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy->next;
    }
};
```

## Example Dry Run

**Input:**

`head = [1, 2, 3, 4, 5], n = 2`

We need to delete the 2nd node from the end (node `4`).

### Step 1: Initialize pointers

- `dummy = 0`
- `slow = dummy`
- `fast = dummy`

Initial list:

`0 → 1 → 2 → 3 → 4 → 5 → NULL`

### Step 2: Move fast pointer n + 1 = 3 positions

- First move: `fast = 1`
- Second move: `fast = 2`
- Third move: `fast = 3`

Now:

- `slow = 0`
- `fast = 3`

### Step 3: Move both pointers

| Iteration | Slow | Fast |
|---|---|---|
| Initial | 0 | 3 |
| 1 | 1 | 4 |
| 2 | 2 | 5 |
| 3 | 3 | NULL |

Now `slow` points to node `3`, which is immediately before the target node.

### Step 4: Delete the target node

```cpp
ListNode* del = slow->next;
slow->next = del->next;
delete del;
```

Node `4` is removed.

**Output:**

`[1, 2, 3, 5]`

## Why Do We Move Fast by n + 1 Positions?

We need the `slow` pointer to stop at the node immediately before the target node.

By moving `fast` `n + 1` positions ahead, we maintain the required gap.

When `fast` reaches `NULL`, `slow` automatically reaches the previous node of the target.

The dummy node ensures that even when the original head needs to be deleted, `slow` has a valid previous node.

## Complexity Analysis

Let `N` be the number of nodes in the linked list.

- **Time Complexity:** `O(N)` – Both pointers traverse the linked list at most once.
- **Space Complexity:** `O(1)` – Only a constant number of pointers and one dummy node are used.

## Important Edge Cases

1. Single node: `[1], n = 1` → `[]`
2. Delete the last node: `[1, 2, 3], n = 1` → `[1, 2]`
3. Delete the first node: `[1, 2, 3], n = 3` → `[2, 3]`
4. Delete a middle node: `[1, 2, 3, 4, 5], n = 2` → `[1, 2, 3, 5]`

## Key Concepts Learned

- Dummy Node technique.
- Slow and Fast Pointer technique.
- Two-pointer gap approach.
- Deleting nodes from a singly linked list.
- Handling head deletion without special conditions.
- Dynamic memory management using `delete`.

## Key Takeaway

The Dummy Node technique eliminates the need for a separate condition to handle head deletion.

Moving the fast pointer `n + 1` positions ahead ensures that when it reaches `NULL`, the slow pointer is exactly at the node before the target.

This provides a clean **single-pass solution with O(N) time and O(1) auxiliary space**.
