#pragma once
#include <vector>
#include "matrix.h"

void PutZeroMarks(Matrix<int>* matrix) {
    for (size_t i = 1; i < matrix->Columns(); i++) {
        for (size_t j = 1; j < matrix->Rows(); j++) {
            if (matrix->at(i, j) == 0) {
                matrix->at(0, j) = 0;
                matrix->at(i, 0) = 0;
            }
        }
    }
}

void ZerifyRow(Matrix<int>* matrix, size_t row_num) {
    std::fill(matrix->RowBegin(row_num), matrix->RowEnd(row_num), 0);
}

void ZerifyColumn(Matrix<int>* matrix, size_t column_num) {
     std::fill(matrix->ColumnBegin(column_num), matrix->ColumnEnd(column_num), 0);
}

void ZerifyAccordingMarks(Matrix<int>* matrix) {
    for (size_t row = 1; row < matrix->Rows(); row++) {
        if (matrix->at(row, 0) == 0) {
            ZerifyRow(matrix, row);
        }
    }

    for (size_t column = 1; column < matrix->Columns(); column++) {
        if (matrix->at(0, column) == 0) {
            ZerifyColumn(matrix, column);
        }
    }
}

void MakeZeroMatrix(Matrix<int>* matrix) {
    if (matrix->Rows() == 0) {
        return;
    }

    bool firstRowHasZeros =
        std::find(matrix->RowBegin(0), matrix->RowEnd(0), 0) != matrix->RowEnd(0);

    bool firstColumnHasZeros =
        std::find(matrix->ColumnBegin(0), matrix->ColumnEnd(0), 0) != matrix->ColumnEnd(0);
    PutZeroMarks(matrix);
    ZerifyAccordingMarks(matrix);

    if (firstRowHasZeros) {
        ZerifyRow(matrix, 0);
    }

    if (firstColumnHasZeros) {
        ZerifyColumn(matrix, 0);
    }
}