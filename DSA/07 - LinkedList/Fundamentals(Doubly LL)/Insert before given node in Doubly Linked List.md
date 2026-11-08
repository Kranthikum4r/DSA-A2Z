# Insert Before Given Node in Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/insert-before-given-node-in-dll)

## Problem Statement

Given a reference to a node in a doubly linked list and an integer `X`, insert a new node with value `X` before the given node.

The head of the linked list is not provided. It is guaranteed that the given node is not the head of the list.

Each node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Pointer Manipulation

Since the given node is directly provided and is guaranteed not to be the head, we can insert a new node before it without traversing the list.

1. Create a new node with value `X`.
2. Set the new node's `prev` pointer to `node->prev`.
3. Set the new node's `next` pointer to the given node.
4. Update the previous node's `next` pointer to the new node.
5. Update the given node's `prev` pointer to the new node.

## C++ Solution

```cpp
class Solution {
public:
    void insertBeforeGivenNode(ListNode* node, int X) {

        // Create a new node
        ListNode* newNode = new ListNode(X);

        // Establish connections
        newNode->prev = node->prev;
        newNode->next = node;

        // Update adjacent nodes
        node->prev->next = newNode;
        node->prev = newNode;
    }
};
```

## Example 1

**Input:**

```text
DLL = 1 <-> 2 <-> 6
Given node = 6
X = 7
```

**Output:**

```text
1 <-> 2 <-> 7 <-> 6
```

**Explanation:**

- The given node is `6`.
- Its previous node is `2`.
- Create a new node containing `7`.
- Connect `7` between `2` and `6`.
- Update the `next` and `prev` pointers accordingly.

## Example 2

**Input:**

```text
DLL = 7 <-> 6 <-> 5
Given node = 5
X = 10
```

**Output:**

```text
7 <-> 6 <-> 10 <-> 5
```

## Pointer Visualization

**Before insertion:**

```text
7 <-> 6 <-> 5
             ^
         Given node
```

**After insertion:**

```text
7 <-> 6 <-> 10 <-> 5
```

## Important Pointer Updates

The following four statements establish the connections:

```cpp
newNode->prev = node->prev;
newNode->next = node;

node->prev->next = newNode;
node->prev = newNode;
```

**Pointer relationship:**

- `newNode->prev` points to the previous node.
- `newNode->next` points to the given node.
- Previous node's `next` points to the new node.
- Given node's `prev` points to the new node.

## Complexity Analysis

- **Time Complexity:** `O(1)` – No traversal is required because the given node is directly available.
- **Space Complexity:** `O(1)` – Only one new node is created.

## Key Takeaway

When a node reference is directly provided in a doubly linked list, insertion before that node can be performed in constant time.

Unlike insertion at a particular position, there is no need to traverse the list.

**Important:** This implementation assumes the given node is valid and is not the head, as guaranteed by the problem constraints.
