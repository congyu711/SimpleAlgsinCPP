#include <iostream>
#include <algorithm>
bool ascending(int x, int y)
{
    return x > y;
}
bool descending(int x, int y)
{
    return x < y;
}
class abc{
    public:
    bool operator()(int x,int y)
    {
        return x<y;
    }
};
void bubblesort(int *a, int n, bool (*cmpfunc)(int, int) = descending)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n - 1; i++)
            if (cmpfunc(a[i], a[i + 1]))
            {
                std::swap(a[i], a[i + 1]);
                sorted = false;
            }
        n--;
    }
}

int main()
{
    int a[8] = {5, 2, 5, 7, 1, -3, 99, 56};
    abc __decending;
    bubblesort(a, 8, __decending);
    std::sort(a,a+8,__decending);
    for (auto e : a)
        std::cout << e << " ";
    std::cout << std::endl;
}