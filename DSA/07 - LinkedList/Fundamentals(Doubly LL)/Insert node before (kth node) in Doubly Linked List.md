# Insert Node Before Kth Position in a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/insert-node-before-kth-node-in-dll)

## Problem Statement

Given the head of a doubly linked list and two integers `X` and `K`, insert a new node with value `X` before the Kth node of the linked list and return the updated head.

The position `K` follows 1-based indexing.

Each node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Traversal and Pointer Manipulation

1. Create a new node with value `X`.
2. If `K == 1`:
   - Set the new node's `next` pointer to the current head.
   - Set the current head's `prev` pointer to the new node.
   - Update head to the new node.
   - Return the updated head.
3. Otherwise, initialize a temporary pointer `temp` with `head` and a counter `len = 1`.
4. Traverse the list until the Kth node is reached.
5. When `len == K`:
   - Set `node->prev = temp->prev`.
   - Set `node->next = temp`.
   - Update the previous node's `next` pointer to the new node.
   - Update the Kth node's `prev` pointer to the new node.
6. Return the original head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {

        // Create a new node
        ListNode* node = new ListNode(X);

        // Insert before head
        if(K == 1) {
            node->next = head;
            head->prev = node;
            head = node;
            return head;
        }

        // Traverse to the Kth node
        ListNode* temp = head;
        int len = 1;

        while(temp) {

            if(len == K) {

                // Establish connections
                node->prev = temp->prev;
                node->next = temp;

                // Update adjacent nodes
                temp->prev->next = node;
                temp->prev = node;

                return head;
            }

            temp = temp->next;
            len++;
        }

        return head;
    }
};
```

## Example 1

**Input:**
```text
DLL = 1 <-> 3 <-> 5
X = 7
K = 2
```

**Output:**
```text
1 <-> 7 <-> 3 <-> 5
```

**Explanation:**

- Traverse to the second node (`3`).
- Set the new node's `prev` to `1`.
- Set the new node's `next` to `3`.
- Update `1->next` to point to `7`.
- Update `3->prev` to point to `7`.

## Example 2

**Input:**
```text
DLL = 4 <-> 5
X = 10
K = 2
```

**Output:**
```text
4 <-> 10 <-> 5
```

## Pointer Visualization

**Before insertion:**
```text
nullptr <- 4 <-> 5 -> nullptr
```

**After insertion:**
```text
nullptr <- 4 <-> 10 <-> 5 -> nullptr
```

## Complexity Analysis

- **Time Complexity:** `O(K)` – We traverse the list to reach the Kth node.
- **Space Complexity:** `O(1)` – Only one new node and a temporary pointer are used.

## Key Takeaway

To insert a node before the Kth node in a doubly linked list, update four pointers:

```cpp
node->prev = temp->prev;
node->next = temp;

temp->prev->next = node;
temp->prev = node;
```

The important idea is to connect the new node to both neighboring nodes while maintaining the `prev` and `next` relationships.

**Note:** This implementation assumes a non-empty list and a valid position `1 <= K <= N`. For a completely robust implementation, handle `head == nullptr` before accessing `head->prev` in the `K == 1` case.
