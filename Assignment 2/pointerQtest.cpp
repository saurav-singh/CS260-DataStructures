//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "pointerqueue.cpp"

using namespace std;

int main()
{
    Queue Q;

    cout <<"\nProgram to test Pointer Queue Implementation: \n\n";
    
    cout <<"\nENQUEUE(1-30): ";
    for (int i = 0; i < 30; i++)
        Q.ENQUEUE(i + 1);

    cout <<"\n\nPRINTALL(): ";
    Q.PRINTALL();

    cout <<"\nDEQUEUE()";
    Q.DEQUEUE();

    cout << "\n\nFront(): " << Q.FRONT();

    cout <<"\n\nMAKENULL()";
    Q.MAKENULL();

    cout <<"\n\nPRINTALL(): ";
    Q.PRINTALL();

    cout <<endl;
    return 0;
}