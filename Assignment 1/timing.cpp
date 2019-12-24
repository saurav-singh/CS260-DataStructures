//CS260 - Data Structure
//Saurav Singh - sms668
//Time - iterated insertion (front and back) , traversal , iterated deletion(in front and back)

#include <iostream>
#include <ctime>
#include "ArrayList.h"
#include "ArrayStack.h"
#include "PointerList.h"
#include "PointerStack.h"
#include <list>
#include <stack>

using namespace std;

int main()
{
    //Time variables
    clock_t begin, end;
    double totalTime;

    //Data Structure variables
    ListArr list_arr;
    ListPtr list_ptr;
    list<int> list_std;
    StackArr stack_arr;
    StackPtr stack_ptr;
    stack<int> stack_std;

    cout << "\n---------Time Performance program (1000 elements)------------\n";
    //----------------------------------------------------------------------
    //Array List Time Performance-------------------------------------------
    //----------------------------------------------------------------------
    cout << "\n Data Structure: (Array List)";

    //Iterated Insertion (BACK)
    cout << "\n\t-Operation: Iterated insertion (back) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_arr.INSERT(i, i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Deletion (BACK)
    cout << "\n\t-Operation: Iterated Deletion (back) | ";
    begin = clock();
    for (int i = 999; i >= 0; i--)
        list_arr.DELETE(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Insertion (FRONT)
    cout << "\n\t-Operation: Iterated insertion (front) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_arr.INSERT(i, 0);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Traversal
    cout << "\n\t-Operation: Traversal | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        int t = list_arr.RETRIEVE(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Deletion (FRONT)
    cout << "\n\t-Operation: Iterated Deletion (front) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_arr.DELETE(0);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //----------------------------------------------------------------------
    //Pointer List Time Performance-----------------------------------------
    //----------------------------------------------------------------------

    cout << "\n\n Data Structure: (Pointer List)";

    //Iterated Insertion (BACK)
    cout << "\n\t-Operation: Iterated insertion (back) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_ptr.INSERT(i, i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Deletion (BACK)
    cout << "\n\t-Operation: Iterated Deletion (back) | ";
    begin = clock();
    for (int i = 999; i >= 0; i--)
        list_ptr.DELETE(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Insertion (FRONT)
    cout << "\n\t-Operation: Iterated insertion (front) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_ptr.INSERT(i, 0);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Traversal
    cout << "\n\t-Operation: Traversal | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        int t = list_ptr.RETRIEVE(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Deletion (FRONT)
    cout << "\n\t-Operation: Iterated Deletion (front) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_ptr.DELETE(0);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //----------------------------------------------------------------------
    //STD::LIST Time Performance--------------------------------------------
    //----------------------------------------------------------------------

    cout << "\n\n Data Structure: (STD::List)";

    //Iterated Insertion (BACK)
    cout << "\n\t-Operation: Iterated insertion (back) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_std.push_back(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Deletion (BACK)
    cout << "\n\t-Operation: Iterated Deletion (back) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_std.pop_back();
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Insertion (FRONT)
    cout << "\n\t-Operation: Iterated insertion (front) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_std.push_front(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Traversal
    cout << "\n\t-Operation: Traversal | ";
    begin = clock();
    list<int>::iterator it;
    for (it = list_std.begin(); it != list_std.end(); ++it)
        ;
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //Iterated Deletion (FRONT)
    cout << "\n\t-Operation: Iterated Deletion (front) | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        list_std.pop_front();
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //----------------------------------------------------------------------
    //Array Stack TIme Performance------------------------------------------
    //----------------------------------------------------------------------

    cout << "\n\n Data Structure: (Array Stack)";

    //PUSH
    cout << "\n\t-Operation: PUSH | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        stack_arr.PUSH(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //POP
    cout << "\n\t-Operation: POP | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        int t = stack_arr.POP();
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //----------------------------------------------------------------------
    //Pointer Stack Time Performance----------------------------------------
    //----------------------------------------------------------------------

    cout << "\n\n Data Structure: (Pointer Stack)";

    //PUSH
    cout << "\n\t-Operation: PUSH | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        stack_ptr.PUSH(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //POP
    cout << "\n\t-Operation: POP | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        int t = stack_ptr.POP();
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //----------------------------------------------------------------------
    //STD::STACK Time Performance-------------------------------------------
    //----------------------------------------------------------------------

    cout << "\n\n Data Structure: (STD::Stack)";

    //PUSH
    cout << "\n\t-Operation: PUSH | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        stack_std.push(i);
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    //POP
    cout << "\n\t-Operation: POP | ";
    begin = clock();
    for (int i = 0; i < 1000; i++)
        stack_std.pop();
    end = clock();
    totalTime = (double(end - begin) / CLOCKS_PER_SEC) * 1000;
    cout << "Total time = " << totalTime << " sec";

    cout << "\n\n-------------------END OF PERFORMANCE TEST --------------------------\n\n";

    return 0;
}