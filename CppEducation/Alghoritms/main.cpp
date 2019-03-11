#pragma once
#include <vector>
#include <InsertionSorter.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	cout << "Hello, C++" << endl;
	InsertionSorter* sorter = new InsertionSorter;
	vector< int32_t > vector;
	vector.push_back(10);
	vector.push_back(40);
	vector.push_back(35);
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(1);
	sorter->sort(vector);
	for(size_t i=0; i < vector.size(); i++){
		cout <<  vector[i] << " ";
	}
	getchar();
	return 0;
}
