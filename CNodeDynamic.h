#pragma once

#include <vector>
#include <iostream>

template<typename T>
class CNodeDynamic
{
public:
	CNodeDynamic() { parent = NULL; };
	~CNodeDynamic();

	void setValue(T newVal) { val = newVal; };

	int getChildrenNumber() { return children.size(); }
	void addNewChild();
	void addNewChild(CNodeDynamic* child);
	CNodeDynamic* getChild(int childOffset);
	CNodeDynamic* getParent();
	void setParent(CNodeDynamic* newParent);
	std::vector<CNodeDynamic*>* getChildren() { return &children; };

	void print() { std::cout << " " << val; }
	void prettyPrintBelow(int depth);
	void printAllBelow();
	T sumAllBelow();
	void printUp();

private:
	std::vector<CNodeDynamic*> children;
	CNodeDynamic* parent;
	T val;
};

template<typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
	int childrenSize = children.size();
	for (int i = 0; i < childrenSize; ++i)
	{
		delete children[i];
	}
}

template<typename T>
void CNodeDynamic<T>::addNewChild()
{
	addNewChild(new CNodeDynamic);
}

template<typename T>
void CNodeDynamic<T>::addNewChild(CNodeDynamic<T>* child)
{
	child->parent = this;
	children.push_back(child);
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::getChild(int childOffset)
{
	if (childOffset < 0 || childOffset >= getChildrenNumber())
		return NULL;
	return children[childOffset];
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::getParent()
{
	return this->parent;
}

template<typename T>
void CNodeDynamic<T>::setParent(CNodeDynamic<T>* newParent)
{
	this->parent = newParent;
}

template<typename T>
void CNodeDynamic<T>::prettyPrintBelow(int depth)
{
	for (int i = 0; i < depth; ++i)
	{
		if (i > 0) std::cout << "   ";
		std::cout << "|";
	}
	if (depth > 0) std::cout << "---";
	std::cout << this->val << '\n';
	int n = getChildrenNumber();
	for (int i = 0; i < n; ++i)
	{
		children[i]->prettyPrintBelow(depth + 1);
	}

}

template<typename T>
void CNodeDynamic<T>::printAllBelow()
{
	print();
	int n = getChildrenNumber();
	for (int i = 0; i < n; ++i)
	{
		children[i]->printAllBelow();
	}
}

template<typename T>
T CNodeDynamic<T>::sumAllBelow()
{
	int ret = this->val;
	int n = getChildrenNumber();
	for (int i = 0; i < n; ++i)
	{
		ret += children[i]->sumAllBelow();
	}
	return ret;
}

template<typename T>
void CNodeDynamic<T>::printUp()
{
	print();
	if (this->parent != NULL)
	{
		this->parent->printUp();
	}
}