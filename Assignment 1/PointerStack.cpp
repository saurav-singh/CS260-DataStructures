//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "PointerStack.h"

int main()
{
    StackPtr stack;

    cout << "\nPointer Stack Implementation test program.\n";
    cout << "--------------------------------------------\n";

    cout << "\nTest 1 - PUSH() - push 1-30 sequentially";
    for (int i = 0; i < 30; i++)
        stack.PUSH(i + 1);

    cout << "\n\nPRINTALL() result after PUSh operation:";
    stack.PRINTALL();

    cout << "\n\nTest 2 - POP() - returns and removes top element";
    cout << "\nCall POP() 10 times and print to console: ";
    cout << "\n\nPOPED elements: ";
    for (int i = 0; i < 10; i++)
        cout << stack.POP() << " ";

    cout << "\n\nPRINTALL() result after POP operation:";
    stack.PRINTALL();

    cout << "\n\nTest 3 - TOP() - returns the top element";
    cout << "\nTOP(): " << stack.TOP();

    cout << "\n\nTest 4 - EMPTY() - returns true if stack is empty otherwise false";
    cout << "\nEMPTY(): ";
    if (stack.EMPTY())
        cout << "True";
    else
        cout << "False";

    cout << "\n\nTest 5 - MAKENULL()- empties the stack";
    stack.MAKENULL();
    
    cout << "\n\nEMPTY() result after MAKENULL(): ";
    if (stack.EMPTY())
        cout << "True";
    else
        cout << "False";

    cout << "\n\nPRINTALL() result after MAKENULL() operation:";
    stack.PRINTALL();

    cout <<"\n\n--------------- ALL TESTS COMPLETED ------------------------------\n\n";
    
    return 0;
}