#include <iostream>
#include <string>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::endl;

struct ListNode
{
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void push(ListNode** headReference, int newData)
{
    ListNode* newNode = new ListNode();
    newNode->val = newData;
    newNode->next = (*headReference);

    (*headReference) = newNode;
}

void printList(ListNode *theNode)
{
    while(theNode != NULL)
    {
        cout << " " << theNode->val << endl;
        theNode = theNode->next;
    }
}

class TheSolution
{
    public:
        ListNode* rotateRight(ListNode* head, int k)
        {

            if(head == nullptr)
            {
                return head;
            }

            ListNode* position = head;
            int num = 1;
            while(position->next != nullptr)
            {
                position = position->next;
                num++;
            }


            position->next = head;
            k = k % num;

            for(int i = 0; i < num - k; i++)
            {
                position = position->next;
            }

            head = position->next;
            position->next = nullptr;

            return head;
        }
};

int main()
{
    TheSolution ts = TheSolution();

    cout << "Display Original" << endl;

    ListNode* theHead = NULL;

    push(&theHead, 4);
    push(&theHead, 3);
    push(&theHead, 2);
    push(&theHead, 1);
    push(&theHead, 0);
   
    printList(theHead);

    cout << "Rotated" << endl;
    printList(ts.rotateRight(theHead, 2));
       
}