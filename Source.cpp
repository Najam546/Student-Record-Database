#include <iostream>
#include <string>
#include <fstream>
#include "Structs.h"
#include "IndexEntryTree.h"

using namespace std;
//void showData(int stuID)
//{
//
//}

//class IndexEntryNode
//{
//	friend class IndexEntryTree;
//	int recID; int StuID;
//	IndexEntryNode* left;
//	IndexEntryNode* right;
//public:
//	IndexEntryNode()
//	{
//
//	}
//	IndexEntryNode(int recID,int StuID, IndexEntryNode* left, IndexEntryNode* right)
//	{
//		this->recID = recID;
//		this->StuID=StuID;
//		this->left = left;
//		this->right = right;
//	}
//	void setRI(int recID)
//	{
//		this->recID = recID;
//	}
//	void setSI(int StuID)
//	{
//		this->StuID = StuID;
//	}
//};
//class IndexEnryTree
//{
//	IndexEntryNode* root;
//};


void main()
{
	ifstream file; AccountRecord a; IndexEntryNode IEN[50]; int i = 0; IndexEntryTree IET; int ID_to_find;
	file.open("records.dat", ios::in,ios::binary);
	while (file.read(reinterpret_cast<char*> (&a), sizeof(AccountRecord))) 
	{
		IEN[i].setRI(a.recNum); IEN[i].setSI(a.acctID);
		IET.insert(IEN[i]);
		i++;
	}
	file.close();
	IET.display();
	if (IET.search(3007) >= 0)//PUT THE STUDENT ID TO FIND THE DATA FROM FILE HERE.
	{
		ID_to_find = IET.search(3007);
		file.open("records.dat", ios::in, ios::binary);
		while (file.read(reinterpret_cast<char*> (&a), sizeof(AccountRecord)))
		{
			if (a.recNum == ID_to_find)
			{
				cout << a.acctID << " " << a.firstName << " " << a.lastName << " " << a.program << " " << a.cgpa << endl;
				break;
			}
		}
	}
}