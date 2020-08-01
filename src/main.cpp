#include<iostream>
#include <string>
#include "stdio.h"
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/*
	This file shows you how to use implemented custom list.
*/

class x {
public:
	int a;
	x() {}
	x(int u) : a(u) {}
};

bool operator >(const x&c, const x&b) {
	return c.a < b.a;
}

int main()
{
	List<int> lll;
	lll.insert(2);
	lll.insert(1);
	lll.insert(3);
	lll.insert(4);
	lll.insert(27);
	Iterator<int> it1 = lll.begin();
	Iterator<int> it2 = lll.end();
	List<int>  lll2(3, 4);
	lll2.insert(1024);
	lll2.swap(lll);
		
	for (List<int>::iterator it = lll2.begin(); it != lll2.end(); ++it) {
		std::cout << (*it) << std::endl;
	}

	List<x> lx;
	lx.insert(4);
	lx.insert(5);
	lx.insert(7);

	for (List<x>::iterator it = lx.begin(); it != lx.end(); ++it) {
		std::cout << (*it).a << std::endl;
	}

	List<int> l_list;
	l_list.insert(2);
	Iterator<int> l_iter1= l_list.begin();
	Iterator<int> l_iter2(l_iter1);
	ConstReverseIterator<int> _crit = l_list.crbegin();

	l_list.insert(rand()%256);
	l_list.insert(rand()%256);
	l_list.insert(rand()%256);
	l_list.insert(rand()%256);
	l_list.insert(rand()%256);
	l_list.insert(rand()%256);

	for (ConstReverseIterator<int> cr = l_list.crbegin(); cr != l_list.crend(); ++cr) {
		std::cout << *cr << std::endl;
	}

	List<std::wstring> lst;	
	List<std::wstring>::iterator it;
	List<std::wstring>::constIterator cit;
	List<std::wstring>::constReverseIterator crit;
	
	lst.insert(L"abc");
	lst.insert(L"zzz");
	lst.insert(L"xcd");
	lst.insert(L"ytfyg");
	lst.insert(L"aaa");

	for (List<std::wstring>::reverseIterator r = lst.rbegin(); r != lst.rend(); ++r) {
		std::wcout << *r << " ";
	}

	std::cout << lst.size() << std::endl;
	std::cout << lst.empty() << std::endl;
	
	List<int> l_newList;
	if (l_newList.size() == 0) cout << "empty" << endl;
	
	system("pause");
	return 0;
}
