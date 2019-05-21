#include "IndexEntryTree.h"
#include <iostream>
using namespace std;

IndexEntryTree::IndexEntryTree()
{
	root = nullptr;
}

bool IndexEntryTree::insert(IndexEntryNode a)
{
	IndexEntryNode* ptr = new IndexEntryNode(a.getSI(),a.getRI(), nullptr, nullptr);
	IndexEntryNode* pre = nullptr;
	IndexEntryNode* cur = root;
	while (cur != nullptr)
	{
		pre = cur;
		if (cur->a.acctID > a.getSI())
			cur = cur->left;
		else if (cur->a.acctID == a.getSI())
			return false;
		else
			cur = cur->right;
	}
	if (pre == nullptr)
		root = ptr;
	else if (pre->left == nullptr && pre->a.acctID > a.getSI())
		pre->left = ptr;
	else if (pre->right == nullptr && pre->a.acctID < a.getSI())
		pre->right = ptr;
}

void IndexEntryTree::display(IndexEntryNode* root)
{
	
	if (root != nullptr)
	{
		display(root->left);
		cout <<root->getSI()<<  endl;
		display(root->right);
	}
}

void IndexEntryTree::display()
{
	display(root);
}

int IndexEntryTree::search(int StuID)
{
	IndexEntryNode* cur = root;
	while (cur != nullptr)
	{
		if (cur->a.acctID > StuID)
			cur = cur->left;
		else if (cur->a.acctID == StuID)
		{
			//cout << cur->a.acctID << " " << cur->name << " " << cur->balance << endl;
			return cur->a.recNum;
		}
		else
			cur = cur->right;
	}
	//cout << "Data Not Found\n";
	return -1;
}

void IndexEntryTree::destructor(IndexEntryNode* stree)
{
	if (stree != nullptr)
	{
		destructor(stree->left);
		destructor(stree->right);
		delete stree;
	}
}


IndexEntryTree::~IndexEntryTree()
{
	destructor(root);
}
