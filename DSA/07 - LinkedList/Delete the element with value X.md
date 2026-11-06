# Delete the Element with Value X in a Singly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/delete-the-element-with-value-x)

## 1. Definition

Deletion of an element with value `X` means finding the first node containing `X`, removing that node, and connecting the previous node to the next node.

**Example:**

```text
Original:
10 -> 20 -> 30 -> 40 -> NULL

X = 30

After deletion:
10 -> 20 -> 40 -> NULL
```

## 2. C++ Code

```cpp
class Solution {
public:
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {

        if(head->data == X) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp) {
            if(temp->data == X) {
                prev->next = temp->next;
                delete temp;
                return head;
            }

            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
```

## 3. Algorithm

1. Check whether the head node contains the value `X`.
   - Store the head in a temporary pointer `del`.
   - Move head to the next node.
   - Delete the old head.
   - Return the updated head.

2. Initialize two pointers:
   - `temp = head`
   - `prev = NULL`

3. Traverse the linked list using `while(temp)`.

4. Check whether `temp->data == X`.
   - Connect `prev->next` to `temp->next`.
   - Delete `temp`.
   - Return head.

5. If the value does not match:
   - Update `prev = temp`.
   - Move `temp = temp->next`.

6. If the value is not found, return the original head.

## 4. Dry Run

**Input:**

```text
10 -> 20 -> 30 -> 40 -> 50 -> NULL

X = 30
```

**Step 1: Initialize pointers**

```cpp
ListNode* temp = head;
ListNode* prev = NULL;
```

**Step 2: Traverse the linked list**

| Iteration | temp->data | prev->data | Condition |
|---|---:|---:|---|
| 1 | 10 | NULL | False |
| 2 | 20 | 10 | False |
| 3 | 30 | 20 | True |

When `temp->data == X`, the target node is found.

**Step 3: Update the connection**

```cpp
prev->next = temp->next;
```

Before:

```text
10 -> 20 -> 30 -> 40 -> 50 -> NULL
      ^     ^
     prev  temp
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
| Empty list | `NULL, X=10` | `NULL` |
| Value at head | `10 -> 20 -> 30, X=10` | `20 -> 30` |
| Value in middle | `10 -> 20 -> 30, X=20` | `10 -> 30` |
| Value at tail | `10 -> 20 -> 30, X=30` | `10 -> 20` |
| Value not present | `10 -> 20 -> 30, X=50` | Original list |

**Important improvement:** Add an empty-list check before accessing `head->data`:

```cpp
if(!head) return head;
```

Without this check, an empty linked list causes a null pointer access.

## 6. Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(N) | Traverses the list to find the target value |
| Space | O(1) | Uses only two pointers |

Where N is the number of nodes in the linked list.

## 7. Key Points to Remember

- Handle the head node separately because deleting it requires updating `head`.
- `temp` points to the node containing the target value.
- `prev` points to the node immediately before `temp`.
- `prev->next = temp->next` skips the target node.
- `delete temp` frees the memory occupied by the deleted node.
- If the value is not found, return the original head.
- This implementation deletes only the **first occurrence** of `X`.

**Important pointer operation:**

```cpp
prev->next = temp->next;
delete temp;
```

This is the fundamental operation for deleting a non-head node in a singly linked list.
