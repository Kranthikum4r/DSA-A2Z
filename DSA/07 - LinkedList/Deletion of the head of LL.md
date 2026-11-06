# Deletion of the Head of a Singly Linked List
[Problem Link](https://takeuforward.org/practice/dsa/deletion-of-the-head-of-ll)

## 1. Definition

Deletion of the head means removing the first node of a singly linked list and updating the head pointer to point to the second node.

## 2. C++ Code

```cpp
class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        ListNode* temp = head;

        head = head->next;

        delete temp;

        return head;
    }
};
```

## 3. Algorithm

1. Create a temporary pointer `temp` and store the current head address.
2. Move the head pointer to the next node using `head = head->next`.
3. Delete the old head node using `delete temp`.
4. Return the updated head pointer.

## 4. Dry Run

Consider the linked list:

```text
10 -> 20 -> 30 -> NULL
 ^
 head
```

**Step 1:** Store the current head in `temp`.

```cpp
ListNode* temp = head;
```

```text
temp
 |
 v
10 -> 20 -> 30 -> NULL
 ^
 head
```

**Step 2:** Move head to the next node.

```cpp
head = head->next;
```

```text
10 -> 20 -> 30 -> NULL
      ^
      head

temp -> 10
```

**Step 3:** Delete the old head.

```cpp
delete temp;
```

**Final Linked List:**

```text
20 -> 30 -> NULL
 ^
 head
```

## 5. Edge Cases

- **Empty linked list:** If `head == nullptr`, there is no node to delete. The function should return `nullptr`.
- **Single-node linked list:** After deletion, `head` becomes `nullptr`.
- **Multiple-node linked list:** The second node becomes the new head.

## 6. Optimized Code (Handles Edge Cases)

```cpp
class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {

        if(head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        head = head->next;

        delete temp;

        return head;
    }
};
```

## 7. Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(1) | Only a constant number of pointer operations |
| Space | O(1) | Uses only one temporary pointer |

## 8. Key Points to Remember

- Always store the old head before updating it.
- Update the head pointer before deleting the old node.
- Use `delete` to free dynamically allocated memory.
- Handle the empty linked list to avoid accessing a null pointer.
- Since `head` is passed by reference (`ListNode* &head`), changes to head are reflected in the original linked list.
