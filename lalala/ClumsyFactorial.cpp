#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        if(N>4)
        {
            int c=N%4;
            if(c==0)    return N+1;
            else if(c==2||c==3)   return N+2;
            else return N-1;
        }
        else
        {
            switch (N)
            {
            case 0:
                return 0;
                break;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
            case 4:
                return 7;
            default:
                break;
            }
        }
    }
};
int main()
{

}