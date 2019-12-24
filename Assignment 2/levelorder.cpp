//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include "loctree.cpp"
#include "pointerqueue.cpp"

using namespace std;

void levelOrder(Loc_tree T)
{
    cout << "\nLevel Order Representation of Tree:\n\n";

    //Required data structures and variables
    Queue Q;
    int root = T.ROOT();
    int node = T.LEFTMOST_CHILD(root);
    int lineBreak = 0;

    cout << T.LABEL(root) << endl;

    while (true)
    {
        //Case for right sibling is valid
        if (node != -1)
        {
            Q.ENQUEUE(node);
            lineBreak++;
            cout << T.LABEL(node) << " ";
            node = T.RIGHT_SIBLING(node);
        }
        //Case for right sibling is not valid
        else
        {
            //Line break when size of queue matches linebreak
            if (lineBreak == Q.SIZE())
            {
                cout << endl;
                lineBreak = 0;
            }
            node = Q.FRONT();
            node = T.LEFTMOST_CHILD(node);
            Q.DEQUEUE();
        }

        //If Queue is empty break of out of the loop
        if (Q.EMPTY())
            break;
    }

    cout << endl;
}

int main()
{
    Loc_tree T;
    vector<int> t;

    //Create Tree using CREATEi
    t.insert(t.end(), {1, 2, 3});
    T.CREATEi("A", t);
    t.clear();
    t.insert(t.end(), {2, 4, 5});
    T.CREATEi("B", t);
    t.clear();
    t.insert(t.end(), {3, 6, 7, 8});
    T.CREATEi("C", t);
    t.clear();
    t.insert(t.end(), {5, 9});
    T.CREATEi("E", t);
    t.clear();
    t.insert(t.end(), {7, 10, 11});
    T.CREATEi("G", t);
    t.clear();
    t.insert(t.end(), {8, 12});
    T.CREATEi("H", t);
    t.clear();
    t.insert(t.end(), {9, 13,14});
    T.CREATEi("I", t);
    //Set Labels for unlabled nodes
    string l = "ABCDEFGHIJKLMN";
    for (int i=0;i<l.length();i++)
    {
        string s(1,l[i]);
        T.SETLABEL(i+1,s);
    }
    
    //Display Level order representation of tree
    levelOrder(T);

    return 0;
}