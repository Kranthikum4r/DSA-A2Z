# Deletion of the Tail of a Singly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/deletion-of-the-tail-of-ll)

## 1. Definition

Deletion of the tail means removing the last node of a singly linked list and updating the second-last node's `next` pointer to `NULL`.

Since a singly linked list allows traversal only in the forward direction, we need to maintain two pointers:
- `temp` – points to the current node.
- `prev` – points to the previous node.

## 2. C++ Code

```cpp
class Solution {
public:
    ListNode* deleteTail(ListNode* &head) {

        // Case 1: Empty linked list
        if(!head) return NULL;

        // Case 2: Only one node
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return head;
        }

        // Case 3: Multiple nodes
        ListNode* temp = head;
        ListNode* prev;

        while(temp->next) {
            prev = temp;
            temp = temp->next;
        }

        delete temp;
        prev->next = NULL;

        return head;
    }
};
```

## 3. Algorithm

1. Check whether the linked list is empty.
   - If `head == NULL`, return `NULL`.
2. Check whether the list contains only one node.
   - Delete the head node.
   - Set `head = NULL`.
   - Return head.
3. Initialize two pointers:
   - `temp = head`
   - `prev` to track the previous node.
4. Traverse the linked list until `temp->next == NULL`.
   - Before moving `temp`, update `prev = temp`.
   - Move `temp = temp->next`.
5. Delete the last node using `delete temp`.
6. Set `prev->next = NULL` to make the previous node the new tail.
7. Return the updated head.

## 4. Dry Run

Consider the linked list:

```text
10 -> 20 -> 30 -> 40 -> NULL
 ^
 head
```

**Step 1: Initialize pointers**

```cpp
ListNode* temp = head;
ListNode* prev;
```

```text
temp
 |
 v
10 -> 20 -> 30 -> 40 -> NULL
```

**Step 2: Traverse the linked list**

Loop condition: `while(temp->next)`

| Iteration | prev | temp |
|---|---|---|
| 1 | 10 | 20 |
| 2 | 20 | 30 |
| 3 | 30 | 40 |

At the end:

```text
prev
 |
 v
10 -> 20 -> 30 -> 40 -> NULL
                 ^
                 temp
```

Now `temp->next == NULL`, so the loop terminates.

**Step 3: Delete the last node**

```cpp
delete temp;
```

The node containing `40` is deleted.

**Step 4: Update the previous node's next pointer**

```cpp
prev->next = NULL;
```

Final linked list:

```text
10 -> 20 -> 30 -> NULL
 ^
 head
```

## 5. Edge Cases

**Case 1: Empty linked list**

```text
head = NULL
```

Return `NULL` without performing deletion.

**Case 2: Single-node linked list**

```text
10 -> NULL
```

After deletion:

```text
head = NULL
```

**Case 3: Multiple-node linked list**

```text
10 -> 20 -> 30 -> NULL
```

After deletion:

```text
10 -> 20 -> NULL
```

## 6. Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(N) | Traverses the linked list to reach the last node |
| Space | O(1) | Uses only two pointers (`temp` and `prev`) |

Where N is the number of nodes in the linked list.

## 7. Key Points to Remember

- We need two pointers because a singly linked list cannot move backward.
- `temp` identifies the last node.
- `prev` identifies the second-last node.
- `delete temp` frees the memory occupied by the last node.
- `prev->next = NULL` makes the second-last node the new tail.
- Always handle empty and single-node linked lists separately.

**Important:** Unlike deleting the head, deleting the tail requires traversal, so its time complexity is O(N).
