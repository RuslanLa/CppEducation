
#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>

using namespace std;

void print(const vector<vector<int32_t >>& matrix){
    for(const auto& row: matrix){
        for(auto value: row){
            cout << value << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int32_t >>& matrix, int32_t level, int32_t position) {
    auto size = matrix.size();
    int32_t* top = &matrix[level][level+position];
    int32_t* right = &matrix[level + position][size-level-1];
    int32_t* bottom = &matrix[size-level-1][size - level - position - 1];
    int32_t* left = &matrix[size - level - position - 1][level];
    int32_t temp = *top;
    swap(temp, *right);
    swap(temp, *bottom);
    swap(temp, *left);
    swap(temp, *top);
}

void rotate(vector<vector<int32_t >>& matrix){
    auto n = matrix.size();
    auto levelsCount = ceil(n/2);
    cout << "levels count "<<levelsCount << endl;
    for(auto i = 0; i < levelsCount; i++){
        auto cellsOnLevel = n - i*2 - 1;
        cout << "cells on level " << cellsOnLevel << endl;
        for(auto j = 0; j < cellsOnLevel; j++){
            rotate(matrix, i, j);
        }
    }
}

vector<vector<int32_t >> createMatrix(int32_t size){
    vector<vector<int32_t >> matrix (size, vector<int32_t>(size));
    for(auto i = 0; i< size; i++){
        for(auto j = 0; j < size; j++){
            matrix[i][j] = i*size + j;
        }
    }
    return matrix;
}

int main(){
    try {
        auto matrix = createMatrix(5);
        cout << "rotating matrix : " << endl;
        print(matrix);
        cout << "result :" << endl;
        rotate(matrix);
        print(matrix);
    }
    catch (const std::exception &exc)
    {
        std::cerr << exc.what();
    }
}