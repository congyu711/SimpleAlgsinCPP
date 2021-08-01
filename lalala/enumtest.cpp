#include <bits/stdc++.h>
using namespace std;
int main()
{
    enum enumType
    {
        Step0,
        Step1,
        Step2
    } Step = Step0;


    enum class number:unsigned int
    {
        _one,
        _two
    } numb;
    numb=number::_one;

    
    switch (Step)
    {
    case Step0:
    {
        cout << "1" << endl;
        break;
    }
    case Step1:
    {
        cout << "2" << endl;
        break;
    }
    case Step2:
    {
        cout << "3" << endl;
        break;
    }
    default:
        break;
    }
}