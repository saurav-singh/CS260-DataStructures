//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>

using namespace std;

//Create MAX size for the stack
const int MAX = 10000;

//---------------Define Stack Class --------------------------------
class StackArr
{

  public:
    StackArr()
    {
        MAKENULL();
    }
    int TOP();
    int POP();
    void PUSH(int x);
    bool EMPTY();
    void MAKENULL();
    void PRINTALL();

  private:
    int _stack[MAX];
    int _top;
};
//---------------Operatiton Implementations -----------------------

//Pop function implementation
int StackArr::POP()
{
    if (_top == 0)
    {
        cout << "\nStack is empty";
        return -1;
    }
    else
    {
        int pop = _stack[_top - 1];
        _stack[_top - 1] = 0;
        _top--;
        return pop;
    }
}

//Push function implementation
void StackArr::PUSH(int x)
{
    if (_top == MAX)
        cout << "\nStack is full.";
    else
    {
        _stack[_top] = x;
        _top++;
    }
}

//Empty function implementation
bool StackArr::EMPTY()
{
    if (_top == 0)
        return true;
    else
        return false;
}

//Top function implementation
int StackArr::TOP()
{
    if (_top == 0)
        return -1;

    return _stack[_top - 1];
}

//Makenull function implementation
void StackArr::MAKENULL()
{
    for (int i = 0; i < MAX; i++)
        _stack[i] = 0;

    _top = 0;
}

//Printall function implementation
void StackArr::PRINTALL()
{
    if (_top == 0)
        cout << "\nStack is empty.";
    else
    {
        cout << "\n top ->";
        for (int i = _top - 1; i >= 0; i--)
            cout << _stack[i] << " ";
        cout << "\n";
    }
}
