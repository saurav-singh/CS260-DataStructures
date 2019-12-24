#include <iostream>
#include <ctime>

using namespace std;

const int MAX = 100000;

//Dictioiniary
class Close_Hash
{
  private:
    int DICT[MAX];

  public:
    Close_Hash()
    {
        MAKENULL();
    }
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
// -1 taken as NULL
// -2 taken as DELETED

//Empties the dictionary
void Close_Hash::MAKENULL()
{
    for (int i = 0; i < MAX; i++)
    {
        DICT[i] = -1;
    }
}

//Returns true if x is in the dictionary
bool Close_Hash::MEMBER(int x)
{
    int bucket = h(x);

    if (DICT[bucket] == x)
        return true;
    else
    {
        int t = x;
        while (DICT[bucket] == -2)
        {
            bucket = h(++t);
            if (DICT[bucket == x])
                return true;
        }
    }

    return false;
}

//Inserts x into the dictionary
void Close_Hash::INSERT(int x)
{
    if (!MEMBER(x))
    {
        int bucket = h(x);
        int t = x;
        int c = 0;

        //Find an empty bucket
        while (DICT[bucket] > 0)
        {
            bucket = h(++t);
            //Break if dict is full
            if (++c == MAX)
            {
                bucket = -1;
                break;
            }
        }

        if (bucket > 0)
            DICT[bucket] = x;
    }
}

//Deletes x from the dictionary
void Close_Hash::DELETE(int x)
{
    int bucket = h(x);
    int t = x;
    int c = 0;

    while (DICT[bucket] > 0)
    {
        //Delete if found
        if (DICT[bucket] == x)
        {
            DICT[bucket] = -1;
            break;
        }
        bucket = h(++t);
        //Break if dict is full
        if (++c == MAX)
        {
            bucket = -1;
            break;
        }
    }
}

//   MAIN IMPLEMENTATION

int main()
{

    Close_Hash Dict;

    cout <<"Closed Hash Dictinary: \n";
    cout <<"------------------------\n";
    cout <<"Bucket Size = 100000\n";
    cout <<"# elements inserted & deleted = 10000\n";

    cout <<"\nTest Result:\n";

    //Time variables
    clock_t begin, end;
    double totalTime;

    begin = clock();

    for (int i = 0; i < 10000; i++)
    {
        Dict.INSERT(i); 
    }

    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Insert Total time = " << totalTime << " sec";

    cout <<endl;

    begin = clock();

    for (int i = 0; i < 10000; i++)
    {
        Dict.DELETE(i); 
    }

    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Delete Total time = " << totalTime << " sec";
    
    cout <<"\n\nConclusion in closedhash.txt\n\n";

    return 0;
}
