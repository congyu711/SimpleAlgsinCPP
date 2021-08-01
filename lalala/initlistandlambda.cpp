#include <bits/stdc++.h>
using namespace std;

// template <typename T, typename... Ts>
// auto printf3(T value, Ts... args)
// {
//     cout << value << std::endl;
//     (void)initializer_list<T>{([&args] {
//         cout << args << std::endl;
//     }(),value)...};
// }

template <typename... Ts>
auto printlist(Ts... args)
{
    //initializer list requires its elements to be the same type
    auto tmp = {args...};
    for (auto &e : tmp)
        cout << e << ' ';
}

template <typename... Ts>
auto printf3(Ts... args)
{
    (void)initializer_list<int>{([&args] {
        cout << args << std::endl;
        return 1;
    }())...};
}
template <typename... Ts>
auto count(Ts... args)
{
    cout<<sizeof...(args)<<endl;
}

int main()
{
    // printf3('a', 1, 23, 4);
    // printlist(1, 23, 4);
    // int a=1;
    // cout<<[&a]{return a+1;}()<<endl;
    count(1,2,2,2,2);
}