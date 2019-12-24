//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>

using namespace std;

const int MAXSIZE = 10000;

// -------------------------- Define List Class ------------------------------------
class ListArr
{

  public:
    //Constructor
    ListArr()
    {
        //Initialize entire list to 0
        MAKENULL();
    }

    //Operation functiton prototypes
    void INSERT(int x, int p);
    void DELETE(int p);
    void MAKENULL();
    void PRINTLIST();
    int NEXT(int p);
    int PREVIOUS(int p);
    int END();
    int FIRST();
    int LOCATE(int x);
    int RETRIEVE(int p);

  private:
    //Array holding list items
    int _list[MAXSIZE];
    //Position of Last element
    int _pos;
};

//---------------------------- FUNCTION IMPLEMENTATIONS -----------------------------

//End function
int ListArr::END()
{
    if (_pos == 0)
        cout <<"\nList is empty\n";

    return _pos;
}

//Insert functiton
void ListArr::INSERT(int x, int p)
{
    if (_pos == MAXSIZE)
        cout << "\nList is full\n";
    else
    {
        if (p == 0 || p < _pos)
        {
            for (int i = _pos; i > p; i--)
                _list[i] = _list[i - 1];

            _list[p] = x;
            _pos++;
        }
        else if (p == _pos)
        {
            _list[p] = x;
            _pos++;
        }
        else
        {
            cout << "\nPosition out of bounds\n";
        }
    }
}

//Locate function
int ListArr::LOCATE(int x)
{
    for (int i = 0; i < END(); i++)
        if (_list[i] == x)
            return i;

    return END();
}

//Retrive function
int ListArr::RETRIEVE(int p)
{
    if (p >= _pos || p < 0)
    {
        cout << "Position out of bounds";
        return -1;
    }
    else
    {
        return _list[p];
    }
}

//Delete function
void ListArr::DELETE(int p)
{
    if (p >= _pos || p < 0)
        cout << "\nPosition out of bounds\n";
    else
    {
        for (int i = p; i < _pos; i++)
            _list[i] = _list[i + 1];

        _pos--;
    }
}

//NEXT FUNCTION
int ListArr::NEXT(int p)
{
    if (_pos == 0)
    {
        cout << "List is empty";
        return -1;
    }
    else if (p >= 0 && p < _pos)
    {
        return p + 1;
    }
    else
    {
        cout << "Position out of bounds ";
        return -1;
    }
}

//PREVIOUS function
int ListArr::PREVIOUS(int p)
{
    if (p <= 0 || p > _pos + 1)
    {
        cout << "Position out of bounds ";
        return -1;
    }
    else
    {
        return p - 1;
    }
}

//MAKENULL function
void ListArr::MAKENULL()
{
    for (int i = 0; i < MAXSIZE; i++)
        _list[i] = 0;

    _pos = 0;
}

//FIRST function
int ListArr::FIRST()
{
    if (_pos == 0)
        cout <<"List is empty";

    return 0;
}

//PRINTLIST function
void ListArr::PRINTLIST()
{
    if (_pos == 0)
        cout << "\nList is empty\n";
    else
    {
        for (int i = 0; i < _pos; i++)
            cout << _list[i] << " ";
    }
}
