#include <vector>

template <typename T>
class ColumnIter
{
    std::vector<T>* data_;
    size_t column_num_;
    size_t columns_count_;
    size_t current_row_ {};
public:
    ColumnIter(std::vector<T>* data, size_t column_num, size_t columns_count)
        : data_(data), column_num_(column_num), columns_count_(columns_count)
    {}
    bool operator==(const ColumnIter &i) {
        return i.data_ == data_ && i.current_row_ == current_row_ && i.column_num_ == column_num_
        && i.columns_count_ == columns_count_;
    }
    bool operator!=(const ColumnIter &i) {
        return !(*this == i);
    }
    ColumnIter & operator++()    {
        ++current_row_;
        return *this;
    }
    ColumnIter operator++(int) { auto t = *this; ++current_row_; return t; }
    ColumnIter operator+(int step) { auto t = *this; t.current_row_ += step; return t; }
    ColumnIter & operator--()    { --current_row_; return *this; }
    ColumnIter operator--(int) { auto t = *this; --current_row_; return t; }
    std::ptrdiff_t operator-(ColumnIter const& sibling) const { return current_row_ - sibling.current_row_; }
    ColumnIter & operator+=(int amount) { current_row_ += amount; return *this; }
    ColumnIter & operator-=(int amount) { current_row_ -= amount; return *this; }
    bool operator<(ColumnIter const&sibling) const { return current_row_ < sibling.current_row_;}
    bool operator<=(ColumnIter const&sibling) const { return current_row_ <= sibling.current_row_; }
    bool operator>(ColumnIter const&sibling) const { return current_row_ > sibling.current_row_; }
    bool operator>=(ColumnIter const&sibling) const { return current_row_ >= sibling.current_row_; }
    T& operator[](int index) const { return *(*this + index); }
    T& operator*() const {
        return (*data_)[current_row_ * columns_count_ + column_num_];
    }
};

namespace std {
    template<typename T>
    class iterator_traits<ColumnIter<T>>
    {
    public:
        using difference_type = std::ptrdiff_t;
        using size_type = std::size_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;
    };
}