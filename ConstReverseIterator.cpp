#include <iostream>
#ifdef ConstRiIterators
#else
#define ConstRiIterators 160

#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;
template<typename T>
ConstReverseIterator<T>::ConstReverseIterator()
{
m_crptr = NULL;
}
template<typename T>
ConstReverseIterator<T>::ConstReverseIterator(Node<T> *p_ptr)
{
m_crptr = p_ptr;
}
template<typename T>
ConstReverseIterator<T>::ConstReverseIterator(const ConstReverseIterator<T> &p_iter)
{
m_crptr = p_iter.m_crptr;
}
/*template<typename T>
const NodeMy<T>* ConstReverseIterator<T>::getCRPtr()
{
return m_crptr;
}*/
template<typename T>
const T& ConstReverseIterator<T>::operator* ()
{
if (m_crptr != NULL) return m_crptr->m_node;
}
template<typename T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator ++()
{
if ((this->m_crptr != NULL) && (this->m_crptr->m_prev != 0))
	m_crptr = m_crptr->m_prev;
return *this;
}
template<typename T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator --()
{
if ((this->m_crptr != NULL) && (this->m_crptr->m_next != 0))
	m_crptr = m_crptr->m_next;
return *this;
}
template<typename T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator ++(int)
{
ConstReverseIterator<T> l_temp(*this);
if ((this->m_crptr != NULL) && (this->m_crptr->m_prev != 0)) 
	m_crptr = m_crptr->m_prev;
return l_temp;
}
template<typename T>
ConstReverseIterator<T> ConstReverseIterator<T>::operator --(int)
{
ConstReverseIterator<T> l_temp(*this);
if ((this->m_crptr != NULL) && (this->m_crptr->m_next != 0)) 
	m_crptr = m_crptr->m_next;
return l_temp;
}
template<typename T>
ConstReverseIterator<T>& ConstReverseIterator<T>::operator = (ConstReverseIterator<T>& p_iter)
{
m_crptr = p_iter.m_crptr;
return *this;
}


#endif