#include <bits/stdc++.h>>
using namespace std;


/**
 * Definition for singly-linked list. */
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
        
        int l1val = l1->val; int l2val = l2->val;
        ListNode* ans = nullptr; ListNode* curr = nullptr; ListNode *prev = nullptr;
        ans = new ListNode;
        curr = ans;
        prev = curr;
        curr->val = (l1val + l2val) % 10;
        int carry = (l1val + l2val) / 10;
        


        while(l1->next != nullptr || l2->next != nullptr || carry != 0){
            
            curr = new ListNode;
            if(l1->next == nullptr) l1val = 0;
            else{
                l1 = l1->next;
                l1val = l1->val;
            }
            if(l2->next == nullptr) l2val = 0;
            else{
                l2 = l2->next;
                l2val = l2->val;
            }
            cout<<l1val << l2val << carry << endl;
            curr->val = (l1val + l2val + carry)%10;
            carry = (l1val + l2val + carry)/10;
            if(prev != nullptr) prev->next = curr;
            prev = curr;


        }
        return ans;
    }

};

int main(){
    Solution solution = Solution();
    //45 + 293
    ListNode* oneOne = new ListNode;
    ListNode* oneTwo = new ListNode;
    ListNode* twoOne = new ListNode;
    ListNode* twoTwo = new ListNode;
    ListNode* twoThree = new ListNode;

    *oneOne = ListNode(9);
    *oneTwo = ListNode(5, oneOne);
    *twoOne = ListNode(9);
    *twoTwo = ListNode(9, twoOne);
    *twoThree = ListNode(1, twoTwo);

    ListNode *result = solution.addTwoNumbers(oneOne, twoThree);
    
    cout<<result->val;
    while(result->next!=nullptr){
        result = result->next;
        cout<<result->val;
    }
}