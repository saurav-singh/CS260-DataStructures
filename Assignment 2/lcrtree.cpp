//CS260 - Data Structure
//Saurav Singh - sms668

#ifndef _LCR_TREE
#define _LCR_TREE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Node to be used for LCR TREE
class NodeT
{
  public:
    //Constructor
    NodeT(int v, string l = "unlabeled'")
    {
        val = v;
        label = l;
        LC = NULL;
        RS = NULL;
        PARENT = NULL;
    }
    int val;
    string label;
    NodeT *LC;
    NodeT *RS;
    NodeT *PARENT;
};

/* --- LCR TREE class definition --- */
class Lcr_tree
{
  public:
    int PARENT(int n);
    int LEFTMOST_CHILD(int n);
    int RIGHT_SIBLING(int n);
    int ROOT();
    string LABEL(int n);
    void MAKENULL();
    void CREATEi(string label, vector<int> T);

    //helper functions
    int FIND(int n);
    void PRINTALL();

  private:
    vector<NodeT *> Tree;
};

/* --- LOC TREE operation function implementations ---   */
/* --- The functions return elements instead of NodeT --- */
/* --- Returns -1 instead of NULL if not found       --- */

//Returns parent of n
int Lcr_tree::PARENT(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n)
        {
            return Tree[i]->PARENT->val;
        }
    }

    return -1;
}

//Returns Leftmost child of  n
int Lcr_tree::LEFTMOST_CHILD(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n)
        {
            return Tree[i]->LC->val;
        }
    }

    return -1;
}

//Returns right sibling of n
int Lcr_tree::RIGHT_SIBLING(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n)
        {
            return Tree[i]->RS->val;
        }
    }

    return -1;
}

//Returns root of the tree
int Lcr_tree::ROOT()
{
    if (Tree.size() == 0)
        return -1;
    else
        return Tree[0]->val;
}

//Returns label of n
string Lcr_tree::LABEL(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n)
        {
            return Tree[i]->label;
        }
    }

    return "Unlabeled";
}

//Makes the tree null
void Lcr_tree::MAKENULL()
{
    Tree.clear();
}

//Returns index of n if found in Tree
int Lcr_tree::FIND(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n)
        {
            return i;
        }
    }

    return -1;
}

//Prints tree in LCR form
void Lcr_tree::PRINTALL()
{
    if (Tree.size() == 0)
        cout << "\nEmpty tree.\n";
    else
    {
        cout << "\nLCR Representation of Tree: \n\n";
        cout << "[  LC  ] | [ Val ] | [  RS ]\n";

        for (int i = 0; i < Tree.size(); i++)
        {
            if (Tree[i]->LC != NULL)
                cout << "[  " << Tree[i]->LC->val << "   ] | ";
            else
                cout << "[  *   ] | ";

            cout << "[  " << Tree[i]->val << "  ]";

            if (Tree[i]->RS != NULL)
                cout << " | [  " << Tree[i]->RS->val << "  ] ";
            else
                cout << " | [  *  ]";

            cout << endl;
        }
    }
}

void Lcr_tree::CREATEi(string label, vector<int> T)
{

    //index = location of first element if found else -1
    int index = FIND(T[0]);

    //If first element of T not in Tree then insert new NodeT at end
    if (index == -1)
    {
        Tree.push_back(new NodeT(T[0], label));
        index = Tree.size() - 1;
    }

    //If T has more than 1 element
    if (T.size() > 1)
    {
        int last_add;
        //Traverse through T
        for (int i = T.size() - 1; i >= 1; i--)
        {
            //Append to tree
            Tree.push_back(new NodeT(T[i]));
            last_add = Tree.size() - 1;

            //Add parent connection
            Tree[last_add]->PARENT = Tree[index];

            //Add as Right sibling if available
            if (i != T.size() - 1 && T[i + 1] == Tree[last_add - 1]->val)
            {
                Tree[last_add]->RS = Tree[last_add - 1];
            }
        }

        //Add left child 
        Tree[index]->LC = Tree[last_add];
    }
}

#endif
