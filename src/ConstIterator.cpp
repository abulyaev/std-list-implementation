#include <iostream>
#ifdef ConstIterators 
#else
#define ConstIterators 150
#include "List.h"
#include "Node.h"
#include "Iterator.h"
using namespace std;
template<typename T>
ConstIterator<T>::ConstIterator()
{
m_cptr = NULL;
}
template<typename T>
ConstIterator<T>::ConstIterator(Node<T> *p_ptr)
{
m_cptr = p_ptr;
}
template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator<T> &p_iter)
{
m_cptr = p_iter.m_cptr;
}
/*template<typename T>
const NodeMy<T>* ConstIterator<T>::getcPtr()
{
return m_cptr;
}*/
template<typename T>
const T& ConstIterator<T>::operator* ()
{
if (m_cptr != NULL)
	return m_cptr->m_node;
}
template<typename T>
ConstIterator<T>& ConstIterator<T>::operator ++()
{
if ((this->m_cptr != NULL) && (this->m_cptr->m_next != 0))
	m_cptr = m_cptr->m_next;
return *this;
}
template<typename T>
ConstIterator<T>& ConstIterator<T>::operator --()
{
if ((this->m_cptr != NULL) && (this->m_cptr->m_prev != 0))
	m_cptr = m_cptr->m_prev;
return *this;
}
template<typename T>
ConstIterator<T> ConstIterator<T>::operator ++(int)
{
ConstIterator<T> l_temp(*this);
if ((this->m_cptr != NULL) && (this->m_cptr->m_next != 0)) 
	m_cptr = m_cptr->m_next;
return l_temp;
}
template<typename T>
ConstIterator<T> ConstIterator<T>:: operator --(int)
{
ConstIterator<T> l_temp(*this);
if((this->m_cptr != NULL) && (this->m_cptr->m_prev != 0))
	m_cptr = m_cptr->m_prev;
return l_temp;
}

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator = (ConstIterator<T>& p_citer)
{
m_cptr = p_citer.m_cptr;
return (*this);
}

#endif