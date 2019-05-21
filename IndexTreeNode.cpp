#include "IndexTreeNode.h"



IndexEntryNode::IndexEntryNode()
{
}

IndexEntryNode::IndexEntryNode(int acctID,int recNum, IndexEntryNode* left, IndexEntryNode* right)
{
	this->a.acctID = acctID;
	this->a.recNum = recNum;
	this->left = left;
	this->right = right;
}

//void IndexEntryNode::setIE(IndexEntry a)
//{
//	this->a.acctID = a.acctID;
//	this->a.recNum = a.recNum;
//}

void IndexEntryNode::setRI(int recID)
{
	this->a.recNum = recID;
}

void IndexEntryNode::setSI(int StuID)
{
	this->a.acctID = StuID;
}

int IndexEntryNode::getRI()
{
	return a.recNum;
}

int IndexEntryNode::getSI()
{
	return a.acctID;
}

IndexEntryNode::~IndexEntryNode()
{
}
