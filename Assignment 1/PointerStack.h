//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "Node.h"

using namespace std;

//Pointer Stack class ---------------------------------
class StackPtr
{
  public:
    void PRINTALL();
    void MAKENULL();
    int TOP();
    int POP();
    void PUSH(int x);
    bool EMPTY();

  private:
    Node *_top = NULL;
};

//------------------ Operation function implementation

//Printall function implementation
void StackPtr::PRINTALL()
{
    if (EMPTY())
    {
        cout << "\nStack is empty\n";
    }
    else
    {
        Node *ptr = _top;
        cout << "\n top->";
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

//Makenull function implementation
void StackPtr::MAKENULL()
{
    _top->next = NULL;
    _top = NULL;
}

int StackPtr::TOP()
{
    if (_top == NULL)
    {
        cout <<"\nStack is empty\n";
        return 0;
    }
    else
    {
        return _top->val;
    }
}

//Pop function implementation
int StackPtr::POP()
{
    if (EMPTY())
    {
        cout << "\nStack is empty\n";
        return 0;
    }
    else
    {
        int pop = _top->val;
        _top = _top->next;
        return pop;
    }
}

//Push function implementation
void StackPtr::PUSH(int x)
{
    Node *ptr = new Node;
    ptr->val = x;
    ptr->next = _top;
    _top = ptr;
}

//Empty function implementation
bool StackPtr::EMPTY()
{
    if(_top == NULL)
        return true;
    else
        return false;
}