//CS260 - Data Structure
//Saurav Singh - sms668
#include <iostream>
#include <ctime>
#include "lcrtree.cpp"
#include "loctree.cpp"
#include "pointerqueue.cpp"

using namespace std;

void PREORDER_LCR(Lcr_tree T);
void POSTORDER_LCR(Lcr_tree T);
void PREORDER_LOC(Loc_tree T);
void POSTORDER_LOC(Loc_tree T);

int main()
{
    //Time variables
    clock_t begin, end;
    double totalTime;

    //create LCR Tree
    Lcr_tree T1;
    vector<int> t1;
    t1.insert(t1.end(), {1, 2, 3});
    T1.CREATEi("Root", t1);
    t1.clear();
    t1.insert(t1.end(), {2, 4, 5});
    T1.CREATEi("Node [2]", t1);
    t1.clear();
    t1.insert(t1.end(), {3, 9, 10});
    T1.CREATEi("Node [3]", t1);
    t1.clear();
    t1.insert(t1.end(), {5, 6, 7, 8});
    T1.CREATEi("Node [5]", t1);

    //create LOC Tree
    Loc_tree T;
    vector<int> t;
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

    cout << "\n Tree time performanc: ";
    cout << "\n-----------------------------------------";

    //LCR PREORDER
    cout << "\nLCR PREORDER: ";
    begin = clock();
    POSTORDER_LCR(T);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //LCR POSTORDER
    cout << "\nLCR POSTORDER: ";
    begin = clock();
    PREORDER_LCR(T);
    PREORDER_LCR(T);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //LOC PREORDER
    cout << "\nLOC PREORDER: ";
    begin = clock();
    PREORDER_LOC(T);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //LOC POSTORDER
    cout << "\nLOC POSTORDER: ";
    begin = clock();
    POSTORDER_LOC(T);
    PREORDER_LOC(T);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    cout << "\n-----------------------------------------\n";

    return 0;
}

void PREORDER_LOC(Loc_tree T)
{
    Queue Q;
    int root = T.ROOT();
    int node = T.LEFTMOST_CHILD(root);
    while (true)
    {
        if (node != -1)
        {
            Q.ENQUEUE(node);
            node = T.RIGHT_SIBLING(node);
        }
        else
        {
            node = Q.FRONT();
            node = T.LEFTMOST_CHILD(node);
            Q.DEQUEUE();
        }
        if (Q.EMPTY())
            break;
    }
}

void PREORDER_LCR(Loc_tree T)
{
    Queue Q;
    int root = T.ROOT();
    int node = T.LEFTMOST_CHILD(root);
    while (true)
    {
        if (node != -1)
        {
            Q.ENQUEUE(node);
            node = T.RIGHT_SIBLING(node);
        }
        else
        {
            node = Q.FRONT();
            node = T.LEFTMOST_CHILD(node);
            Q.DEQUEUE();
        }
        if (Q.EMPTY())
            break;
    }
}
void POSTORDER_LCR(Loc_tree T)
{
    Queue Q;
    int root = T.ROOT();
    int node = T.LEFTMOST_CHILD(root);
    while (true)
    {
        if (node != -1)
        {
            Q.ENQUEUE(node);
            node = T.RIGHT_SIBLING(node);
        }
        else
        {
            node = Q.FRONT();
            node = T.LEFTMOST_CHILD(node);
            Q.DEQUEUE();
        }
        if (Q.EMPTY())
            break;
    }
}
void POSTORDER_LOC(Loc_tree T)
{
    Queue Q;
    int root = T.ROOT();
    int node = T.LEFTMOST_CHILD(root);
    while (true)
    {
        if (node != -1)
        {
            Q.ENQUEUE(node);
            node = T.RIGHT_SIBLING(node);
        }
        else
        {
            node = Q.FRONT();
            node = T.LEFTMOST_CHILD(node);
            Q.DEQUEUE();
        }
        if (Q.EMPTY())
            break;
    }
}