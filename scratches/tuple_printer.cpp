#include <utility>
#include <string>
#include <iostream>
#include <tuple>

template <typename Type, unsigned N, unsigned Last>
struct printer
{
    static void print(const Type &tuple)
    {
        std::cout << std::get<N>(tuple) << ", ";
        printer<Type, N + 1, Last>::print(tuple);
    }
};

template <typename Type, unsigned N>
struct printer<Type, N, N>
{
    static void print(const Type &tuple)
    {
        std::cout << std::get<N>(tuple);
    }
};

template <typename... Type>
void print(std::tuple<Type...> tuple)
{
    printer<std::tuple<Type...>, 0, sizeof...(Type) - 1>::print(tuple);
}

int main()
{
    std::tuple<int, std::string, int> myTuple(1, "32323", 1);
    print(myTuple);
}