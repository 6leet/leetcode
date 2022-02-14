#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3, *pre;
        pre = new ListNode();
        pre->val = -1;
        l3 = pre;
        int carry = 0;
        while (l1 || l2 || carry) {
            ListNode *cur;
            cur = new ListNode();
            if (pre->val == -1) { // first node
                cur = pre;
            } else {
                pre->next = cur;   
            }
            int l1val = l1 ? l1->val : 0;
            int l2val = l2 ? l2->val : 0;
            int sum = l1val + l2val + carry;
            int val = sum % 10;
            carry = sum / 10;
            cur->val = val;
            pre = cur;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return l3;
    }
};

ListNode* stringToList(string s) {
    stringstream ss(s);
    string buf;
    ListNode *l, *pre;
    pre = new ListNode();
    l = pre;
    pre->val = -1;
    while (ss >> buf) {
        ListNode *cur;
        cur = new ListNode();
        if (pre->val == -1) {
            cur = pre;
        } else {
            pre->next = cur;
        }
        int val = stoi(buf);
        cur->val = val;
        pre = cur;
    }
    return l;
}

void printList(ListNode *l) {
    while (l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << '\n';
}

int main() {
    string s1, s2;
    cout << "l1: ";
    getline(cin, s1);
    cout << "l2: ";
    getline(cin, s2);

    ListNode* l1 = stringToList(s1), *l2 = stringToList(s2);
    printList(l1);
    printList(l2);
    
    Solution s;
    ListNode* l3 = s.addTwoNumbers(l1, l2);
    printList(l3);
}