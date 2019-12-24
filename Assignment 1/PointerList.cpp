//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "PointerList.h"

using namespace std;

int main()
{
    ListPtr list;

    cout << "\nPointer List Implementation test program.\n";
    cout << "--------------------------------------------\n";

    cout << "\nTest 1 - INSERT() - inserting (1-30)\n";
    for (int i = 0; i < 30; i++)
        list.INSERT(i + 1, i);

    cout << "\nPRINTLIST : ";
    list.PRINTLIST();

    cout << "\nTest 2 - NEXT() - return next position (if valid)";
    cout << "\nNext(5): " << list.NEXT(5);
    cout << "\tNext(100): " << list.NEXT(100);

    cout << "\n\nTest 3 - PREVIOUS() - return previous position (if valid)";
    cout << "\nPrevious(5): " << list.PREVIOUS(5);
    cout << "\tPrevious(0): " << list.PREVIOUS(0);

    cout << "\n\nTest 4 - FIRST() - return position of first element";
    cout << "\nFIRST(): " << list.FIRST();

    cout << "\n\nTest 5 - END() - return position of last+1 element";
    cout << "\nEND(): " << list.END();

    cout << "\n\nTest 6 - LOCATE() - return position of first occuring x element | returns END() if not found";
    cout << "\nLOCATE(10): " << list.LOCATE(10);
    cout << "\tLOCATE(100): " << list.LOCATE(100);

    cout << "\n\nTest 7 - RETRIEVE() - return element at p position";
    cout << "\nRETRIEVE(9): " << list.RETRIEVE(9);
    cout << "\tRETRIEVE(100): " << list.RETRIEVE(100);

    cout << "\n\nTest 8: DELETE() - deletes first occuring x element";
    cout << "\nDELETE(FIRST()) and DELETE(END()-1) - delete first and last element";
    list.DELETE(list.FIRST());
    list.DELETE(list.END()-1);
   
    cout <<"\n\nPRINTLIST() result after DELETE: ";
    list.PRINTLIST();

    cout <<"\n\nTest 9: MAKENULL() - Make the list empty";
    list.MAKENULL();
    
    cout <<"\n\nPRINTLIST() result after MAKENULL";
    list.PRINTLIST();

    cout <<"\n--------------- ALL TESTS COMPLETED ------------------------------\n\n";
    
    return 0;
}