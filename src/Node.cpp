#include <iostream>
#ifndef Nodes

#define Nodes 100
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;
template<typename T>
Node<T>::Node()
{
	m_node;
	m_next = NULL;
	m_prev = NULL;
}
template<typename T>
Node<T>::Node(const T data)
{
	m_node = data;
	m_next = NULL;
	m_prev = NULL;
}
template<typename T>
Node<T>::~Node()
{
}
#endif
