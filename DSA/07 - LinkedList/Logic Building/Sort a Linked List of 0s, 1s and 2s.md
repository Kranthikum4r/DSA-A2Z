# Sort a Linked List of 0s, 1s and 2s
[Problem Link](https://takeuforward.org/practice/dsa/sort-a-ll-of-0's-1's-and-2's)

## Problem Statement

Given the head of a linked list containing only `0`, `1`, and `2`, sort the linked list in ascending order.

The sorting should be performed by rearranging the existing nodes rather than creating a new linked list.

## Approach: Three Dummy Nodes (Segregation)

We create three separate linked lists to store nodes containing `0`, `1`, and `2`.

Instead of sorting the nodes using traditional sorting algorithms, we segregate them into three groups and connect them in the required order.

### Algorithm

1. Create three dummy nodes:
   - `zeroHead` for nodes containing `0`.
   - `oneHead` for nodes containing `1`.
   - `twoHead` for nodes containing `2`.

2. Initialize three pointers:
   - `zero = zeroHead`
   - `one = oneHead`
   - `two = twoHead`

3. Traverse the original linked list using `temp`.

4. For each node:
   - Store its next node in `nextNode`.
   - Detach the current node by setting `temp->next = NULL`.
   - If its value is `0`, append it to the zero list.
   - If its value is `1`, append it to the one list.
   - Otherwise, append it to the two list.
   - Move `temp` to `nextNode`.

5. Connect the three lists:
   - Connect the zero list to the one list if it exists; otherwise, connect it to the two list.
   - Connect the one list to the two list.
   - Set the last node of the two list to `NULL`.

6. Store `zeroHead->next` as the new head.

7. Delete all three dummy nodes and return the new head.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* &head) {
        // Creating dummy nodes
        ListNode* zeroHead = new ListNode(-1);
        ListNode* zero = zeroHead;

        ListNode* oneHead = new ListNode(-1);
        ListNode* one = oneHead;

        ListNode* twoHead = new ListNode(-1);
        ListNode* two = twoHead;

        ListNode* temp = head;

        while(temp) {
            ListNode* nextNode = temp->next;
            temp->next = NULL;

            if(temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }

            temp = nextNode;
        }

        // Connecting the three lists
        zero->next = oneHead->next ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        ListNode* newHead = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};
```

## Example Dry Run

**Input:**

`head = [1, 0, 2, 1, 0, 2, 1]`

### Step 1: Initialize three lists

- Zero list: `NULL`
- One list: `NULL`
- Two list: `NULL`

### Step 2: Traverse and segregate nodes

| Current Node | Zero List | One List | Two List |
|---|---|---|---|
| 1 | - | 1 | - |
| 0 | 0 | 1 | - |
| 2 | 0 | 1 | 2 |
| 1 | 0 | 1 → 1 | 2 |
| 0 | 0 → 0 | 1 → 1 | 2 |
| 2 | 0 → 0 | 1 → 1 | 2 → 2 |
| 1 | 0 → 0 | 1 → 1 → 1 | 2 → 2 |

### Step 3: Connect the lists

Connect the zero list to the one list, and the one list to the two list.

**Final Output:**

`[0, 0, 1, 1, 1, 2, 2]`

## Complexity Analysis

Let `N` be the number of nodes in the linked list.

- **Time Complexity:** `O(N)` – We traverse the linked list exactly once to segregate the nodes. Connecting the three lists takes constant time.
- **Space Complexity:** `O(1)` – Only three dummy nodes and a constant number of pointers are used. The original nodes are rearranged without creating additional data nodes.

## Important Edge Cases

1. Empty linked list: `[]`
2. Only zeroes: `[0, 0, 0]`
3. Only ones: `[1, 1, 1]`
4. Only twos: `[2, 2, 2]`
5. Missing zeroes: `[1, 2, 1, 2]`
6. Missing ones: `[0, 2, 0, 2]`
7. Missing twos: `[0, 1, 0, 1]`
8. Single node: `[1]`

## Key Concepts Learned

- Linked list segregation.
- Dummy Node technique.
- Rearranging existing nodes.
- Maintaining separate linked lists.
- Connecting multiple linked lists.
- Pointer manipulation.
- Dynamic memory management.

## Key Takeaway

Instead of sorting the linked list directly, we can segregate nodes into three separate lists based on their values.

By connecting the zero, one, and two lists in order, we achieve sorting in a single traversal.

This approach takes **O(N) time and O(1) auxiliary space** without creating additional data nodes.
