#pragma once
class insertion_sort_enumerator
{
protected:
	/**
	* \brief position in direct traversing
	*/
	size_t current_direct_position_ = 0;
	/**
	* \brief position in indirect traversing
	*/
	size_t current_indirect_position_ = 0;

	size_t max_index_ = 0;

	vector<int32_t>& _vector;
public:
	virtual ~insertion_sort_enumerator() = default;
	virtual bool next();
	int32_t curElement;
	int32_t inderectTraversingElement() const;
	virtual bool previous();
	virtual void set_previous_to_inderect() const;
	void set_direct_to_inderect() const;
	insertion_sort_enumerator(vector<int32_t>& vector);
};
