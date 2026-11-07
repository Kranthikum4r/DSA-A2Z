*Insertion at the tail of Linked List*
[Problem Link](https://takeuforward.org/practice/dsa/insertion-at-the-tail-of-ll)

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
    ListNode* insertAtTail(ListNode* &head, int X) {
        ListNode* node = new ListNode(X);
        if(!head) {
            return node;
        }
        ListNode* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = node;
        return head;
    }
};
```
