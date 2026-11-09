# Odd Even Linked List
[Problem Link](https://leetcode.com/problems/odd-even-linked-list/description/)

## Problem Statement

Given the head of a singly linked list, group all nodes at **odd indices together**, followed by the nodes at even indices, and return the reordered list.

- The first node is considered to have index 1 (odd).
- The second node is considered to have index 2 (even).
- The relative order within the odd and even groups must be maintained.

**Note:** We group nodes based on their positions, not their values.

## Approach: Two Pointers

We use two pointers to separate the linked list into odd-indexed and even-indexed nodes.

### Algorithm

1. If the list is empty or contains only one node, return `head`.
2. Initialize three pointers:
   - `odd = head` – Points to the first odd-indexed node.
   - `even = head->next` – Points to the first even-indexed node.
   - `evenHead = even` – Stores the starting point of the even-indexed list.
3. Traverse the list while `even` and `even->next` exist.
4. Connect the current odd node to the next odd node:
   - `odd->next = even->next`
   - Move `odd` forward.
5. Connect the current even node to the next even node:
   - `even->next = odd->next`
   - Move `even` forward.
6. After the traversal, connect the last odd node to the beginning of the even list:
   - `odd->next = evenHead`
7. Return the original `head`.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
```

## Example Dry Run

**Input:**

`head = [1, 2, 3, 4, 5]`

Initially:

- `odd = 1`
- `even = 2`
- `evenHead = 2`

**Iteration 1:**

- Connect `1` to `3`.
- Move `odd` to `3`.
- Connect `2` to `4`.
- Move `even` to `4`.

Odd list: `1 → 3`

Even list: `2 → 4`

**Iteration 2:**

- Connect `3` to `5`.
- Move `odd` to `5`.
- Connect `4` to `NULL`.
- Move `even` to `NULL`.

Odd list: `1 → 3 → 5`

Even list: `2 → 4`

**Final Connection:**

Connect the last odd node (`5`) to `evenHead` (`2`).

**Output:**

`[1, 3, 5, 2, 4]`

## Complexity Analysis

Let `N` be the number of nodes in the linked list.

- **Time Complexity:** `O(N)` – Every node is visited at most once.
- **Space Complexity:** `O(1)` – Only a constant number of pointers are used. No additional linked list or array is created.

## Important Edge Cases

1. Empty linked list: `[]`
2. Single node: `[1]`
3. Two nodes: `[1, 2]`
4. Odd number of nodes: `[1, 2, 3, 4, 5]`
5. Even number of nodes: `[1, 2, 3, 4, 5, 6]`

## Key Concepts Learned

- Two-pointer technique.
- In-place linked list rearrangement.
- Maintaining relative order of nodes.
- Separating odd and even indexed nodes.
- Connecting two linked list sections.
- Handling NULL pointers safely.

## Key Takeaway

The important idea is to maintain two separate sequences using `odd` and `even` pointers.

The `evenHead` pointer preserves the starting position of the even-indexed list. Once traversal is complete, connect the last odd node to `evenHead`.

This solution rearranges the original linked list without creating any additional nodes.
