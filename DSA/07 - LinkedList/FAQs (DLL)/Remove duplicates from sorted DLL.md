# Remove Duplicates from Sorted DLL
[Problem Link](https://takeuforward.org/practice/dsa/remove-duplicated-from-sorted-dll)

## Problem Statement

Given the head of a sorted doubly linked list, remove all duplicate nodes so that each element appears only once.

Return the head of the modified doubly linked list.

## Approach: Two-Pointer Technique

Since the doubly linked list is sorted, all duplicate elements appear consecutively.

We traverse the list using a pointer `temp` and compare its value with the previous node's value.

### Algorithm

1. If the list is empty or contains only one node, return `head`.
2. Initialize `temp = head->next`.
3. Traverse the list while `temp` is not NULL.
4. Store the previous node using `prev = temp->prev`.
5. If `temp->val == prev->val`:
   - Connect `prev->next` to `temp->next`.
   - If the next node exists, update its `prev` pointer to `prev`.
   - Store the duplicate node in `del`.
   - Move `temp` to the next node.
   - Delete the duplicate node.
6. Otherwise, move `temp` to the next node.
7. Return the original `head`.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* removeDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp = head->next;

        while(temp) {
            ListNode* prev = temp->prev;

            if(temp->val == prev->val) {
                prev->next = temp->next;

                if(temp->next) {
                    temp->next->prev = prev;
                }

                ListNode* del = temp;
                temp = temp->next;

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
1 <-> 1 <-> 2 <-> 3 <-> 3 <-> 4
```

**Step-by-step execution:**

| Current node | Previous node | Action |
|---|---|---|
| 1 | 1 | Delete duplicate |
| 2 | 1 | Move forward |
| 3 | 2 | Move forward |
| 3 | 3 | Delete duplicate |
| 4 | 3 | Move forward |

**Output:**

```text
1 <-> 2 <-> 3 <-> 4
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N) | Each node is visited at most once. |
| Auxiliary Space | O(1) | Only a constant number of pointers are used. |

Where N is the number of nodes in the doubly linked list.

## Important Edge Cases

1. Empty doubly linked list.
2. DLL containing only one node.
3. No duplicate elements.
4. All elements are duplicates.
5. Duplicates at the beginning.
6. Duplicates at the end.
7. Multiple consecutive duplicate elements.

## Key Learnings

- A sorted DLL stores duplicate elements consecutively.
- Comparing the current node with its previous node is sufficient.
- Always update both `next` and `prev` pointers when deleting a node.
- Move the traversal pointer before deleting the current node to avoid accessing freed memory.
- Return the original head because the first node is never deleted when retaining one occurrence of each value.
