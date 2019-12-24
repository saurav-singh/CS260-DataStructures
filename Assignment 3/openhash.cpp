#include <iostream>
#include <ctime>

using namespace std;

const int MAX = 100000;

//Node Class
class Node
{
  public:
    int val;
    Node *next;
    Node(int v = -1, Node *n = NULL)
    {
        val = v;
        next = n;
    }
};

//Dictioiniary
class Open_Hash
{
  private:
    Node *DICT[MAX];

  public:
    void MAKENULL();
    bool MEMBER(int x);
    void INSERT(int x);
    void DELETE(int x);
};

//Hash Function - taken from book
int h(int x)
{
    int sum = 0;
    for (int i = 0; i < 1; i++)
        sum += (x+48);

    sum = sum % MAX;
    return sum;
}

// Function implementations

//Empties the dictionary
void Open_Hash::MAKENULL()
{
    for (int i = 0; i < MAX; i++)
    {
        DICT[i] = NULL;
    }
}

//Returns true if x is in the dictionary
bool Open_Hash::MEMBER(int x)
{
    Node *ptr;
    ptr = DICT[h(x)];

    while (ptr != NULL)
    {
        if (ptr->val == x)
            return true;
        else
            ptr = ptr->next;
    }

    return false;
}

//Inserts x into the dictionary
void Open_Hash::INSERT(int x)
{
    int bucket;
    Node *ptr;

    if (!MEMBER(x))
    {
        bucket = h(x);
        ptr = DICT[bucket];
        //Create new Node and insert
        Node *N = new Node(x, ptr);
        DICT[bucket] = N;
    }
}

//Deletes x from the dictionary
void Open_Hash::DELETE(int x)
{
    int bucket = h(x);
    Node *ptr = DICT[bucket];

    //If element in hash table
    if (ptr != NULL)
    {
        //Delete process if first element is x
        if (ptr->val == x)
        {
            DICT[bucket] = ptr->next;
        }
        //Delete process if x might be in buckets
        else
        {
            while (ptr->next != NULL)
            {
                if (ptr->next->val == x)
                {
                    ptr->next = ptr->next->next;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }
}

//   MAIN IMPLEMENTATION

int main()
{

    //Declare Dict
    Open_Hash Dict;

    cout <<"Open Hash Dictinary: \n";
    cout <<"------------------------\n";
    cout <<"Bucket Size = 100000\n";
    cout <<"# elements inserted & deleted = 10000\n";

    cout <<"\nTest Result:\n";

    //Time variables
    clock_t begin, end;
    double totalTime;

    begin = clock();

    for (int i = 0; i < 500; i++)
    {
        Dict.INSERT(i); 
    }

    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Insert Total time = " << totalTime << " sec";

    begin = clock();

    for (int i = 0; i < 10000; i++)
    {
        Dict.DELETE(i); 
    }

    cout <<endl;

    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Delete Total time = " << totalTime << " sec";

    cout <<"\n\nConclusion in openhash.txt\n\n";

    return 0;
}


