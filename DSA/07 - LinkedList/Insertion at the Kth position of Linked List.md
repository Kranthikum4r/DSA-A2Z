# 954. Insertion at the Kth Position of Linked List

## Problem Statement
Given the head of a singly linked list and two integers `X` and `K`, insert a new node with value `X` at the Kth position (1-based indexing) and return the modified head.

## Approach: Iterative Traversal

1. Create a new node with value `X`.
2. If `K == 1`, insert the new node at the beginning:
   - Point the new node's `next` to the current head.
   - Update the head to the new node.
3. Otherwise, traverse the linked list to reach the `(K-1)th` node.
4. Insert the new node after the `(K-1)th` node:
   - `node->next = temp->next`
   - `temp->next = node`
5. Return the updated head.

## C++ Code

```cpp
class Solution {
public:
    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {

        ListNode* node = new ListNode(X);

        // Insertion at the beginning
        if(K == 1) {
            node->next = head;
            head = node;
            return head;
        }

        int len = 1;
        ListNode* temp = head;

        // Traverse to the (K-1)th node
        while(temp) {
            if(len == K - 1) {
                node->next = temp->next;
                temp->next = node;
                return head;
            }

            temp = temp->next;
            len++;
        }

        return head;
    }
};
```

## Dry Run

**Input:**
```text
Linked List = 1 -> 2 -> NULL
X = 15
K = 3
```

**Step 1:** Create a new node with value `15`.

**Step 2:** Since `K != 1`, start traversal.

**Step 3:** Reach the `(K-1)th` node (position 2), which contains `2`.

**Step 4:** Perform insertion:

```cpp
node->next = temp->next;
temp->next = node;
```

**Output:**
```text
1 -> 2 -> 15 -> NULL
```

## Edge Cases

| Case | Expected Output |
|---|---|
| Empty list, K = 1 | `[X]` |
| Insertion at beginning | `[X, 1, 2, 3]` |
| Insertion in middle | `[1, X, 2, 3]` |
| Insertion at end | `[1, 2, X]` |

## Complexity Analysis

- **Time Complexity:** `O(n)` – In the worst case, we traverse the entire linked list.
- **Space Complexity:** `O(1)` – Only a constant amount of extra pointer space is used (excluding the newly allocated node).

## Key Takeaways

- Linked list positions are 1-indexed in this problem.
- To insert at position `K`, reach the `(K-1)th` node.
- Handle insertion at the head separately because the head pointer changes.
- Update pointers in the correct order to avoid losing the remaining linked list.

**Important:** The insertion position is based on the original linked list, and `K = n + 1` represents insertion at the end.
