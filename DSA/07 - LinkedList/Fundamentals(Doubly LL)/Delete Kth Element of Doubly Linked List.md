# Delete Kth Element of a Doubly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/delete-kth-element-of-dll?tab=problem)

## Problem Statement

Given the head of a doubly linked list and an integer `k`, delete the kth node from the list (1-based indexing) and return the updated head.

Each node contains:
- `data`: Stores the value of the node.
- `prev`: Points to the previous node.
- `next`: Points to the next node.

## Approach: Traversal

1. Check whether the list is empty. If `head == nullptr`, return `nullptr`.
2. If `k == 1`:
   - Store the current head in a temporary pointer.
   - Move the head to the next node.
   - If the new head exists, set its `prev` pointer to `nullptr`.
   - Delete the original head.
   - Return the updated head.
3. For other positions:
   - Initialize `temp = head` and `len = 1`.
   - Traverse the list until the kth node is reached.
4. Once the kth node is found:
   - If the next node exists, update its `prev` pointer to `temp->prev`.
   - Update the previous node's `next` pointer to `temp->next`.
   - Delete the kth node.
5. Return the updated head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteKthElement(ListNode*& head, int k) {

        // Handle empty list or invalid position
        if(head == nullptr || k <= 0) return head;

        // Delete the first node
        if(k == 1) {
            ListNode* temp = head;

            head = head->next;

            if(head != nullptr)
                head->prev = nullptr;

            delete temp;
            return head;
        }

        // Traverse to the kth node
        ListNode* temp = head;
        int len = 1;

        while(temp) {

            if(len == k) {

                // Update the next node's prev pointer
                if(temp->next != nullptr)
                    temp->next->prev = temp->prev;

                // Update the previous node's next pointer
                temp->prev->next = temp->next;

                // Delete the kth node
                delete temp;

                return head;
            }

            temp = temp->next;
            len++;
        }

        // If k is greater than the list length
        return head;
    }
};
```

## Example 1

**Input:**
```text
DLL = 10 <-> 20 <-> 30 <-> 40
k = 2
```

**Output:**
```text
10 <-> 30 <-> 40
```

**Explanation:**

- Traverse to the second node (`20`).
- Update `30->prev` to point to `10`.
- Update `10->next` to point to `30`.
- Delete node `20`.

## Example 2

**Input:**
```text
DLL = 10 <-> 20 <-> 30
k = 1
```

**Output:**
```text
20 <-> 30
```

**Explanation:**

- Since `k = 1`, delete the head node.
- Move the head to the next node (`20`).
- Set `20->prev = nullptr`.

## Edge Cases

| Case | Expected Behavior |
|---|---|
| Empty list | Return `nullptr` |
| `k = 1` | Delete the head |
| `k = N` | Delete the tail |
| Single-node list, `k = 1` | Return `nullptr` |
| `k > N` | Return the original list |
| `k <= 0` | Return the original list |

## Complexity Analysis

- **Time Complexity:** `O(N)` – In the worst case, we traverse the entire list to find the kth node.
- **Space Complexity:** `O(1)` – Only a temporary pointer and a counter are used.

## Key Takeaway

In a doubly linked list, deleting a middle or last node requires updating both `prev` and `next` pointers.

The two important pointer updates are:

```cpp
temp->next->prev = temp->prev;
temp->prev->next = temp->next;
```

Always check whether the next node exists before accessing `temp->next->prev`.

Similarly, handle head deletion separately because the head has no previous node.
