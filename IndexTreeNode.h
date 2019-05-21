#pragma once
#include "Structs.h"
class IndexEntryNode
{
	friend class IndexEntryTree;
	IndexEntry a;
	IndexEntryNode* left;
	IndexEntryNode* right;
public:
	IndexEntryNode();
	IndexEntryNode(int acctID, int recNum, IndexEntryNode* left, IndexEntryNode* right);
	/*void setIE(IndexEntry a);*/
	void setRI(int recID);
	void setSI(int StuID);
	int getRI();
	int getSI();
	~IndexEntryNode();
};

