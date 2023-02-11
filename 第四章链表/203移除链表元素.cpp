#include <iostream>
//#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {
    Solution solution;

    ListNode *head, *tail;
    head = tail = new ListNode(0);
    tail->val = 1;
    for (int i = 2; i <= 5; i++) {
        tail->next = new ListNode(0);
        tail = tail->next;
        tail->val = i;
    }
    tail->next = NULL;


    solution.removeElements(head, 4);

    ListNode *temp = head;

    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
