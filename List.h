#pragma once
#ifndef Listh
#define Listh 123
template <typename T> class Node; // forward declare
template <typename T> class List; // forward declare
template <typename T> class ConstIterator;
template <typename T> class ConstReverseIterator;
template <typename T> class Iterator;
template <typename T> class ReverseIterator;
#include "Node.h"
#include "Iterator.h"



template <typename T>
class List
{
	
private:
	int m_count;
	Node<T>* m_first;
	Node<T>* m_last;

public:
	typedef Iterator<T> iterator;
	typedef ReverseIterator<T> reverseIterator;
	typedef ConstIterator<T> constIterator;
	typedef ConstReverseIterator<T> constReverseIterator;
	typedef T value_type;
	typedef int size_type;

	List(const List&);
	List<T>& operator=(const List&);
	List(int p_count, T p_data)
	{
		(this)->List<T>::List<T>();
		for (int i = 0; i < p_count; i++)
			this->insert(p_data);
	}
	List(Iterator<T> p_begin, Iterator<T> p_end)
	{
		(this)->List<T>::List<T>();
		while (p_begin != p_end)
		{
			
			this->insert(*p_begin);
			p_begin++;
		}
	}
	void swap(List<T> &);
	int size() const;
	void insert(T);
	int clear(int);
	void clear_memory();
	bool empty();
	Iterator<T> begin()const;
	Iterator<T> end()const;
	ReverseIterator<T> rbegin()const;
	ReverseIterator<T> rend()const;
	ConstIterator<T> cbegin()const;
	ConstIterator<T> cend()const;
	ConstReverseIterator<T> crbegin()const;
	ConstReverseIterator<T> crend()const;
	bool erase(T);
	bool erase(T, T);
	void erase(Iterator<T> p_iter);
	void erase(Iterator<T>p_iterBegin, Iterator<T>p_iterEnd);
	T& front()
	{
		return this->m_first->m_next->m_node;
	}
	T& back()
	{
		return this->m_last->m_prev->m_node;
	}
	void pop_front();
	void pop_back();
	const bool operator == (const List<T>&p_listSecond)
	{
		if (this->size() != p_listSecond.size())
			return 0;

		Iterator<T> l_iterFirst = this->begin();
		Iterator<T> l_iterSecond = p_listSecond.begin();
		for ( ; (l_iterFirst !=this->end()) && (l_iterSecond != p_listSecond.end()) && (*l_iterFirst == *l_iterSecond); l_iterFirst++, l_iterSecond++);
		return (l_iterSecond == p_listSecond.end() && l_iterFirst == this->end());
	}
	const bool operator != ( const List<T>&p_listSecond)
	{
		return !(*this == p_listSecond);
	}
	bool operator < (const List<T>&);
	bool operator > (const List<T>&);
	bool operator <=(const List<T>&);
	bool operator >=(const List<T>&);
	int max_size();
	List();
	~List();
};

#include "List.cpp"

#endif




