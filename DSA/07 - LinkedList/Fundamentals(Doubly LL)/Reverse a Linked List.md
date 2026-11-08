# Reverse Linked List (SLL)

**Problem Link:** https://leetcode.com/problems/reverse-linked-list/

## Problem Statement

Given the head of a singly linked list, reverse the linked list and return the new head.

## Approach: Iterative (Three Pointers)

We use three pointers:
- `curr`: Points to the current node.
- `prev`: Points to the previous node.
- `next`: Temporarily stores the next node to avoid losing the remaining list.

### Algorithm

1. Initialize `curr = head`.
2. Initialize `prev = nullptr` because the original head will become the tail.
3. Traverse the linked list while `curr != nullptr`.
4. Store the next node using `next = curr->next`.
5. Reverse the current node's link using `curr->next = prev`.
6. Move `prev` to the current node.
7. Move `curr` to the previously stored next node.
8. Repeat until all nodes are processed.
9. Return `prev` as the new head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {

            // Store the next node
            ListNode* next = curr->next;

            // Reverse the link
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = next;
        }

        return prev;
    }
};
```

## Example 1

**Input:**
```text
head = [1, 2, 3, 4, 5]
```

**Output:**
```text
[5, 4, 3, 2, 1]
```

**Explanation:**

The original linked list:

```text
1 -> 2 -> 3 -> 4 -> 5 -> nullptr
```

After reversing:

```text
5 -> 4 -> 3 -> 2 -> 1 -> nullptr
```

## Dry Run

Consider the input:

```text
1 -> 2 -> 3 -> nullptr
```

Initially:
```text
prev = nullptr
curr = 1
```

| Iteration | curr | next | prev after update | Reversed link |
|---|---|---|---|---|
| 1 | 1 | 2 | 1 | `1 -> nullptr` |
| 2 | 2 | 3 | 2 | `2 -> 1` |
| 3 | 3 | nullptr | 3 | `3 -> 2` |

Final linked list:

```text
3 -> 2 -> 1 -> nullptr
```

Return `prev`, which points to node `3`.

## Edge Cases

| Input | Output |
|---|---|
| `[]` | `[]` |
| `[1]` | `[1]` |
| `[1, 2]` | `[2, 1]` |
| `[1, 2, 3, 4]` | `[4, 3, 2, 1]` |

## Complexity Analysis

- **Time Complexity:** `O(N)` – Every node is visited exactly once.
- **Space Complexity:** `O(1)` – Only three pointers are used. No additional data structure is required.

## Key Takeaway

The main idea is to reverse the direction of each node's `next` pointer.

Remember these four operations:

```cpp
ListNode* next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
```

**Why do we need the `next` pointer?**

Before reversing the current node's link, we must save its next node. Otherwise, the remaining linked list becomes inaccessible.

This iterative approach reverses a singly linked list in-place using constant extra space.



# Reverse a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/reverse-a-doubly-linked-list)

## Problem Statement

Given the head of a doubly linked list, reverse the list and return the new head.

A doubly linked list contains two pointers:
- `prev` – Points to the previous node.
- `next` – Points to the next node.

The task is to reverse the links so that the list is traversed in the opposite direction.

## Approach: Two Pointers and Swapping Links

We can reverse a doubly linked list by swapping the `prev` and `next` pointers of every node.

### Algorithm

1. Initialize `curr` with `head`.
2. Initialize `prev` with `nullptr`.
3. Traverse the list while `curr` is not `nullptr`.
4. Store the original `prev` pointer of the current node in `prev`.
5. Swap the `prev` and `next` pointers of the current node.
6. Move to the next node using `curr = curr->prev` because the pointers have been swapped.
7. After the loop, return the new head using `prev ? prev->prev : head`.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {

            // Store the original prev node
            prev = curr->prev;

            // Swap prev and next pointers
            curr->prev = curr->next;
            curr->next = prev;

            // Move forward using the original next pointer
            curr = curr->prev;
        }

        return prev ? prev->prev : head;
    }
};
```

## Example

**Input:**

```text
10 <-> 20 <-> 30 <-> 40
```

**Output:**

```text
40 <-> 30 <-> 20 <-> 10
```

## Dry Run

Consider the linked list:

```text
10 <-> 20 <-> 30
```

| Iteration | Current node | Action |
|---|---|---|
| 1 | 10 | Swap `prev` and `next` |
| 2 | 20 | Swap `prev` and `next` |
| 3 | 30 | Swap `prev` and `next` |

After reversing:

```text
30 <-> 20 <-> 10
```

The new head is `30`.

## Edge Cases

1. **Empty list:** If `head == nullptr`, return `nullptr`.
2. **Single node:** The list remains unchanged.
3. **Multiple nodes:** All `prev` and `next` pointers are swapped.

## Complexity Analysis

- **Time Complexity:** `O(N)` – We traverse every node exactly once.
- **Space Complexity:** `O(1)` – We use only two pointer variables (`curr` and `prev`).

## Key Takeaway

To reverse a doubly linked list, swap the `prev` and `next` pointers of every node.

Since the pointers are swapped, move forward using:

```cpp
curr = curr->prev;
```

This reverses the list in-place without creating any additional nodes.
