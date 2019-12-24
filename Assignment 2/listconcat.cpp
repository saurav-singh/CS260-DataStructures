//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include <vector>
#include "ArrayList.h"

using namespace std;

//concatList function takes in 2 Vectors of list as argument
//Returns concatinated vector of list
vector<ListArr> concatList(vector<ListArr> L1, vector<ListArr> L2)
{
    vector<ListArr> L;
    ListArr l;

    for (int i = 0; i < L1.size(); i++)
    {
        L.push_back(L1[i]);
    }
    for (int i = 0; i < L2.size(); i++)
    {
        L.push_back(L2[i]);
    }

    return L;
}

void displayVector(vector<ListArr> L)
{
    for (int i = 0; i < L.size(); i++)
    {
        cout << "[ ";
        L[i].PRINTLIST();
        cout << " ] ";
    }
}

int main()
{
    //Variable declaration
    vector<ListArr> L1, L2, L3, L;
    ListArr l1, l2, l3, l4, l5, l;

    //Insert data into lists
    for (int i = 0; i < 5; i++)
    {
        l1.INSERT(i, i);
        l2.INSERT((i + 1) * 5, i);
        l3.INSERT((i + 1) * 10, i);
        l4.INSERT((i + 1) * 2, i);
        l5.INSERT((i + 1) * 2 + 1, i);
    }

    //Insert lists into vectors
    L1.push_back(l1);
    L1.push_back(l2);

    L2.push_back(l4);
    L2.push_back(l5);

    L3.push_back(l1);
    L3.push_back(l4);
    L3.push_back(l3);

    //Display lists and information
    cout << "\nConcat List Program";
    cout << "\n------------------------------------------------------------------";
    cout << "\n L1 : ";
    displayVector(L1);
    cout << "\n L2 : ";
    displayVector(L2);
    cout << "\n L3 : ";
    displayVector(L3);
    cout << "\n------------------------------------------------------------------";

    cout << "\n Concat(L1,L2): ";
    L = concatList(L1, L2);
    displayVector(L);
    L.clear();

    cout << "\n Concat(L2,L3): ";
    L = concatList(L2, L3);
    displayVector(L);
    L.clear();

    cout << "\n Concat(L3,L1): ";
    L = concatList(L3, L1);
    displayVector(L);
    L.clear();

    cout << "\n\n--------------- END of Program -----------------------------------\n\n";

    return 0;
}