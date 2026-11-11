# Rotate a Linked List
[Problem Link](https://leetcode.com/problems/rotate-list/)

## Problem Statement

Given the head of a singly linked list and an integer `k`, rotate the linked list to the right by `k` positions and return the new head.

### Example

**Input:**
```text
head = [1, 2, 3, 4, 5], k = 2
```

**Output:**
```text
[4, 5, 1, 2, 3]
```

**Explanation:**

Rotate the linked list to the right by 2 positions. The last two nodes move to the beginning of the list.

---

## Approach: Two Pointers

### Intuition

Instead of rotating the linked list one position at a time, we can efficiently find the new head using two pointers (`slow` and `fast`).

The key observation is:

- The new tail will be at position `n - k`.
- The new head will be at position `n - k + 1`.
- We can use two pointers with a gap of `k` nodes to find these positions.

### Algorithm

1. If the linked list is empty, return `head`.
2. Traverse the linked list to calculate its length `n`.
3. Reduce unnecessary rotations using `k %= n`.
4. If `k == 0`, return the original head.
5. Initialize two pointers, `slow` and `fast`, at the head.
6. Move `fast` exactly `k` steps ahead.
7. Move both pointers until `fast` reaches the last node.
8. Store `slow->next` as the new head.
9. Disconnect the list using `slow->next = NULL`.
10. Connect the original tail to the original head using `fast->next = head`.
11. Return the new head.

---

## C++ Solution

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int n = 0;
        ListNode* temp = head;

        // Calculate the length
        while(temp) {
            temp = temp->next;
            n++;
        }

        // Optimize rotations
        k %= n;

        if(k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast k steps ahead
        int len = 0;
        while(len < k) {
            len++;
            fast = fast->next;
        }

        // Move both pointers
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Change the head
        ListNode* newHead = slow->next;

        // Break and reconnect the list
        slow->next = NULL;
        fast->next = head;

        return newHead;
    }
};
```

---

## Dry Run

**Input:** `head = [1, 2, 3, 4, 5], k = 2`

**Step 1: Calculate length**

```text
n = 5
k = 2
```

**Step 2: Move fast pointer k steps ahead**

```text
slow = 1
fast = 3
```

**Step 3: Move both pointers until fast reaches the last node**

| Iteration | slow | fast |
|---|---|---|
| Initial | 1 | 3 |
| 1 | 2 | 4 |
| 2 | 3 | 5 |

**Step 4: Identify the new head**

```text
newHead = slow->next = 4
```

**Step 5: Break and reconnect**

```cpp
slow->next = NULL;
fast->next = head;
```

Final linked list:

```text
4 -> 5 -> 1 -> 2 -> 3 -> NULL
```

**Output:** `[4, 5, 1, 2, 3]`

---

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N) | Traversing the list to calculate length and locate the new tail. |
| Space Complexity | O(1) | Only a constant number of pointers and variables are used. |

---

## Edge Cases

1. **Empty list:** Return `NULL`.
2. **Single node:** Return the original head.
3. **k = 0:** No rotation is required.
4. **k = n:** The list remains unchanged.
5. **k > n:** Use `k %= n` to eliminate redundant rotations.

---

## Key Takeaways

- Two pointers can efficiently locate the new tail and new head.
- Modulo (`k %= n`) avoids unnecessary rotations.
- Maintain a gap of exactly `k` nodes between `slow` and `fast`.
- Reconnect pointers carefully to avoid losing nodes.
- The solution achieves O(N) time and O(1) auxiliary space.

**Pattern:** Linked List + Two Pointers
