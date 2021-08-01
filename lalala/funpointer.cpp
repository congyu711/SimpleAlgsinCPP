#include <iostream>
template <typename T>
bool ascending(T x, T y)
{
    return x > y;
}

template <typename T>
bool descending(T x, T y)
{
    return x < y;
}
template <typename T>
void bubblesort(T *a, int n, bool (*cmpfunc)(T, T) = descending)
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
    int b[8] = {5, 2, 5, 7, 1, -3, 99, 56};

    bubblesort<int>(a, 8, ascending);

    for (auto e : a)
        std::cout << e << " ";
    std::cout << std::endl;

    bubblesort<int>(b, 8, descending);

    for (auto e : b)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}