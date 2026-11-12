# Delete All Occurrences of a Key in DLL
[Problem Link](https://takeuforward.org/practice/dsa/delete-all-occurrences-of-a-key-in-dll)

## Problem Statement

Given the head of a doubly linked list and an integer `target`, delete all the nodes whose value is equal to `target` and return the head of the modified doubly linked list.

## Approach: Pointer Manipulation

We traverse the doubly linked list and delete every node whose value matches the target.

### Algorithm

1. If the list is empty, return `head`.
2. **Delete matching nodes from the beginning:**
   - While the head contains the target value:
     - Store the current head in a temporary pointer `del`.
     - Move `head` to the next node.
     - Update the new head's `prev` pointer to `NULL`.
     - Delete the old head.
3. If the list becomes empty, return `head`.
4. Start traversal from `head->next`.
5. **Delete matching nodes during traversal:**
   - If the current node's value matches the target:
     - Store it in `del`.
     - Move `temp` to the next node before deleting.
     - Connect the previous node to the next node.
     - Update the next node's `prev` pointer if it exists.
     - Delete the current node.
   - Otherwise, move to the next node.
6. Return the updated head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        if(!head) return head;
        if(!head->next && head->val != target) return head;

        // Delete matching nodes from the beginning
        while(head && head->val == target) {
            ListNode* del = head;
            head = head->next;

            if(head) head->prev = NULL;

            delete del;
        }

        if(!head) return head;

        ListNode* temp = head->next;

        // Delete matching nodes from the remaining list
        while(temp) {
            if(temp->val == target) {
                ListNode* del = temp;

                temp = temp->next;

                del->prev->next = del->next;

                if(del->next) {
                    del->next->prev = del->prev;
                }

                delete del;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
```

## Example Dry Run

**Input:**

```text
DLL:    2 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2
Target: 2
```

**Step 1:** Delete matching nodes from the beginning.

```text
3 <-> 2 <-> 4 <-> 2
```

**Step 2:** Traverse the remaining list.

- Node `3`: Not equal to target. Move forward.
- Node `2`: Delete the node and reconnect its neighbors.
- Node `4`: Not equal to target. Move forward.
- Node `2`: Delete the last node.

**Output:**

```text
3 <-> 4
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N) | Every node is visited at most once. |
| Auxiliary Space | O(1) | Only a constant number of pointers are used. |

Where N is the number of nodes in the doubly linked list.

## Important Edge Cases

1. Empty linked list.
2. All nodes contain the target value.
3. No nodes contain the target value.
4. Only the head contains the target value.
5. Only the last node contains the target value.
6. Consecutive occurrences of the target.
7. Multiple occurrences throughout the list.

## Key Learnings

- Always update the `prev` pointer when deleting the head.
- Update both `next` and `prev` pointers when deleting a middle node.
- Move the traversal pointer before deleting the current node to avoid accessing freed memory.
- Handle the last node carefully because its `next` pointer is `NULL`.
- Pointer manipulation is essential when performing deletion operations in a doubly linked list.
