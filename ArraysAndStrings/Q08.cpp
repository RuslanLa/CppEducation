
#include <vector>
#include <iostream>
#include <algorithm>
#include "ArrayUtils.h"

using namespace std;


/*
 * Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
 */

bool checkFirstRowContainsZeros(vector<vector<int32_t>>& matrix) {
    return any_of(matrix[0].begin(), matrix[0].end(), [](auto value) {
        return value == 0;
    });
}

bool checkFirstColumnContainsZeros(vector<vector<int32_t>>& matrix) {
    return any_of(matrix.begin(), matrix.end(), [](auto& row) {
        return row[0] == 0;
    });
}

void markZeros(vector<vector<int32_t>>& matrix){
    for(auto i = 1; i< matrix.size(); i++){
        for(auto j = 1; j< matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
}

void makeColumnZero(vector<vector<int32_t>>& matrix, int32_t columnNumber){
    for(auto & row : matrix){
        row[columnNumber] = 0;
    }
}

void makeRowZero(vector<vector<int32_t>>& matrix, int32_t rowNumber){
    for(auto columnNumber = 0; columnNumber< matrix[0].size(); columnNumber++){
        matrix[rowNumber][columnNumber] = 0;
    }
}


void handleZeroColumns(vector<vector<int32_t>>& matrix){
    for(auto i = 1; i <  matrix.size(); i++){
        if(matrix[0][i] != 0){
            continue;
        }
        makeColumnZero(matrix, i);
    }
}

void handleZeroRows(vector<vector<int32_t>>& matrix){
    for(auto rowNumber = 1; rowNumber <  matrix[0].size(); rowNumber++){
        if(matrix[rowNumber][0] != 0){
            continue;
        }
        makeRowZero(matrix, rowNumber);
    }
}

void makeZeroMatrix(vector<vector<int32_t>>& matrix){
    if(matrix.empty() || matrix[0].empty()){
        return;
    }
    bool isFirstRowContainsZero = checkFirstRowContainsZeros(matrix);
    bool isFirstColumnContainsZero = checkFirstColumnContainsZeros(matrix);
    markZeros(matrix);
    handleZeroColumns(matrix);
    handleZeroRows(matrix);

    if(isFirstColumnContainsZero){
        makeColumnZero(matrix, 0);
    }
    if(isFirstRowContainsZero){
        makeRowZero(matrix, 0);
    }
}

int main(){
    auto matrix = createMatrix(5);
    matrix[0][1] = 0;
    matrix[4][4] = 0;
    matrix[2][1] = 0;
    cout << "matrix before:" << endl;
    print(matrix);
    makeZeroMatrix(matrix);
    cout << "matrix after:" << endl;
    print(matrix);
    return 0;
}