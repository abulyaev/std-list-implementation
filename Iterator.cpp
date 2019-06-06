#include <iostream>
#ifdef Iterators
#else
#define Iterators 140
#include "List.h"
#include "Node.h"
#include "Iterator.h"
#include "ConstIterator.h"
#include "ConstReverseIterator.h"
#include "ReverseIterator.h"
using namespace std;
template<typename T>
Iterator<T>::Iterator()
{
	m_ptr = NULL;
}
template<typename T>
Iterator<T>::Iterator(const Iterator<T>& p_iter)
{
	m_ptr = p_iter.m_ptr;
}
template<typename T>
Iterator<T>::Iterator(Node<T> *p_ptr)
{
	m_ptr = p_ptr;
}
template<typename T>
Node<T>* Iterator<T>::getPtr()
{
	return m_ptr;
}
template<typename T>
T& Iterator<T>:: operator* ()
{
	if (m_ptr != NULL) return m_ptr->m_node;
	/*else
	{
		cout << "NULL iterator" << endl;
		return NULL;
	}*/
}
template<typename T>
Iterator<T>& Iterator<T>::operator ++()
{
	if ((this->m_ptr != NULL) && (this->m_ptr->m_next != 0))
		m_ptr = m_ptr->m_next;
	return *this;
}
template<typename T>
Iterator<T>& Iterator<T>::operator --()
{
	if ((this->m_ptr != NULL) && (this->m_ptr->m_prev != 0)) 
		m_ptr = m_ptr->m_prev;
	return *this;
}
template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator l_tmp(*this);
	 if ((this->m_ptr != NULL) && (this->m_ptr->m_next != 0)) 
		 m_ptr = m_ptr->m_next;
	return l_tmp;
}
template<typename T>
Iterator<T> Iterator<T>::operator --(int)
{
	Iterator<T> l_temp(*this);
	if ((this->m_ptr != NULL) && (this->m_ptr->m_prev != 0))
		m_ptr = m_ptr->m_prev;
	return l_temp;
}
template<typename T>
Iterator<T>& Iterator<T>::operator = (Iterator& p_iter)
{
	m_ptr = p_iter.m_ptr;
	return (*this);
}

//template<typename T>
//friend bool operator == (const Iterator<T>& p_first, const Iterator<T>& p_second)
//{
//	return p_first.m_ptr == p_second.m_ptr;
//}
//template<typename T>
//bool operator != (Iterator<T>& p_first, Iterator<T>& p_second)
//{
//	return p_first.m_ptr != p_second.m_ptr;
//}

#endif