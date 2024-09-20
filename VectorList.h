#pragma once
#include <iterator>
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

	/*empty -> true*/
	bool empty() const { return size() == 0; }

	/*size of all items in each vector*/
	size_t size() const
	{
		size_t cnt = 0;
		/*need to avoid: "Some redundant copy operations detected"*/
		for(const auto& vec : data_)
			cnt += vec.size();
		return cnt;
	}
private:
	ListT data_;

public:
	struct const_iterator
	{
		/*usings*/
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using value_type = const T;
		using pointer    = const T*;
		using reference  = const T&;

		using ItL = typename ListT::const_iterator;
		using ItV = typename VectT::const_iterator;

		/*fields*/
		ListT const* m_pData;
		ItL m_itL;
		ItV m_itV;

		/*ctors*/ 
		const_iterator() = default;
		const_iterator(const const_iterator&) = default;
		const_iterator(ItL itL, ItV itV, ListT const* pData = nullptr) 
			: m_itL(itL), m_itV(itV), m_pData(pData)
		{}
		/*operators*/
		reference operator*() const
		{
			return *m_itV;
		}
		pointer operator->() const
		{
			return &*m_itV;
		}

		bool operator==(const const_iterator& it) const
		{
			/*if i use (this->m_itV == it.m_itV),i get 
			"vector iterators incompatible on C++14"*/
			return this->m_itV._Ptr == it.m_itV._Ptr;
		}
		bool operator!=(const const_iterator& it) const
		{
			return !(it == *this);
		}

		/*prefix increment operator*/
		const_iterator& operator++()
		{
			/*is vec it valid*/
			m_itV++;
			if(m_itV != (*m_itL).cend())
				return *this;
			/*is list it valid*/
			if (m_itL != std::prev(m_pData->cend()))
			{
				m_itL++;
				m_itV = m_itL->cbegin();
			}
			return *this;
		}
		/*postfix increment operator*/
		const_iterator operator++(int)
		{
			auto tmp = *this;
			++(*this);
			return tmp;
		}

		/*prefix decrement operator*/
		const_iterator& operator--()
		{
			/*is vec valid*/
			if(m_itV != m_itL->cbegin())
			{
				m_itV--;
				return *this;
			}
			/*is list valid*/
			if(m_itL != m_pData->cbegin())
			{
				m_itL--;
				m_itV = std::prev(m_itL->cend());
			}
			return *this;
		}
		/*postfix decrement operator*/
		const_iterator operator--(int)
		{
			auto tmp = *this;
			--(*this);
			return tmp;
		}
	};

	using const_reverse_iterator = std::reverse_iterator<const_iterator>;
public:
	/*iterators*/
	const_iterator begin() const
	{
		if (empty())
			return const_iterator();

		auto ListBgn = data_.cbegin();
		auto VecBgn = ListBgn->cbegin();
		return const_iterator(ListBgn, VecBgn, &data_);
	}
	const_iterator end() const
	{
		if(empty())
			return const_iterator();
		auto LastLstElem = --(data_.cend());
		auto VecEnd = LastLstElem->cend();
		return const_iterator(LastLstElem, VecEnd, &data_);
	}
	/*reverse iterators*/
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}
};