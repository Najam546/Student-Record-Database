#pragma once
#include "IndexTreeNode.h"
class IndexEntryTree
{
	void destructor(IndexEntryNode* stree);
	IndexEntryNode* root;
public:
	IndexEntryTree();
	bool insert(IndexEntryNode a);
	void display(IndexEntryNode* root);
	void display();
	int search(int StuID);
	~IndexEntryTree();
};

