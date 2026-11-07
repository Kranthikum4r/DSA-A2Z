# Insert a Node Before a Node with Value X in a Singly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/insertion-before-the-value-x-in-ll?tab=problem)

## Problem Statement

Given the head of a singly linked list and two integers `X` and `val`, insert a new node with value `val` **before the node containing value `X`**.

Return the updated head of the linked list.

If the value `X` is not present, return the original list unchanged.

## C++ Solution

```cpp
class Solution {
public:
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        if(!head) return head;

        ListNode* node = new ListNode(val);

        // Case 1: Insert before the head
        if(head->data == X) {
            node->next = head;
            head = node;
            return head;
        }

        // Case 2: Insert before any other node
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp) {
            if(temp->data == X) {
                node->next = temp;
                prev->next = node;
                return head;
            }

            prev = temp;
            temp = temp->next;
        }

        // X was not found
        delete node;
        return head;
    }
};
```

## Approach

We use two pointers:

- `temp`: Points to the current node.
- `prev`: Points to the node immediately before `temp`.

### Step 1: Handle an empty list

```cpp
if(!head) return head;
```

If the linked list is empty, there is no node before which we can insert.

### Step 2: Create the new node

```cpp
ListNode* node = new ListNode(val);
```

Create a new node containing the value `val`.

### Step 3: Handle insertion before the head

```cpp
if(head->data == X) {
    node->next = head;
    head = node;
    return head;
}
```

If the head itself contains `X`, insert the new node before it.

We update the head because the newly inserted node becomes the first node.

### Step 4: Traverse the linked list

```cpp
ListNode* temp = head;
ListNode* prev = NULL;
```

Traverse the list while maintaining the previous node.

```cpp
while(temp) {
    if(temp->data == X) {
        node->next = temp;
        prev->next = node;
        return head;
    }

    prev = temp;
    temp = temp->next;
}
```

When `temp` points to the node containing `X`:

1. Connect the new node to `temp`.
2. Connect `prev` to the new node.
3. Return the original head.

### Step 5: Handle X not found

```cpp
delete node;
return head;
```

If traversal finishes without finding `X`, the new node was never inserted.

Therefore, delete the allocated node to avoid a memory leak and return the original list.

## Dry Run

**Input:**

```text
head = [1, 2, 3, 4]
X = 3
val = 10
```

Initially:

```text
temp = 1
prev = NULL
```

| Iteration | temp | prev | Action |
|---|---:|---:|---|
| 1 | 1 | NULL | X not found |
| 2 | 2 | 1 | X not found |
| 3 | 3 | 2 | X found |

Now perform:

```cpp
node->next = temp;
prev->next = node;
```

The pointer connections become:

```text
Before insertion:

1 -> 2 -> 3 -> 4 -> NULL

After insertion:

1 -> 2 -> 10 -> 3 -> 4 -> NULL
```

**Output:**

```text
[1, 2, 10, 3, 4]
```

## Edge Cases

| Case | Input | Output |
|---|---|---|
| Insert before head | `[1, 2, 3]`, X = 1, val = 10 | `[10, 1, 2, 3]` |
| Insert in middle | `[1, 2, 3]`, X = 2, val = 10 | `[1, 10, 2, 3]` |
| Insert before tail | `[1, 2, 3]`, X = 3, val = 10 | `[1, 2, 10, 3]` |
| X not found | `[1, 2, 3]`, X = 5, val = 10 | `[1, 2, 3]` |
| Single-node list | `[1]`, X = 1, val = 10 | `[10, 1]` |

## Complexity Analysis

**Time Complexity: O(N)**

In the worst case, we traverse the entire linked list to find the node containing `X`.

**Auxiliary Space Complexity: O(1)**

We use only a constant number of pointers (`node`, `temp`, and `prev`).

One additional node is allocated for insertion.

## Important Points to Remember

1. Always create the new node using `val`, not `X`.
2. Handle insertion before the head separately because the head pointer must change.
3. `prev` must point to the node before `temp`.
4. To insert before `temp`, perform:

```cpp
node->next = temp;
prev->next = node;
```

5. If `X` is not found, delete the unused allocated node.
6. Since the problem guarantees that `X` occurs at most once, we only need to insert before the first matching node.
