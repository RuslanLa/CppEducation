#ifndef CPPEDUCATION_LINKEDLISTUTILS_H
#define CPPEDUCATION_LINKEDLISTUTILS_H

#include <iostream>
#include <list>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::forward_list<T> const& a)
{
    out << "[ ";

    for(auto x : a)
    {
        out << x << " ";
    }

    out << "]";
    return out;
}
#endif //CPPEDUCATION_LINKEDLISTUTILS_H
