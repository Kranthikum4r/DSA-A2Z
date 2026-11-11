# Merge Two Sorted Linked Lists
[Problem Link](https://leetcode.com/problems/merge-two-sorted-lists/)

## Problem Statement

Given the heads of two sorted singly linked lists, merge them into a single sorted linked list and return its head.

The merged linked list should contain all nodes from both input lists in sorted order.

### Example 1

**Input:**
```text
list1 = [1, 3, 5]
list2 = [2, 4, 6]
```

**Output:**
```text
[1, 2, 3, 4, 5, 6]
```

### Example 2

**Input:**
```text
list1 = [1, 2, 4]
list2 = [1, 3, 4]
```

**Output:**
```text
[1, 1, 2, 3, 4, 4]
```

---

## Approach: Dummy Node + Two Pointers

### Intuition

Since both linked lists are already sorted, we can compare their current nodes and select the smaller value each time.

We use:
- `dummy`: A temporary node that simplifies the merging process.
- `tail`: Maintains the last node of the merged linked list.
- `list1` and `list2`: Traverse the two input linked lists.

### Algorithm

1. Create a dummy node with value `0`.
2. Initialize `tail` to point to the dummy node.
3. Traverse both lists while neither list is empty.
4. Compare the values of the current nodes.
5. Attach the smaller node to `tail->next`.
6. Move the corresponding list pointer forward.
7. Move `tail` forward.
8. When one list becomes empty, attach the remaining portion of the other list directly.
9. Return `dummy->next`, which points to the merged linked list.

---

## C++ Solution

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes
        if(list1) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy->next;
    }
};
```

---

## Dry Run

**Input:**
```text
list1 = 1 -> 3 -> 5
list2 = 2 -> 4 -> 6 -> 8
```

Initially:

```text
dummy -> NULL
tail = dummy
```

### Step-by-step execution

| Comparison | Selected node | Merged list |
|---|---|---|
| 1 vs 2 | 1 | 1 |
| 3 vs 2 | 2 | 1 → 2 |
| 3 vs 4 | 3 | 1 → 2 → 3 |
| 5 vs 4 | 4 | 1 → 2 → 3 → 4 |
| 5 vs 6 | 5 | 1 → 2 → 3 → 4 → 5 |

Now `list1` becomes `NULL`, while `list2` still contains:

```text
6 -> 8
```

Attach the remaining nodes directly:

```cpp
tail->next = list2;
```

**Final merged list:**

```text
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 8 -> NULL
```

---

## Important Pointer Operations

| Statement | Purpose |
|---|---|
| `tail->next = list1` | Attach a node from the first list |
| `tail->next = list2` | Attach a node from the second list |
| `list1 = list1->next` | Move the first pointer forward |
| `list2 = list2->next` | Move the second pointer forward |
| `tail = tail->next` | Update the merged list's tail |
| `tail->next = list1/list2` | Attach all remaining nodes |
| `return dummy->next` | Return the actual merged list |

### Why use a Dummy Node?

Without a dummy node, we would need special handling to identify the first node of the merged list.

The dummy node simplifies the implementation because every selected node is attached using the same logic.

---

## Complexity Analysis

Let:
- `N` = Number of nodes in the first list.
- `M` = Number of nodes in the second list.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(N + M) | Each node is processed at most once. |
| Auxiliary Space | O(1) | Only a constant number of pointers are used. |

---

## Edge Cases

1. Both linked lists are empty.
2. The first linked list is empty.
3. The second linked list is empty.
4. Both lists contain only one node.
5. Both lists contain duplicate values.
6. One list is completely smaller than the other.

---

## Key Takeaways

- Two sorted linked lists can be merged efficiently using two pointers.
- A dummy node simplifies linked list construction.
- Always move the selected list pointer forward.
- Once one list becomes empty, attach the remaining list directly.
- No additional linked list nodes are required for the merged result.

**Pattern:** Linked List + Two Pointers + Dummy Node
