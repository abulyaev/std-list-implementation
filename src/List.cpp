#include <iostream>
#ifdef Listes
#else 
#define Listes 130
#include "List.h"
#include "Node.h"
#include "Iterator.h"

#define MAX_SIZE 1000
using namespace std;
template<typename T>
List<T>::List()
{
		m_first = new Node<T>();
		m_last = new Node<T>();
		m_first->m_next = m_last;
		m_first->m_prev = NULL;
		m_last->m_next = NULL;
		m_last->m_prev = m_first;
		this->m_count = 0;
}
template<typename T>
List<T>::~List()
{
	Node<T>* l_ptr;
	this->m_count = 0;
	while (m_first != NULL)
	{
		l_ptr = m_first;
		m_first = m_first->m_next;
		delete l_ptr;
	}
}


template<typename T>
void List<T>::swap(List<T> &p_list)
{
	Node<T>* l_firstTemp, *l_lastTemp;
	l_firstTemp = m_first;
	l_lastTemp = m_last;
	m_first = p_list.m_first;
	m_last = p_list.m_last;
	p_list.m_first = l_firstTemp;
	p_list.m_last = l_lastTemp;
}

template<typename T>
int List<T>::size() const
{
	return this->m_count;
}

template<typename T>
void List<T>::insert(T p_node) //with sorting
{
	Node<T> *to_add = new Node<T>(p_node);
	Node<T> *buf = m_first->m_next;
	while (buf != m_last && to_add->m_node > buf->m_node)
	{
		buf = buf->m_next;
	}
	buf->m_prev->m_next = to_add;
	to_add->m_next = buf;
	to_add->m_prev = buf->m_prev;
	buf->m_prev = to_add;
	m_count++;
}
template<typename T>
int List<T>::clear(int p_num)
{
	if (p_num > m_count) return -1;
	Node<T> *buf = m_first;
	for (int i = 1; i <= p_num; i++)
		buf = buf->m_next;
	buf->m_prev->m_next = buf->m_next;
	buf->m_next->m_prev = buf->m_prev;
	m_count--;
	return m_count;
}
template<typename T>
void List<T>::clear_memory()
{
	Node<T> *buf = m_first;
	Node<T> *to_del = m_first;
	while (to_del != m_last)
	{
		buf = buf->m_next;
		delete to_del;
		to_del = buf;
	}
	m_count = 0;
}
template<typename T>
bool List<T>::empty()
{
	if (begin() == end())
		return 1;
	else return 0;
}
template<typename T>
Iterator<T> List<T>::begin()const
{
	return Iterator<T>(m_first->m_next);
}
template<typename T>
Iterator<T> List<T>::end()const
{
	return Iterator<T>(m_last);
}
template<typename T>
ReverseIterator<T> List<T>::rbegin()const
{
	return ReverseIterator<T>(m_last->m_prev);
}
template<typename T>
ReverseIterator<T> List<T>::rend()const
{
	return ReverseIterator<T>(m_first);
}


template<typename T>
bool List<T>::erase(T p_data)
{
	Node<T>* l_temp;
	Node<T> *l_iter = m_first->m_next;
	if (this->m_count == 0) { return 0; }
	while ((l_iter->m_node != p_data) && (l_iter->m_next != m_last))
		l_iter = l_iter->m_next;
	if (l_iter->m_node == p_data)
	{
		l_temp = l_iter;
		l_iter->m_next->m_prev = l_temp->m_prev;
		l_iter->m_prev->m_next = l_temp->m_next;
		delete l_iter;
		this->m_count--;
		return 1;
	}
	return 0;
}
template<typename T>
bool List<T>::erase(T p_dataFirst,T p_dataSecond)
{
	Node<T>* l_temp;
	Node<T> *l_iter = m_first->m_next;
	if (this->m_count == 0) { return 0; }
	while ((l_iter->m_node < p_dataFirst) && (l_iter->m_next != m_last))
		l_iter = l_iter->m_next;
	while ((l_iter!=m_last)&&l_iter->m_node < p_dataSecond)
	{
		l_temp = l_iter;
		l_iter->m_next->m_prev = l_temp->m_prev;
		l_iter->m_prev->m_next = l_temp->m_next;
		l_temp = l_iter->m_next;
		delete l_iter;
		l_iter = l_temp;
		this->m_count--;
	}


	return 1;
}
template<typename T>
void List<T>::erase(Iterator<T> p_iter)
{
	
	Node<T>& l_iter = *p_iter.getPtr();
	Node<T> * l_temp = &l_iter;
	l_iter.m_next->m_prev = l_temp->m_prev;
	l_iter.m_prev->m_next = l_temp->m_next;
	this->m_count--;
	delete l_temp;
}
template<typename T>
void List<T>:: erase(Iterator<T> p_iterBegin, Iterator<T> p_iterEnd)
{
	Iterator<T> l_iter = p_iterBegin;
	Iterator<T> l_temp = l_iter;
	while (l_iter != p_iterEnd)
	{
		l_temp++;
		this->erase(l_iter);
		l_iter = l_temp;

	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* buf;
	buf = m_first->m_next;
	m_first->m_next = buf->m_next;
	buf->m_next->m_prev = m_first;
}
template<typename T>
void List<T>::pop_back()
{
	Node<T>* buf;
	buf = m_last->m_prev;
	m_last->m_prev = buf->m_prev;
	buf->m_prev->m_next = m_last;
}

template <typename T>
int List<T>:: max_size()
{
	return MAX_SIZE;
}


template <typename T>
List<T>::List(const List<T>& p_list)
{
	this->List<T>::List<T>();
	Iterator<T> l_iterFirst = p_list.begin();
	for (; (l_iterFirst != p_list.end()); l_iterFirst++)
	{
		this->insert(*l_iterFirst);
	}
}
template <typename T>
List<T>& List<T>::operator=(const List<T>& p_list)
{
	if (this != &p_list)
	{
		(this)->~List<T>();
		new (this) List<T>(p_list);
		return *this;
	}
	else
		return *this;
}
template <typename T>
bool List<T>:: operator <(const List<T>& p_list)
{
	Iterator<T> l_iterFirst =this->begin();
	Iterator<T> l_iterSecond = p_list.begin();
	for (; (l_iterFirst != this->end()) && (l_iterSecond != p_list.end()) && (*l_iterFirst == *l_iterSecond); l_iterFirst++, l_iterSecond++)
		if (*l_iterFirst < *l_iterSecond)
			return 1;
		else
			if (*l_iterFirst > *l_iterSecond)
			return 0;
	return 0;
}
template <typename T>
bool List<T>:: operator >(const List<T>& p_list)
{
	return p_list < *this;
}
template <typename T>
bool List<T>:: operator >=(const List<T>& p_list)
{
	return !(*this > p_list);
}
template <typename T>
bool List<T>:: operator <=(const List<T>& p_list)
{
	return !(*this < p_list);
}
template <typename T>
ConstIterator<T> List<T>::cbegin()const
{
	return ConstIterator<T>(m_first->m_next);
}
template <typename T>
ConstIterator<T> List<T>::cend()const
{
	return ConstIterator<T>(m_last);
}
template <typename T>
ConstReverseIterator<T>List<T>::crbegin()const
{
	return ConstReverseIterator<T>(m_last->m_prev);
}
template <typename T>
ConstReverseIterator<T> List<T>:: crend()const
{
	return ConstReverseIterator<T>(m_first);
}


#endif