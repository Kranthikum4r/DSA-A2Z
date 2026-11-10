# Palindrome Linked List
[Problem Link](https://leetcode.com/problems/palindrome-linked-list/description/)

## Problem Statement

Given the head of a singly linked list, determine whether the linked list is a palindrome.

A linked list is a palindrome if it reads the same forward and backward.

### Example 1

**Input:** `1 -> 2 -> 2 -> 1`

**Output:** `true`

**Explanation:** The linked list reads the same in both directions.

### Example 2

**Input:** `1 -> 2 -> 3`

**Output:** `false`

**Explanation:** The linked list is not the same when reversed.

### Example 3

**Input:** `1 -> 2 -> 1`

**Output:** `true`

---

## Approach: Slow & Fast Pointer + Reverse Second Half

We use three important linked-list techniques:

1. Slow and Fast Pointers to find the middle.
2. Reverse the second half of the linked list.
3. Compare the first half with the reversed second half.

### Algorithm

**Step 1: Handle the base case**

If the linked list is empty or contains only one node, it is a palindrome.

**Step 2: Find the middle**

Initialize both `slow` and `fast` to `head`.

- `slow` moves one step.
- `fast` moves two steps.

Use the condition:

```cpp
while(fast->next && fast->next->next)
```

This ensures that `slow` points to the first middle for even-length lists and the actual middle for odd-length lists.

**Step 3: Reverse the second half**

Reverse the linked list starting from `slow->next`.

**Step 4: Compare both halves**

- Initialize `first = head`.
- Initialize `second = secHead`.
- Compare the values while `second` is not NULL.
- If any values differ, return `false`.
- If all values match, return `true`.

---

## C++ Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* secHead = reverseList(slow->next);

        ListNode* first = head;
        ListNode* second = secHead;

        // Compare both halves
        while(second) {
            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
```

---

## Dry Run

**Input:** `1 -> 2 -> 2 -> 1`

### Step 1: Find the middle

After slow and fast pointer traversal:

- `slow` points to the second node (`2`).
- `fast` points to the fourth node (`1`).

### Step 2: Reverse the second half

Original list:

`1 -> 2 -> 2 -> 1`

Second half:

`2 -> 1`

After reversing:

`1 -> 2`

### Step 3: Compare both halves

| First Half | Second Half | Result |
|---|---|---|
| 1 | 1 | Match |
| 2 | 2 | Match |

Both halves match.

**Final Output:** `true`

---

## Complexity Analysis

- **Time Complexity:** O(N)
  - Finding the middle takes O(N).
  - Reversing the second half takes O(N).
  - Comparing both halves takes O(N).

- **Auxiliary Space Complexity:** O(1)
  - Only a constant number of pointers are used.
  - No additional data structures are required.

---

## Edge Cases

| Input | Output |
|---|---|
| `1` | `true` |
| `1 -> 2` | `false` |
| `1 -> 2 -> 1` | `true` |
| `1 -> 2 -> 2 -> 1` | `true` |
| `1 -> 2 -> 3 -> 4` | `false` |
| `1 -> 2 -> 3 -> 2 -> 1` | `true` |

---

## Key Takeaways

- Slow and Fast Pointers help find the middle in one traversal.
- Reversing the second half allows comparison without using extra space.
- For odd-length lists, the middle node is automatically excluded from comparison.
- Comparing only the second half is sufficient because both halves have equal lengths (or the first half has one extra node).

**Important Note:** This implementation modifies the original linked list because it reverses the second half. If the original list must be preserved, reverse the second half again before returning.

**Pattern:** Linked List – Slow & Fast Pointers + Reversal + Two-Pointer Comparison
