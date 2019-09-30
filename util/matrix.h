#pragma once
#include <vector>
#include <initializer_list>
#include <string>
#include <iostream>
#include "matrix_column_iter.h"

template <typename TData>
std::vector<TData> Flatten(const std::initializer_list<std::initializer_list<TData>>& data) {
    if (data.size() == 0) {
        return {};
    }
    std::vector<TData> result{};
    for (auto& arr : data) {
        for (auto& item : arr) {
            result.push_back(item);
        }
    }
    return result;
}

template <typename TData>
class Matrix {
private:
    std::vector<TData> data_;
    size_t rows_;
    size_t columns_;

public:
    Matrix(const std::initializer_list<std::initializer_list<TData>>& data)
        : rows_(data.size()), columns_(data.size()), data_(Flatten(data)) {
    }

public:
    TData& at(size_t i, size_t j) {
        return data_.at(i * columns_ + j);
    }

    TData at(size_t i, size_t j) const {
        return data_.at(i * columns_ + j);
    }

    size_t Columns() const {
        return columns_;
    }

    size_t Rows() const {
        return rows_;
    }
    decltype(data_.begin()) begin() {
        return data_.begin();
    }

    decltype(data_.end()) end() {
        return data_.end();
    }

    decltype(data_.cbegin()) begin() const {
        return data_.begin();
    }

    decltype(data_.cend()) end() const {
        return data_.end();
    }

    decltype(data_.begin()) RowBegin(size_t row) {
        return data_.begin() + row * columns_;
    }

    const decltype(data_.cbegin()) RowBegin(size_t row) const {
        return data_.begin() + row * columns_;
    }

    decltype(data_.end()) RowEnd(size_t row) {
        return data_.begin() + (row + 1) * columns_;
    }

    const decltype(data_.cend()) RowEnd(size_t row) const {
        return data_.begin() + (row + 1) * columns_;
    }

    ColumnIter<TData> ColumnBegin(size_t column) {
        return ColumnIter {&data_, column, columns_};
    }

    ColumnIter<TData> ColumnEnd(size_t column) {
        return ColumnIter {&data_, column, columns_} + rows_;
    }


    const ColumnIter<TData> ColumnBegin(size_t column) const {
        return ColumnIter {&data_, column, columns_};
    }

    const ColumnIter<TData> ColumnEnd(size_t column) const {
        return ColumnIter {&data_, column, columns_} + rows_;
    }
};

template <typename TData>
bool operator==(const Matrix<TData>& lhs, const Matrix<TData>& rhs) {
    if (lhs.Columns() != rhs.Columns() || lhs.Rows() != rhs.Rows()) {
        return false;
    }

    for (auto i = 0; i < rhs.Rows(); i++) {
        for (auto j = 0; j < rhs.Columns(); j++) {
            if (rhs.at(i, j) != lhs.at(i, j)) {
                return false;
            }
        }
    }
    return true;
}

template <typename TData>
std::ostream& operator<<(std::ostream& out, const Matrix<TData>& matrix) {
    out << "{";
    std::copy(matrix.begin(), matrix.end() - 1, std::ostream_iterator<TData>(out, ", "));
    if (matrix.begin() != matrix.end() - 1) {
        out << *(matrix.end() - 1);
    }
    out << "}";
    return out;
}
