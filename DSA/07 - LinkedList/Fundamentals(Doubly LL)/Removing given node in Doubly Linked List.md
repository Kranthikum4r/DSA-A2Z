# Removing Given Node in a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/removing-given-node-in-dll)

## Problem Statement

Given a pointer to a node in a doubly linked list, delete that particular node from the list.

The node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

The task is to remove the given node without traversing the entire linked list.

## Approach: Pointer Manipulation

Since we are directly given the node to delete, there is no need to traverse the list.

1. Check whether the given node has a next node.
2. If `node->next` exists:
   - Update the next node's `prev` pointer to `node->prev`.
3. Update the previous node's `next` pointer to `node->next`.
4. Delete the given node using `delete node`.

## C++ Solution

```cpp
class Solution {
public:
    void deleteGivenNode(ListNode* node) {

        // Update the next node's prev pointer
        if(node->next)
            node->next->prev = node->prev;

        // Update the previous node's next pointer
        node->prev->next = node->next;

        // Delete the given node
        delete node;
    }
};
```

## Example

**Input:**

```text
DLL = 10 <-> 20 <-> 30 <-> 40

Given node = 30
```

**Output:**

```text
10 <-> 20 <-> 40
```

**Explanation:**

- The given node is `30`.
- Update `40->prev` to point to `20`.
- Update `20->next` to point to `40`.
- Delete node `30`.

## Pointer Visualization

**Before deletion:**

```text
10 <-> 20 <-> 30 <-> 40
             ^
          Given node
```

**After deletion:**

```text
10 <-> 20 <-> 40
```

## Complexity Analysis

- **Time Complexity:** `O(1)` – No traversal is required because the node is directly provided.
- **Space Complexity:** `O(1)` – Only pointer manipulation is performed.

## Key Takeaway

In a doubly linked list, we can delete a given node in constant time when its pointer is already available.

The important pointer updates are:

```cpp
node->next->prev = node->prev;
node->prev->next = node->next;
```

Unlike deleting a node by position or value, this operation does not require traversal.

**Important:** This implementation assumes the given node is neither `nullptr` nor the head node. The head node cannot be deleted correctly using this function alone because there is no head pointer reference to update.
