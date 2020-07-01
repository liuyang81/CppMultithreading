#include <iostream>
#include <type_traits>
#include <utility>

template<typename Fn>
void printRetType(Fn&& func)
{
    typedef typename std::result_of<Fn(int, int)>::type MyType;
    char a[std::is_same<int, MyType>::value];
    std::cout << "return type of Fn is int: " << std::is_same<int, MyType>::value << std::endl;
    std::cout << "return value of Fn is: " << func(4,5) << std::endl;
}

int main()
{
    printRetType( [](int x, int y) -> int { return x + y; } );
    return 0;
}