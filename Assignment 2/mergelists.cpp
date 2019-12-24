//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include <vector>
#include "ArrayList.h"

using namespace std;

//Swap function - swaps elements at position i and j in the List L
void swapArr(ListArr &L, int i, int j)
{
    if (i != j)
    {
        L.INSERT(L.RETRIEVE(j), i);
        L.INSERT(L.RETRIEVE(i + 1), j);
        L.DELETE(i + 1);
        L.DELETE(j + 1);
    }
}

//Partition function to partition for quick sort
int partition(ListArr &L, int low, int high)
{

    int pivot = L.RETRIEVE(high);

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (L.RETRIEVE(j) <= pivot)
        {
            i++;
            swapArr(L, i, j);
        }
    }
    swapArr(L, i + 1, high);

    return (i + 1);
}

//Quick sort function to sort a List
void quickSort(ListArr &L, int low, int high)
{
    if (low < high)
    {
        int pi = partition(L, low, high);

        quickSort(L, low, pi - 1);
        quickSort(L, pi + 1, high);
    }
}


//MergeLists function to merge N lists in ascending order
//Takes in vector (containing N list) and returns a single merged list
ListArr meregeLists(vector<ListArr> nList)
{
    ListArr mergedList;

    int index = 0;

    for (int i = 0; i < nList.size(); i++)
    {
        for (int j = 0; j < nList[i].END(); j++)
        {
            mergedList.INSERT(nList[i].RETRIEVE(j), index++);
        }
    }

    quickSort(mergedList, 0, mergedList.END() - 1);

    return mergedList;
}

int main()
{
    //Variable declaration
    vector<ListArr> L1, L2, L3;
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
    L1.push_back(l3);

    L2.push_back(l4);
    L2.push_back(l5);

    L3.push_back(l1);
    L3.push_back(l2);
    L3.push_back(l3);
    L3.push_back(l4);
    L3.push_back(l5);

    //Display lists and information
    cout << "\nMerge List Program";
    cout << "\n------------------------------------------------------------------\n";
    cout << "List l1 : ";
    l1.PRINTLIST();
    cout << "\nList l2 : ";
    l2.PRINTLIST();
    cout << "\nList l3 : ";
    l3.PRINTLIST();
    cout << "\nList l4 : ";
    l4.PRINTLIST();
    cout << "\nList l5 : ";
    l5.PRINTLIST();
    cout << "\n------------------------------------------------------------------";

    cout << "\nMergeList(l1,l2,l3) : ";
    l = meregeLists(L1);
    l.PRINTLIST();
    l.MAKENULL();

    cout << "\nMergeList(l4,l5) : ";
    l = meregeLists(L2);
    l.PRINTLIST();
    l.MAKENULL();

    cout << "\nMeregeList(l1,l2,l3,l4,l5) : ";
    l = meregeLists(L3);
    l.PRINTLIST();
    l.MAKENULL();

    cout << "\n--------------- END of Program -----------------------------------\n\n";

    return 0;
}
