# Insert Node Before Tail in a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/insert-node-before-tail-in-dll)

## Problem Statement

Given the head of a doubly linked list and an integer `X`, insert a new node with value `X` immediately before the last node (tail) and return the updated head.

Each node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Traversal and Pointer Manipulation

1. Create a new node with value `X`.
2. Check if the list contains only one node:
   - Set the new node's `next` pointer to the current head.
   - Set the current head's `prev` pointer to the new node.
   - Update head to the new node.
   - Return the updated head.
3. Otherwise, initialize a temporary pointer `temp` with `head`.
4. Traverse the list until `temp->next == nullptr`, which means the tail is reached.
5. Insert the new node before the tail:
   - Set `node->prev = temp->prev`.
   - Set `node->next = temp`.
   - Update `temp->prev->next = node`.
   - Update `temp->prev = node`.
6. Return the original head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* insertBeforeTail(ListNode* head, int X) {

        // Create a new node
        ListNode* node = new ListNode(X);

        // Handle single-node list
        if(head->next == nullptr) {
            node->next = head;
            head->prev = node;
            head = node;
            return head;
        }

        // Traverse to the tail
        ListNode* temp = head;

        while(temp->next) {
            temp = temp->next;
        }

        // Insert the new node before the tail
        temp->prev->next = node;

        node->next = temp;
        node->prev = temp->prev;

        temp->prev = node;

        return head;
    }
};
```

## Example 1

**Input:**

```text
DLL = 10 <-> 20 <-> 30 <-> 40
X = 25
```

**Output:**

```text
10 <-> 20 <-> 30 <-> 25 <-> 40
```

**Explanation:**

- Traverse until the tail (`40`) is reached.
- Create a new node containing `25`.
- Connect `25` between `30` and `40`.
- Update the `next` and `prev` pointers of the adjacent nodes.

## Example 2

**Input:**

```text
DLL = 10
X = 5
```

**Output:**

```text
5 <-> 10
```

**Explanation:**

Since the list contains only one node, the new node becomes the head and the existing node becomes the tail.

## Pointer Visualization

**Before insertion:**

```text
10 <-> 20 <-> 30 <-> 40
```

**After insertion:**

```text
10 <-> 20 <-> 30 <-> 25 <-> 40
```

## Complexity Analysis

- **Time Complexity:** `O(N)` – We traverse the list to reach the tail.
- **Space Complexity:** `O(1)` – Only one new node and a temporary pointer are used.

## Key Takeaway

To insert a node before the tail of a doubly linked list, establish connections between the new node and the tail's previous node.

The important pointer updates are:

```cpp
temp->prev->next = node;

node->prev = temp->prev;
node->next = temp;

temp->prev = node;
```

These four pointer updates maintain the doubly linked list structure.

**Important:** This implementation assumes the list is non-empty. If empty lists are allowed, handle `head == nullptr` separately by returning the new node as the head.
