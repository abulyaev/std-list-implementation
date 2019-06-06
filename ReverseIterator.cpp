#include <iostream>
#ifdef Reverses
#else
#define Reverses 120
#include "List.h"
#include "Node.h"
#include "Iterator.h"
using namespace std;
template<typename T>
ReverseIterator<T>::ReverseIterator()
{
m_revPtr = NULL;
}
template<typename T>
ReverseIterator<T>::ReverseIterator(Node<T> *p_ptr)
{
m_revPtr = p_ptr;
}
template<typename T>
ReverseIterator<T>::ReverseIterator(const ReverseIterator<T> &p_iter)
{
m_revPtr = p_iter.m_revPtr;
}
/*template<typename T>
NodeMy<T>* ReverseIterator<T>::getRevPtr()
{
return m_revPtr;
}*/
template<typename T>
T& ReverseIterator<T>:: operator* ()
{
if (m_revPtr != NULL) return m_revPtr->m_node;
else cout << "NULL iterator" << endl;
}
template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator ++()
{
if ((this->m_revPtr != NULL) && (this->m_revPtr->m_prev != 0))
	m_revPtr = m_revPtr->m_prev;
return *this;
}
template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator --()
{
if ((this->m_revPtr != NULL) && (this->m_revPtr->m_next != 0)) 
	m_revPtr = m_revPtr->m_next;
return *this;
}
template<typename T>
ReverseIterator<T> ReverseIterator<T>:: operator ++(int)
{
ReverseIterator<T> l_temp(*this);
if ((this->m_revPtr != NULL) && (this->m_revPtr->m_prev != 0)) 
	m_revPtr = m_revPtr->m_prev;
return l_temp;
}
template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator --(int)
{
ReverseIterator<T> l_temp(*this);
if ((this->m_revPtr != NULL) && (this->m_revPtr->m_next != 0))
	m_revPtr = m_revPtr->m_next;
return l_temp;
}

template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator = (ReverseIterator<T>& p_iter)
{
	m_revPtr = p_iter.m_revPtr;
	return (*this);
}


#endif