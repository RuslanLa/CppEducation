#pragma once
class sorter
{
public:
	virtual ~sorter() = default;
	virtual void sort(vector<int32_t>& arr);
	virtual void descSort(std::vector<int32_t>& arr);
};
