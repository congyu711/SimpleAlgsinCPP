#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//unique
class Solution1
{
public:
    ListNode *unique(ListNode *head)
    {
        ListNode *p = head;
        while (p && p->next) //in case head is nullptr
        {
            if (p->val == p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};
//delete all duplicates
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *l, *r;
        ListNode *p = new ListNode;
        p->next = head;
        head = p;
        while (p->next)
        {
            l = p->next;
            r = l;
            while (r->next && r->next->val == l->val)
            {
                r = r->next;
            }
            if (l == r)
                p = p->next;
            else
                p->next = r->next;
        }
        return head->next;
    }
};
int main()
{
}