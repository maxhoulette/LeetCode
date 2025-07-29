#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void createDeepestNext(ListNode *l, ListNode *next)
    {
        if (!l->next)
        {
            l->next = next;
            l->next->val = next->val;
        }
        else
            createDeepestNext(l->next, next);
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *temp;
        int remainder = 0;
        int quotient = 0;
        int val = 0;

        if (l1)
            val = l1->val;
        if (l2)
            val += l2->val;

        // Compute the remainder at level i
        remainder = (val + quotient) % 10;

        // Use the remainder at level i and the quotient at level i-1
        result->val = remainder;

        // Compute the quotient at level i
        quotient = (val + quotient - remainder) / 10;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;

        while (l1 || l2 || quotient > 0)
        {
            temp = new ListNode();

            if (l1)
                val = l1->val;
            if (l2)
                val += l2->val;

            // Compute the remainder at level i
            remainder = (val + quotient) % 10;

            // Use the remainder at level i and the quotient at level i-1
            temp->val = remainder;

            // Compute the quotient at level i
            quotient = (val + quotient - remainder) / 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            createDeepestNext(result, temp);
        }

        return result;
    }
};