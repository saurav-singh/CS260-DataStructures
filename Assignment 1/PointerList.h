//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "Node.h"

using namespace std;

//List Pointer class------------------------------------------------

class ListPtr
{
  public:
    //Operation functiton prototypes
    int LOCATE(int x);
    int RETRIEVE(int p);
    int NEXT(int p);
    int PREVIOUS(int p);
    int END();
    int FIRST();
    void INSERT(int x, int p);
    void DELETE(int p);
    void MAKENULL();
    void PRINTLIST();

  private:
    Node *_head = NULL;
    Node *_tail = NULL;
};

//Operation function implementations--------------------------------


//Delete function implementation
void ListPtr::DELETE(int p)
{
    if (_head == NULL)
        cout << "\nList is empty\n";
    else if (p < 0 || p >= END())
        cout << "\nOut of bound\n";
    else
    {
        int i = 0;
        Node *ptr = _head;
        Node *prev = _head;

        while (ptr != NULL)
        {
            if (i == p)
            {
                if (i == 0)
                {
                    _head = ptr->next;
                }
                else if (i == END() - 1)
                {
                    prev->next = NULL;
                    _tail = prev;
                }
                else
                    prev->next = ptr->next;
                
                delete ptr;
            }
            i++;
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

//Makenull function implementation
void ListPtr::MAKENULL()
{
    _head = _tail = NULL;
}

//First function implementation
int ListPtr::FIRST()
{
    if (_head == NULL)
        cout << "\nList is empty\n";

    return 0;
}

//Previous function implementation
int ListPtr::PREVIOUS(int p)
{
    if (_head == NULL)
    {
        cout << "List is empty";
        return -1;
    }
    else if (p > 0 && p < END())
    {
        return p - 1;
    }
    else
    {
        cout << "Out of bound";
        return -1;
    }
}

//Next function implementation
int ListPtr::NEXT(int p)
{
    if (_head == NULL)
    {
        cout << "List is empty";
        return -1;
    }
    else if (p >= 0 && p < END())
    {
        return p + 1;
    }
    else
    {
        cout << "Out of bound";
        return -1;
    }
}

//Retrieve function implementation
int ListPtr::RETRIEVE(int p)
{
    if (_head == NULL)
    {
        cout << "List is empty";
        return -1;
    }
    else if (p >= END())
    {
        cout << "Out of bounds";
        return -1;
    }
    else
    {
        int i = 0;
        Node *ptr = _head;

        while (ptr != NULL)
        {
            if (i == p)
                return ptr->val;

            i++;
            ptr = ptr->next;
        }
    }
}

//Locate function implementation
int ListPtr::LOCATE(int x)
{
    if (_head == NULL)
    {
        cout << "List is empty";
        return -1;
    }
    else
    {
        int p = 0;
        Node *ptr = _head;

        while (ptr != NULL)
        {
            if (ptr->val == x)
                return p;

            p++;
            ptr = ptr->next;
        }
        
        return END();
    }
}

//End function implementation
int ListPtr::END()
{
    if (_head == NULL)
        return 0;
    else
    {
        int i = 0;
        Node *ptr = _head;
        while (ptr != NULL)
        {
            i++;
            ptr = ptr->next;
        }

        return i;
    }
}

//Insert function implementation
void ListPtr::INSERT(int x, int p)
{
    if (p < 0 || p > END())
    {
        cout << "\nOut of bound\n";
    }
    else if (_head == NULL && p == 0)
    {
        Node *ptr = new Node;
        ptr->val = x;
        ptr->next == NULL;
        _head = _tail = ptr;
    }
    else if (_tail != NULL && p == END())
    {
        Node *N = new Node;
        N->val = x;
        N->next = NULL;
        _tail->next = N;
        _tail = N;
    }
    else
    {
        int i = 0;
        Node *ptr = _head;
        Node *prev = _head;

        while (ptr != NULL || i < p)
        {
            if (i == p)
            {
                Node *N = new Node;
                N->val = x;
                N->next = ptr;

                if (p == 0)
                    _head = N;
                else
                    prev->next = N;
            }
            i++;
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

//Printlist function implementation
void ListPtr::PRINTLIST()
{
    if (_head == NULL)
        cout << "\nList is empty\n";
    else
    {
        Node *ptr = _head;
        cout << "\n";
        while (ptr != NULL)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}