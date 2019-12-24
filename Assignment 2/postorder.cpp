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
 
//Perform postorder evaluatiton on string E
float postorder(string E)
{
    vector<string> tokens = Tokenize(E);
    stack<float> s;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].compare("+") == 0 || tokens[i].compare("-") == 0 || tokens[i].compare("*") == 0|| tokens[i].compare("/")==0)
        {
            float x = s.top();
            s.pop();
            float y = s.top();
            s.pop();
            
            if(tokens[i].compare("+") == 0)
                s.push(x+y);
            if(tokens[i].compare("-") == 0)
                s.push(y-x);
            if(tokens[i].compare("*") == 0)
                s.push(x*y);
            if(tokens[i].compare("/") == 0)
                s.push(y/x);
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
    cout <<"\nPostorder Evaluation";
    cout <<"\n-------------------------------------------------\n";

    cout <<"\npostorder (1 2 +) : " << postorder("1 2 +");
    cout <<"\npostorder (10 10 10 * *) : " << postorder("10 10 10 * *");
    cout <<"\npostorder (1000 2 / 20 20 + 100 2 * + -) : " << postorder("1000 2 / 200 40 + -");

    cout <<"\n-------------------------------------------------\n\n";
    return 0;
}