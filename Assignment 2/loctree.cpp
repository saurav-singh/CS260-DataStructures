//CS260 - Data Structure
//Saurav Singh - sms668

#ifndef _LOC_TREEE
#define _LOC_TREEE

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Node to be used in LOC TREE
class Node
{
  public:
    //Constructor
    Node(int v, string l = "Unlabeled")
    {
        val = v;
        label = l;
        next = NULL;
    }
    int val;
    string label;
    Node *next;
};

/* --- LOC TREE class definition --- */
class Loc_tree
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
    void SETLABEL(int n, string l);
    void PRINTALL();

  private:
    vector<Node *> Tree;
};

/* --- LOC TREE operation function implementations ---   */
/* --- The functions return elements instead of node --- */
/* --- Returns -1 instead of NULL if not found       --- */

//Returns parent of n
int Loc_tree::PARENT(int n)
{

    for (int i = 0; i < Tree.size(); i++)
    {
        for (Node *ptr = Tree[i]->next; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->val == n)
                return Tree[i]->val;
        }
    }

    return -1;
}

//Returns leftmost child of n
int Loc_tree::LEFTMOST_CHILD(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n && Tree[i]->next != NULL)
        {
            return Tree[i]->next->val;
        }
    }

    return -1;
}

//Returns the right sibling of n
int Loc_tree::RIGHT_SIBLING(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        for (Node *ptr = Tree[i]->next; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->val == n && ptr->next != NULL)
            {
                return ptr->next->val;
            }
        }
    }

    return -1;
}

//Returnshe root of the tree
int Loc_tree::ROOT()
{
    if (Tree.size() == 0)
        return -1;
    else
        return Tree[0]->val;
}

//Returns label of n
string Loc_tree::LABEL(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (Tree[i]->val == n)
            return Tree[i]->label;
    }

    return "Unlabeled";
}

void Loc_tree::SETLABEL(int n, string l)
{
    int index = FIND(n);
    if (index != -1)
        Tree[index]->label = l;
}

//Returns position if n is in Tree else
int Loc_tree::FIND(int n)
{
    for (int i = 0; i < Tree.size(); i++)
    {
        if (n == Tree[i]->val)
        {
            return i;
        }
    }

    return -1;
}

//Prints the tree in LOC form
void Loc_tree::PRINTALL()
{
    if (Tree.size() == 0)
        cout << "\nTree is empty.\n";
    else
    {
        cout << "\nLOC representation of Tree: \n\n";
        for (int i = 0; i < Tree.size(); i++)
        {
            cout << "[ " << Tree[i]->val << " ] -> ";
            for (Node *ptr = Tree[i]->next; ptr != NULL; ptr = ptr->next)
            {
                cout << ptr->val << " -> ";
            }
            cout << " * \n";
        }
    }
}

//Makes the tree to be null
void Loc_tree::MAKENULL()
{
    Tree.clear();
}

//Appends T (n Trees) to Tree
void Loc_tree::CREATEi(string label, vector<int> T)
{
    //index = location of first element if found else -1
    int index = FIND(T[0]);

    //If first element of T not in Tree then insert new node at end
    if (index == -1)
    {
        Tree.push_back(new Node(T[0], label));
        index = Tree.size() - 1;
    }

    //If T has more than 1 element
    if (T.size() > 1)
    {
        //Create node pointer
        Node *ptr = Tree[index];

        //Traverse to end of child nodes
        for (ptr; ptr->next != NULL; ptr = ptr->next)
            ;

        //Traverse through T
        for (int i = 1; i < T.size(); i++)
        {
            //Append elements of T to child nodes
            ptr->next = new Node(T[i]);
            ptr = ptr->next;

            //If T[i] is not in Tree append it to Tree
            if (FIND(T[i]) == -1)
            {
                Tree.push_back(new Node(T[i]));
            }
        }
    }
}

#endif