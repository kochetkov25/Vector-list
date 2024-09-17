#pragma once
#include <vector>
#include <list>

template<class T>
class VectorList
{
private:
	using VectT = std::vector<T>;
	using ListT = std::list<VectT>;

public:
	using value_type = const T;

	VectorList() = default;
	VectorList(VectorList const&) = default;
	VectorList(VectorList&&)	  = default;

	VectorList& operator=(VectorList&&)		 = default;
	VectorList& operator=(VectorList const&) = default;

	/*fill VectorList*/
	template<class It>
	void append(It p, It q)
	{
		if (p != q)
			data_.push_back(VectT(p, q));
	}

	/*empty - true*/
	bool empty() const { return size() == 0; }

	/*size of VectorList*/
	size_t size() const
	{
		size_t size = 0;
		for (const auto& vec : data_)
			for (const auto& el : vec)
				size++;
		return size;
	}
private:
	ListT data_;

private:
	struct const_iterator
	{
		/*usings*/
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = void;
		using value_type = const T;
		using pointer = const T*;
		using reference = const T&;

		using ItL = typename ListT::const_iterator;
		using ItV = typename VectT::const_iterator;

		/*fields*/
		ListT const* m_pData;
		pointer m_ptr;
		ItL m_itL;
		ItV m_itV;

		/*ctors*/ 
		const_iterator() = default;
		const_iterator(const const_iterator&) = default;
		const_iterator(ItL itL, ItV itV, ListT const* pData, pointer ptr)
		{
			m_itL = itL;
			m_itV = itV;
			m_pData = pData;
			m_ptr = ptr;
		}
	};
public:

	/*methods*/
	const_iterator begin()
	{
		if (data_.empty())
			return const_iterator();

		//auto it = data_.begin()->begin();

		return const_iterator(data_.begin(), data_.begin()->begin(), &data_, &(*(data_.begin()->begin())));
	}
};