# Insert Node Before Head in a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/insert-node-before-head-in-dll)

## Problem Statement

Given the head of a doubly linked list and an integer `X`, insert a new node with value `X` before the current head and return the updated head.

Each node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Pointer Manipulation

1. Create a new node with value `X`.
2. Set its `prev` pointer to `nullptr` because it will become the first node.
3. Set its `next` pointer to the current head.
4. If the current head exists, update its `prev` pointer to point to the new node.
5. Update the head to the newly created node.
6. Return the updated head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {

        // Create a new node
        ListNode* node = new ListNode(X, nullptr, head);

        // Update the previous pointer of the old head
        if(head != nullptr)
            head->prev = node;

        // Update head
        head = node;

        return head;
    }
};
```

## Example 1

**Input:**

```text
DLL = 10 <-> 20 <-> 30
X = 5
```

**Output:**

```text
5 <-> 10 <-> 20 <-> 30
```

**Explanation:**

- Create a new node containing `5`.
- Set `5->next` to the current head (`10`).
- Set `10->prev` to the new node (`5`).
- Update head to point to node `5`.

## Pointer Visualization

**Before insertion:**

```text
nullptr <- 10 <-> 20 <-> 30
           ^
          head
```

**After insertion:**

```text
nullptr <- 5 <-> 10 <-> 20 <-> 30
           ^
          head
```

## Edge Cases

| Case | Expected Behavior |
|---|---|
| Empty list | New node becomes the head |
| Single-node list | New node is inserted before the existing node |
| Multiple-node list | New node becomes the new head |

## Complexity Analysis

- **Time Complexity:** `O(1)` – Only a constant number of pointer operations are performed.
- **Space Complexity:** `O(1)` – Only one new node is created.

## Key Takeaway

Inserting before the head of a doubly linked list requires updating only two pointers:

```cpp
node->next = head;
head->prev = node;
```

Finally, update the head:

```cpp
head = node;
```

**Important:** Always check whether `head != nullptr` before accessing `head->prev`. This handles the empty-list case safely.
