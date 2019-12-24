//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "loctree.cpp"

using namespace std;

int main()
{
    Loc_tree T;
    vector<int> t;

    cout <<"\n\nCreating tree using CREATEi(T..)\n";

    t.insert(t.end(), {1, 2, 3});
    T.CREATEi("Root", t);

    t.clear();
    t.insert(t.end(), {2, 4, 5});
    T.CREATEi("Node [2]", t);

    t.clear();
    t.insert(t.end(), {3, 9, 10});
    T.CREATEi("Node [3]", t);

    t.clear();
    t.insert(t.end(), {5, 6, 7, 8});
    T.CREATEi("Node [5]", t);

    T.PRINTALL();

    cout << "\nLEFTMOST_CHILD(1): " << T.LEFTMOST_CHILD(1);

    cout << "\nLABEL(1):" << T.LABEL(1);

    cout << "\nRIGHT_SIBLING(2): " << T.RIGHT_SIBLING(2);

    cout << "\nROOT(): " << T.ROOT();

    cout << "\nPARENT(4): " << T.PARENT(4);

    cout <<endl;

    return 0;
}