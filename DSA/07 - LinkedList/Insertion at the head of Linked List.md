*Insertion at the head of Linked List*
[Problem Link](https://takeuforward.org/practice/dsa/insertion-at-the-head-of-ll)

```
/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* newHead = new ListNode(X);
        newHead->next = head;
        head = newHead;
        return head;
    }
};
```
