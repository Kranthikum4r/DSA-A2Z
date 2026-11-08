# Delete Tail of a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/delete-tail-of-dll)

## Problem Statement

Given the head of a doubly linked list, delete the last node (tail) of the list and return the updated head.

A doubly linked list consists of nodes containing:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Traversal

1. Check if the list is empty. If `head == nullptr`, return `nullptr`.
2. Check if the list contains only one node. If `head->next == nullptr`, delete the node and return `nullptr`.
3. Create a temporary pointer `temp` and initialize it with `head`.
4. Traverse the list until `temp->next == nullptr`.
5. Once the tail is reached:
   - Set `temp->prev->next = nullptr` to disconnect the last node.
   - Delete the tail node using `delete temp`.
6. Return the original head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteTail(ListNode*& head) {

        // Handle empty list
        if(head == nullptr) return nullptr;

        // Handle single-node list
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return nullptr;
        }

        // Traverse to the tail
        ListNode* temp = head;

        while(temp->next) {
            temp = temp->next;
        }

        // Disconnect the tail
        temp->prev->next = nullptr;

        // Delete the last node
        delete temp;

        return head;
    }
};
```

## Example

**Input:**
```text
DLL = 10 <-> 20 <-> 30 <-> 40
```

**Output:**
```text
10 <-> 20 <-> 30
```

**Explanation:**

- Traverse the list until the last node (`40`).
- Update the previous node's `next` pointer to `nullptr`.
- Delete the last node (`40`).
- Return the updated head.

## Edge Cases

| Case | Input | Output |
|---|---|---|
| Empty list | `nullptr` | `nullptr` |
| Single node | `10` | `nullptr` |
| Two nodes | `10 <-> 20` | `10` |
| Multiple nodes | `10 <-> 20 <-> 30` | `10 <-> 20` |

## Complexity Analysis

- **Time Complexity:** `O(N)` – We traverse the list to reach the last node.
- **Space Complexity:** `O(1)` – We use only one temporary pointer.

## Key Takeaway

In a doubly linked list, the `prev` pointer makes it easy to access the previous node of the tail.

To delete the tail, update:

```cpp
temp->prev->next = nullptr;
```

Then free the memory:

```cpp
delete temp;
```
