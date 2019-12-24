//CS260 - Data Structure
//Saurav Singh - sms668

#ifndef _QUEUE
#define _QUEUE

#include <iostream>

using namespace std;

class NodeQ
{
  public:
    int val;
    NodeQ *next;
};

class Queue
{
  public:
    //Constructor
    Queue()
    {
        _front = NULL;
        _rear = NULL;
    }
    //Operation functions
    void MAKENULL();
    void ENQUEUE(int x);
    void DEQUEUE();
    void PRINTALL();
    int FRONT();
    int SIZE();
    bool EMPTY();

  private:
    NodeQ *_front;
    NodeQ *_rear;
};

void Queue::ENQUEUE(int x)
{
    //If Queue is empty then front = rear
    if (_front == NULL)
    {
        NodeQ *N = new NodeQ;
        N->val = x;
        N->next = NULL;
        _front = _rear = N;
    }
    //Else insert at rear
    else
    {
        NodeQ *N = new NodeQ;
        N->val = x;
        N->next = NULL;
        _rear->next = N;
        _rear = N;
    }
}

void Queue::DEQUEUE()
{
    if (_front == NULL)
    {
        cout << "\nQueue is empty\n";
    }
    else
    {
        NodeQ *temp = _front;
        _front = _front->next;
        delete (temp);
    }
}

int Queue::SIZE()
{
    if (_front == NULL)
        return 0;
    else
    {
        int size = 0;
        for (NodeQ *ptr = _front; ptr != NULL; ptr = ptr->next)
            size++;

        return size;
    }
}

void Queue::PRINTALL()
{
    if (_front == NULL)
    {
        cout << "\nQueue is empty\n";
    }
    else
    {
        cout << "\n(front) ";
        for (NodeQ *ptr = _front; ptr != NULL; ptr = ptr->next)
        {
            cout << ptr->val << " ";
        }
        cout << "(rear)\n";
    }
}

void Queue::MAKENULL()
{
    while (!EMPTY())
        DEQUEUE();
}

bool Queue::EMPTY()
{
    if (_front == NULL)
        return true;
    else
        return false;
}

int Queue::FRONT()
{
    if (_front == NULL)
    {
        cout << " Queue is empty";
        return -1;
    }
    else
    {
        return (_front->val);
    }
}

#endif