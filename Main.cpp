#include <iostream>
#include "cnodedynamic.h"
#include "ctreedynamic.h"
void dynamicTreeTest()
{
	CTreeDynamic<int> tree;
	CNodeDynamic<int>* root = tree.getRoot();

	root->addNewChild();
	root->addNewChild();

	root->getChild(0)->setValue(1);
	root->getChild(1)->setValue(2);

	root->getChild(0)->addNewChild();
	root->getChild(0)->addNewChild();

	root->getChild(0)->getChild(0)->setValue(11);
	root->getChild(0)->getChild(1)->setValue(12);

	root->getChild(1)->addNewChild();
	root->getChild(1)->addNewChild();

	root->getChild(1)->getChild(0)->setValue(21);
	root->getChild(1)->getChild(1)->setValue(22);

	tree.printPrettyTree();
}

void labModTest()
{
	CTreeDynamic<int> tree;
	CNodeDynamic<int>* root = tree.getRoot();

	root->setValue(1);

	root->addNewChild();
	root->addNewChild();

	root->getChild(0)->setValue(5);
	root->getChild(1)->setValue(8);

	root->getChild(0)->addNewChild();
	root->getChild(0)->addNewChild();

	root->getChild(0)->getChild(0)->setValue(11);
	root->getChild(0)->getChild(1)->setValue(2);

	root->getChild(0)->getChild(1)->addNewChild();

	root->getChild(0)->getChild(1)->getChild(0)->setValue(3);

	tree.printPrettyTree();

}

int main()
{
	labModTest();
	system("pause");
	return 0;
}