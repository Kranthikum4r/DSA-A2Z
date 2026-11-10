# Add One to a Number Represented by Linked List
[Problem Link](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1)

## Problem Statement
Given the head of a singly linked list representing a non-negative integer, add 1 to the number and return the head of the updated linked list.

Each node contains a single digit, and the digits are stored from most significant to least significant.

### Example 1
**Input:** `1 -> 2 -> 3`

**Output:** `1 -> 2 -> 4`

### Example 2
**Input:** `1 -> 9 -> 9`

**Output:** `2 -> 0 -> 0`

### Example 3
**Input:** `9 -> 9 -> 9`

**Output:** `1 -> 0 -> 0 -> 0`

---

## Approach: Reverse, Add One, Reverse Again

Since addition starts from the least significant digit, we reverse the linked list to process the digits from left to right.

### Algorithm

1. Reverse the original linked list using an iterative approach.
2. Initialize `carry = 1` because we need to add one.
3. Traverse the reversed linked list while a carry exists.
4. Calculate `sum = temp->data + carry`.
5. Update the current node:
   - `temp->data = sum % 10`
   - `carry = sum / 10`
6. If carry remains after reaching the last node, create a new node containing the carry.
7. Reverse the linked list again to restore the original digit order.
8. Return the new head.

## C++ Solution

```cpp
class Solution {
public:
    Node* reverseList(Node* head) {
        Node* curr = head;
        Node* prev = NULL;

        while(curr) {
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* addOne(Node* head) {
        Node* revhead = reverseList(head);

        Node* temp = revhead;
        int carry = 1;

        while(temp && carry) {
            int sum = temp->data + carry;

            temp->data = sum % 10;
            carry = sum / 10;

            if(carry == 0) break;

            if(temp->next == NULL) {
                temp->next = new Node(carry);
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        Node* finalhead = reverseList(revhead);

        return finalhead;
    }
};
```

---

## Dry Run

**Input:** `1 -> 9 -> 9`

### Step 1: Reverse the linked list

`9 -> 9 -> 1`

### Step 2: Add one

| Current Digit | Sum | Updated Digit | Carry |
|---|---|---|---|
| 9 | 9 + 1 = 10 | 0 | 1 |
| 9 | 9 + 1 = 10 | 0 | 1 |
| 1 | 1 + 1 = 2 | 2 | 0 |

Reversed result: `0 -> 0 -> 2`

### Step 3: Reverse again

`2 -> 0 -> 0`

**Final Output:** `2 -> 0 -> 0`

---

## Complexity Analysis

- **Time Complexity:** O(N)
  - First reversal takes O(N).
  - Adding one takes O(N) in the worst case.
  - Final reversal takes O(N).

- **Auxiliary Space Complexity:** O(1)
  - Only a constant number of pointers and variables are used.
  - A new node is allocated only when an additional carry is required.

## Edge Cases

| Input | Output |
|---|---|
| `1 -> 2 -> 3` | `1 -> 2 -> 4` |
| `1 -> 9 -> 9` | `2 -> 0 -> 0` |
| `9 -> 9 -> 9` | `1 -> 0 -> 0 -> 0` |
| `0` | `1` |
| `9` | `1 -> 0` |

## Key Takeaways

- Reverse a linked list to simplify operations starting from the least significant digit.
- Use `% 10` to extract the resulting digit.
- Use `/ 10` to calculate the carry.
- Create a new node only when a carry remains after processing the last node.
- Reverse the list again to restore the original digit order.

**Pattern:** Linked List Reversal + Carry Propagation
