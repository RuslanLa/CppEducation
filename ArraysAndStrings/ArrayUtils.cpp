//
// Created by Akvelon on 4/24/2019.
//

#include "ArrayUtils.h"
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int32_t >>& matrix){
    for(const auto& row: matrix){
        for(auto value: row){
            cout << value << " ";
        }
        cout << endl;
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