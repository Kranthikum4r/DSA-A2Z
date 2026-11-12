# Sort List – Merge Sort
[Problem Link](https://leetcode.com/problems/sort-list/)

**Problem:** Given the head of a singly linked list, sort the linked list in ascending order and return its head.

## Approach: Merge Sort (Divide and Conquer)

### Intuition

We use the **Merge Sort** algorithm to sort the linked list.

Merge Sort follows the Divide and Conquer technique:

1. Divide the linked list into two halves.
2. Recursively sort both halves.
3. Merge the two sorted linked lists.
4. Continue until the entire linked list is sorted.

We use the **Slow and Fast Pointer technique** to find the middle of the linked list.

### Algorithm

**Step 1: Merge Two Sorted Lists**

- Use a dummy node to simplify merging.
- Compare the values of both lists.
- Attach the smaller node to the result.
- Move the corresponding pointer forward.
- Attach the remaining nodes once one list becomes empty.

**Step 2: Split the Linked List**

- Initialize `slow = head` and `fast = head->next`.
- Move slow one step and fast two steps.
- When fast reaches the end, slow points to the end of the first half.
- Disconnect the two halves using `slow->next = NULL`.
- Return the head of the second half.

**Step 3: Sort the Linked List**

- If the list is empty or contains only one node, return it.
- Split the list into two halves.
- Recursively sort both halves.
- Merge the sorted halves.

### Code (C++)

```cpp
class Solution {
public:
    // Merge two sorted linked lists
    ListNode* mergeLists(ListNode* first, ListNode* second) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(first != nullptr && second != nullptr) {
            if(first->val <= second->val) {
                tail->next = first;
                first = first->next;
            }
            else {
                tail->next = second;
                second = second->next;
            }

            tail = tail->next;
        }

        tail->next = (first != nullptr) ? first : second;

        return dummy.next;
    }

    // Split the linked list into two halves
    ListNode* splitList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        return second;
    }

    // Sort linked list using Merge Sort
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* second = splitList(head);

        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        return mergeLists(left, right);
    }
};
```

---

## Dry Run

**Input:**

```text
4 -> 2 -> 1 -> 3
```

### Step 1: Divide the list

First split:

```text
Left:  4 -> 2
Right: 1 -> 3
```

Split both halves again:

```text
4    2    1    3
```

Now every sublist contains only one node.

### Step 2: Merge sorted sublists

Merge `4` and `2`:

```text
2 -> 4
```

Merge `1` and `3`:

```text
1 -> 3
```

### Step 3: Final Merge

Merge both sorted halves:

```text
2 -> 4
1 -> 3
```

Compare the elements:

```text
1 -> 2 -> 3 -> 4
```

**Final Output:**

```text
1 -> 2 -> 3 -> 4
```

---

## Understanding the Slow and Fast Pointer

```cpp
ListNode* slow = head;
ListNode* fast = head->next;

while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

For the linked list:

```text
1 -> 2 -> 3 -> 4
```

Initially:

```text
slow = 1
fast = 2
```

After one iteration:

```text
slow = 2
fast = 4
```

The loop stops because `fast->next` is `NULL`.

Therefore:

```text
First half:  1 -> 2
Second half: 3 -> 4
```

We use `fast = head->next` so that the first half is correctly separated, including when the list has an even number of nodes.

---

## Complexity Analysis

Let `N` be the number of nodes in the linked list.

**Time Complexity: `O(N log N)`**

- Splitting the linked list takes `O(N)` time at each recursion level.
- Merging the two sorted halves also takes `O(N)` time.
- The list is divided into halves, resulting in `O(log N)` recursion levels.

Therefore:

\[
O(N) \times O(\log N) = O(N\log N)
\]

**Auxiliary Space Complexity: `O(log N)`**

- The recursive calls require `O(log N)` stack space.
- The merging operation itself uses `O(1)` auxiliary space.
- No additional arrays or vectors are used.

---

## Important Edge Cases

| Input | Output |
|---|---|
| `NULL` | `NULL` |
| `5` | `5` |
| `2 -> 1` | `1 -> 2` |
| `4 -> 2 -> 1 -> 3` | `1 -> 2 -> 3 -> 4` |
| `1 -> 2 -> 3 -> 4` | `1 -> 2 -> 3 -> 4` |
| `3 -> 3 -> 1 -> 2` | `1 -> 2 -> 3 -> 3` |

## Key Takeaways

1. Merge Sort is an efficient sorting algorithm for linked lists.
2. Slow and Fast Pointers help divide the linked list into two halves.
3. Recursion continues until each sublist contains only one node.
4. Two sorted linked lists can be merged using a dummy node and a tail pointer.
5. The algorithm achieves `O(N log N)` time complexity.
6. It does not require additional arrays or vectors.

**Final Complexity:**
- Time: `O(N log N)`
- Auxiliary Space: `O(log N)` due to recursion stack.
