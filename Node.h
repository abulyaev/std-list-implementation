#pragma once
#ifndef Nodeh
#define Nodeh 123

#include "Iterator.h"
#include "ConstReverseIterator.h"
#include "ReverseIterator.h"
#include "List.h"
#include "ConstIterator.h"

template <typename T>
class Node
{
public:
	T m_node;
	Node<T>* m_next; 
	Node<T>* m_prev; 
	Node();
	Node(const T);
	~Node(); 

};
#include "Node.cpp"
#endif