#pragma once

#include "CNodeDynamic.h"

template<typename T>
class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic<T>* getRoot() { return root; };
	T* sum();
	void printTree();
	void printPrettyTree();
	bool moveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode);
private:
	CNodeDynamic<T>* root;
};

template<typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	root = new CNodeDynamic<T>();
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete root;
}

template<typename T>
T* CTreeDynamic<T>::sum()
{
	T* ret = new T;
	*ret = root->sumAllBelow();
	return ret;
}

template<typename T>
void CTreeDynamic<T>::printTree()
{
	root->printAllBelow();
}

template<typename T>
void CTreeDynamic<T>::printPrettyTree()
{
	root->prettyPrintBelow(0);
}

template<typename T>
bool CTreeDynamic<T>::moveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode)
{
	if (parentNode == NULL || newChildNode == NULL)
		return false;

	std::vector<CNodeDynamic<T>*>* children = newChildNode->getParent()->getChildren();
	int childrenSize = children->size();
	bool found = false;
	for (int i = 0; i < childrenSize && !found; ++i)
	{
		if ((*children)[i] == newChildNode)
		{
			children->erase(children->begin() + i);
			found = true;
		}
	}
	parentNode->addNewChild(newChildNode);

	return true;
}
