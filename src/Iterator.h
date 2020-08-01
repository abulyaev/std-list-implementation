#pragma once

#include "List.h"
#include "Node.h"

//================================ITERATOR==========================================================================

template<typename T>
class Iterator
{
private:
	Node<T>* m_ptr;
public:
	Iterator();
	Iterator(Node<T>*);
	Iterator(const Iterator<T> &);
	Node<T>* getPtr();
	T& operator* ();
	Iterator<T>& operator ++();
	Iterator<T>& operator --();
	Iterator<T> operator ++(int);
	Iterator<T> operator --(int);
	const bool operator == (const Iterator<T>& p_second)
	{
		return this->m_ptr == p_second.m_ptr;
	}
	const bool operator != ( Iterator<T>& p_second)
	{
		return !(*this == p_second);
	}

	Iterator<T>& operator = (Iterator<T>& );
};
#include "Iterator.cpp"

//================================ITERATOR END==========================================================================

//================================CONST ITERATOR========================================================================

#ifndef ConstIteratorh
#define ConstIteratorh 123

template <typename T>
class ConstIterator
{
private:
	const Node<T>* m_cptr;
public:
	ConstIterator();
	ConstIterator(Node<T> *);
	ConstIterator(const ConstIterator<T> &);
	const T& operator* ();
	ConstIterator<T>& operator ++();
	ConstIterator<T>& operator --();
	ConstIterator<T> operator ++(int);
	ConstIterator<T> operator --(int);
	const bool operator == (const ConstIterator<T>& p_second)
	{
		return this->m_cptr == p_second.m_cptr;
	}
	const bool operator != (const ConstIterator<T>& p_second)
	{
		return !(*this == p_second);
	}
	ConstIterator<T>& operator = (ConstIterator<T>&);
};
#include "ConstIterator.cpp"
#endif

//================================CONST ITERATOR END====================================================================

//================================CONST REVERSE ITERATOR================================================================

#ifndef ConstRiIteratorh
#define ConstRiITeratorh 124
template <typename T>
class ConstReverseIterator
{
private:
	const Node<T>* m_crptr;
public:
	ConstReverseIterator();
	ConstReverseIterator(Node<T> *);
	ConstReverseIterator(const ConstReverseIterator<T> &);
	const T& operator* ();
	ConstReverseIterator<T>& operator ++();
	ConstReverseIterator<T>& operator --();
	ConstReverseIterator<T> operator ++(int);
	ConstReverseIterator<T> operator --(int);
	const bool operator == (const ConstReverseIterator<T>& p_second)
	{
		return this->m_crptr == p_second.m_crptr;
	}
	const bool operator != (const ConstReverseIterator<T>& p_second)
	{
		return !(*this == p_second);
	}
	ConstReverseIterator<T>& operator = (ConstReverseIterator<T>&);

};
#include "ConstReverseIterator.cpp"
#endif

//================================CONST REVERSE ITERATOR================================================================

//================================REVERSE ITERATOR======================================================================

#ifndef Reverseh
#define Reverseh 123

template <typename T>
class ReverseIterator
{
private:
	Node<T>* m_revPtr;
public:
	ReverseIterator();
	ReverseIterator(Node<T> *);
	ReverseIterator(const ReverseIterator<T> &);
	T& operator* ();
	ReverseIterator<T>& operator ++();
	ReverseIterator<T>& operator --();
	ReverseIterator<T> operator ++(int);
	ReverseIterator<T> operator --(int);
	const bool operator == (const ReverseIterator<T>& p_second)
	{
		return this->m_revPtr == p_second.m_revPtr;
	}
	const bool operator != (const ReverseIterator<T>& p_second)
	{
		return !(*this == p_second.m_revPtr);
	}
	ReverseIterator<T>& operator = (ReverseIterator<T>&);
};

#include "ReverseIterator.cpp"
#endif

//================================REVERSE ITERATOR END==================================================================