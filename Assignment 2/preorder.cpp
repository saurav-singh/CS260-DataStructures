//CS260 - Data Structure
//Saurav Singh - sms668

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//Tokenizes string into vector spereated by spaces
vector<string> Tokenize(string E)
{
    vector<string> token;
    string temp = "";

    for (int i = 0; i < E.size(); i++)
    {
        if (E[i] == ' ')
        {
            token.push_back(temp);
            temp = "";
        }
        else
        {
            temp += E[i];
        }
    }

    token.push_back(temp);

    return token;
}

//Perform preorder evaluatiton on string E
float preorder(string E)
{
    vector<string> tokens = Tokenize(E);
    stack<float> s;

    for (int i = tokens.size() - 1; i >= 0; i--)
    {
        if (tokens[i].compare("+") == 0 || tokens[i].compare("-") == 0 || tokens[i].compare("*") == 0 || tokens[i].compare("/") == 0)
        {
            float x = s.top();
            s.pop();
            float y = s.top();
            s.pop();

            if (tokens[i].compare("+") == 0)
                s.push(x + y);
            if (tokens[i].compare("-") == 0)
                s.push(x - y);
            if (tokens[i].compare("*") == 0)
                s.push(x * y);
            if (tokens[i].compare("/") == 0)
                s.push(x/y);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }

    return s.top();
}

int main()
{
    cout << "\nPreorder Evaluation";
    cout << "\n-------------------------------------------------\n";

    cout << "\npreorder (+ 1 2) : " << preorder("+ 1 2");
    cout << "\npreorder (/ 1000 / 100 10) : " << preorder("/ 1000 / 100 10");
    cout << "\npreorder (* - 10 5 + 20 5) : " << preorder("* - 10 5 + 20 5");

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}