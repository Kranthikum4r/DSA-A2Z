# Delete Head of a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/delete-head-of-dll?tab=problem)

## Problem Statement

Given the head of a doubly linked list, delete the first node (head) and return the updated head.

Each node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Pointer Manipulation

1. Check whether the list is empty. If `head == nullptr`, return `nullptr`.
2. If the list contains only one node:
   - Delete the head node.
   - Set `head = nullptr`.
   - Return `nullptr`.
3. Create a temporary pointer `temp` and initialize it with `head`.
4. Move the head to the next node using `head = head->next`.
5. Set the new head's `prev` pointer to `nullptr`.
6. Delete the original head using `delete temp`.
7. Return the updated head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteHead(ListNode*& head) {

        // Handle empty list
        if(head == nullptr) return nullptr;

        // Store the original head
        ListNode* temp = head;

        // Move head to the next node
        head = head->next;

        // Update the new head's prev pointer
        if(head != nullptr)
            head->prev = nullptr;

        // Delete the original head
        delete temp;

        return head;
    }
};
```

## Example 1

**Input:**

```text
DLL = 10 <-> 20 <-> 30 <-> 40
```

**Output:**

```text
20 <-> 30 <-> 40
```

**Explanation:**

- Store the original head (`10`) in `temp`.
- Move head to the next node (`20`).
- Set `20->prev = nullptr`.
- Delete the original head (`10`).

## Example 2

**Input:**

```text
DLL = 10
```

**Output:**

```text
nullptr
```

**Explanation:**

Since the list contains only one node, deleting the head makes the list empty.

## Pointer Visualization

**Before deletion:**

```text
nullptr <- 10 <-> 20 <-> 30
           ^
          head
```

**After deletion:**

```text
nullptr <- 20 <-> 30
           ^
          head
```

## Edge Cases

| Case | Expected Output |
|---|---|
| Empty list | `nullptr` |
| Single-node list | `nullptr` |
| Two-node list | Second node becomes head |
| Multiple-node list | Second node becomes head |

## Complexity Analysis

- **Time Complexity:** `O(1)` – Only a constant number of pointer operations are performed.
- **Space Complexity:** `O(1)` – Only one temporary pointer is used.

## Key Takeaway

To delete the head of a doubly linked list, update the head pointer and disconnect the previous pointer of the new head.

Important pointer operations:

```cpp
head = head->next;

if(head != nullptr)
    head->prev = nullptr;

delete temp;
```

Always handle the empty-list case and check whether the new head exists before accessing its `prev` pointer.
