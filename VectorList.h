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

	/*empty - true*/
	bool empty() const { return size() == 0; }

	/*size of VectorList*/
	size_t size() const
	{
		size_t cnt = 0;
		for(auto it = data_.cbegin(); it != data_.cend(); it++)
			cnt += it->size();
		return cnt;
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
		ItL m_itL;
		ItV m_itV;

		/*ctors*/ 
		const_iterator() = default;
		const_iterator(const const_iterator&) = default;
		const_iterator(ItL itL, ItV itV, ListT const* pData = nullptr)
		{
			m_itL = itL;
			m_itV = itV;
			m_pData = pData;
		}
		/*operators*/
		reference operator*() const
		{
			return static_cast<reference>(*m_itV);
		}
		pointer operator->() const
		{
			return *m_itV;
		}
		/*prefix increment operator*/
		const_iterator& operator++()
		{
			/*is vec it valid*/
			m_itV++;
			if(m_itV != (*m_itL).cend())
				return *this;
			/*is list it valid*/
			m_itL++;
			if(m_itL != m_pData->cend())
			{
				m_itV = m_itL->cbegin();
				return *this;
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
			if(m_itV != m_itL->cbegin())
			{
				m_itV--;
				return *this;
			}

			if(m_itL != m_pData->cbegin())
			{
				m_itL--;
				m_itV = --(m_itL->cend());
				return *this;
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
		bool operator==(const const_iterator& it) const
		{
			return it.m_itV == m_itV;
		}
		bool operator!=(const const_iterator& it) const
		{
			return !(it == *this);
		}
	};
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;
public:

	/*methods*/
	const_iterator begin() const
	{
		if (data_.empty())
			return const_iterator();

		auto ListBgn = data_.cbegin();
		auto VecBgn = ListBgn->cbegin();
		return const_iterator(ListBgn, VecBgn, &data_);
	}
	const_iterator end() const
	{
		if(data_.empty())
			return const_iterator();
		auto LastLstElem = --(data_.cend());
		auto VecEnd = LastLstElem->cend();
		return const_iterator(LastLstElem, VecEnd, &data_);
	}
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}
};