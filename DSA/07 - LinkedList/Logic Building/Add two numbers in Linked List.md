# Add Two Numbers
[Problem Link](https://leetcode.com/problems/add-two-numbers/description/)

## Problem Statement
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each node contains a single digit.

Add the two numbers and return the sum as a linked list, also in reverse order.

## Approach: Iterative Addition Using Carry

We use a **Dummy Node** to simplify the construction of the result linked list.

### Algorithm
1. Create a dummy node with value `0` and initialize a pointer `curr` to it.
2. Initialize `carry = 0` to store the carry from the previous addition.
3. Traverse both linked lists while at least one list has nodes remaining or a carry exists.
4. Initialize `sum = carry`.
5. If `l1` is not NULL:
   - Add `l1->val` to `sum`.
   - Move `l1` to the next node.
6. If `l2` is not NULL:
   - Add `l2->val` to `sum`.
   - Move `l2` to the next node.
7. Calculate:
   - `carry = sum / 10`
   - `digit = sum % 10`
8. Create a new node containing `digit` and attach it to the result list.
9. Move `curr` forward.
10. Return `dummy->next` as the head of the resultant linked list.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while(l1 || l2 || carry) {
            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};
```

## Example Dry Run

**Input:**

- `l1 = [2, 4, 3]` → Represents 342
- `l2 = [5, 6, 4]` → Represents 465

**Calculation:**

342 + 465 = 807

| Step | l1 digit | l2 digit | Carry | Sum | Result digit |
|---|---:|---:|---:|---:|---:|
| 1 | 2 | 5 | 0 | 7 | 7 |
| 2 | 4 | 6 | 0 | 10 | 0 |
| 3 | 3 | 4 | 1 | 8 | 8 |

**Output:** `[7, 0, 8]`

## Complexity Analysis

Let `N` be the length of the first linked list and `M` be the length of the second linked list.

- **Time Complexity:** `O(max(N, M))` – Each node is visited exactly once.
- **Space Complexity:** `O(max(N, M))` – A new linked list is created to store the result.

## Key Concepts Learned

- Dummy Node technique.
- Traversing two linked lists simultaneously.
- Handling different linked list lengths.
- Carry management in addition.
- Creating a new linked list dynamically.
- Handling the remaining carry after traversal.

## Important Edge Cases

1. Both linked lists have only one node.
2. The two linked lists have different lengths.
3. Addition produces a carry at the final position.
4. Both numbers contain zeros.
5. All digits generate a carry, e.g., `[9,9,9] + [1]`.

## Key Takeaway

The Dummy Node technique simplifies linked list construction by providing a fixed starting point. Using `sum / 10` and `sum % 10` allows us to handle carry and result digits just like normal arithmetic addition.
