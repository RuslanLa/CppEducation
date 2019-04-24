
#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>
#include "ArrayUtils.h"

using namespace std;

/*
 * Rotate Matrix: Given an image represented by an NxN matrix,
 * where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
 * Can you do this in place?
 */

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

    return 0;
}