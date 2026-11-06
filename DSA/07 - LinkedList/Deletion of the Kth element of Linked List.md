# Deletion of the Kth Node in a Singly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/deletion-of-the-kth-element-of-ll)

## 1. Definition

Deletion of the Kth node means removing the node at position `k` from a singly linked list and connecting the previous node to the next node.

**Example:**

```text
Original:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

k = 3

After deletion:
10 -> 20 -> 40 -> 50 -> NULL
```

## 2. C++ Code

```cpp
class Solution {
public:
    ListNode* deleteKthNode(ListNode* &head, int k) {

        if(k == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        int len = 1;

        while(temp) {

            if(len == k) {
                prev->next = temp->next;
                delete temp;
                return head;
            }

            prev = temp;
            temp = temp->next;
            len++;
        }

        return head;
    }
};
```

## 3. Algorithm

1. If `k == 1`:
   - Store the current head in `temp`.
   - Move head to the next node.
   - Delete the old head.
   - Return the updated head.

2. Initialize three variables:
   - `temp = head`
   - `prev = NULL`
   - `len = 1`

3. Traverse the linked list using `while(temp)`.

4. Check whether `len == k`.
   - Connect `prev->next` to `temp->next`.
   - Delete `temp`.
   - Return head.

5. Otherwise:
   - Update `prev = temp`.
   - Move `temp = temp->next`.
   - Increment `len`.

6. If the Kth node does not exist, return the original head.

## 4. Dry Run

**Input:**

```text
10 -> 20 -> 30 -> 40 -> 50 -> NULL
k = 3
```

**Step 1: Initialization**

```cpp
ListNode* temp = head;
ListNode* prev = NULL;
int len = 1;
```

**Step 2: Traversal**

| Iteration | len | prev | temp |
|---|---:|---:|---:|
| 1 | 1 | NULL | 10 |
| 2 | 2 | 10 | 20 |
| 3 | 3 | 20 | 30 |

At the third iteration:

```cpp
if(len == k)
```

Since `len = 3` and `k = 3`, the condition becomes true.

**Step 3: Update the connection**

```cpp
prev->next = temp->next;
```

Before:

```text
10 -> 20 -> 30 -> 40 -> 50 -> NULL
      ^    ^
     prev temp
```

After:

```text
10 -> 20 ------> 40 -> 50 -> NULL
```

**Step 4: Delete the target node**

```cpp
delete temp;
```

Final linked list:

```text
10 -> 20 -> 40 -> 50 -> NULL
```

## 5. Edge Cases

| Case | Input | Expected Output |
|---|---|---|
| Empty list | `NULL, k=1` | `NULL` |
| Delete head | `10 -> 20, k=1` | `20` |
| Delete middle | `10 -> 20 -> 30, k=2` | `10 -> 30` |
| Delete tail | `10 -> 20 -> 30, k=3` | `10 -> 20` |
| K exceeds length | `10 -> 20, k=5` | Original list |

**Small improvement:** Add an empty-list and invalid-position check at the beginning:

```cpp
if(!head || k <= 0) return head;
```

This prevents accessing `head->next` when the list is empty and avoids invalid positions.

## 6. Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(N) | Traverses the linked list to find the Kth node |
| Space | O(1) | Uses only a constant number of pointers and variables |

Where N is the number of nodes in the linked list.

## 7. Key Points to Remember

- `temp` points to the node that needs to be deleted.
- `prev` points to the node immediately before `temp`.
- `prev->next = temp->next` skips the target node.
- `delete temp` frees the target node's memory.
- Handle deletion of the head separately because the head pointer must be updated.
- Use `while(temp)` so that the last node is also checked.

**Most important pointer operation:**

```cpp
prev->next = temp->next;
delete temp;
```

This is the fundamental operation for deleting a node when both the target node and its previous node are available.
