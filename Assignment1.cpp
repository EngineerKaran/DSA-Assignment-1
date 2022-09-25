#include <iostream>
#include <string>
#include "fmlyclss.h"
using namespace std;

Family *inputtoappend()
{

    int n;
    cout << "Kindly enter the number of family members : ";
    cin >> n;
    cout << endl;

    Family *head = NULL;
    Family *nextone = NULL;
    Family *previous = NULL;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cout << "Kindly enter " << i << "th family members name : ";
        cin >> s;
        int age;
        cout << "Kindly enter " << i << "th family memebers age : ";
        cin >> age;

        Family *newmember = new Family(s, age);

        if (head == NULL)
        {
            head = newmember;
            nextone = newmember;
            previous = newmember;
        }
        else
        {
            previous->next = newmember;
            newmember->previous = previous;
            nextone = newmember;
            previous = nextone;
        }
    }
    return head;
}

Family *removemember(Family *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    Family *temp = head;
    if (i == 0)
    {
        temp = temp->next;
        temp->previous = NULL;
        head = temp;
        return head;
    }
    else
    {
        int count = 0;
        Family *temp1 = head;
        Family *temp2 = NULL;

        while (count < (i - 1))
        {
            temp1 = temp1->next;
            count++;
        }
        Family *incomingdelete = temp1->next;
        temp2 = incomingdelete->next;
        temp1->next = temp2;
        temp2->previous = temp1;

        delete incomingdelete;
        return head;
    }
}

void printDLL(Family *head)
{
    Family *temp = head;
    cout << endl
         << "Family Details--" << endl;
    while (temp != NULL)
    {
        cout << "Respected family members name : " << temp->name << " "
             << "Respected family memebers age : " << temp->age << endl;
        temp = temp->next;
    }
}

int main()
{

    Family *head = inputtoappend();
    printDLL(head);

    int i;
    cin >> i;
    Family *removedmember = removemember(head, i);
    printDLL(removedmember);
}