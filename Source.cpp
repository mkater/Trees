#include"TreeClass.h"
#include"NodeClass.h"
#include<iostream>

using namespace std;

int main()
{

	Tree myTree;			//creating tree for main functions
	myTree.pubInsert(8);	//inserting values into tree
	myTree.pubInsert(4);
	myTree.pubInsert(12);
	myTree.pubInsert(2);
	myTree.pubInsert(6);
	myTree.pubInsert(10);
	myTree.pubInsert(14);
	myTree.pubInsert(1);
	myTree.pubInsert(9);
	myTree.pubInsert(11);
	myTree.pubInsert(15);
	myTree.pubInsert(16);
	

	myTree.pubFind(4);	//looking for values within tree
	myTree.pubFind(5);	//5 is not in tree, will return -1 when it gets here
	myTree.pubFind(6);
	myTree.pubFind(10);
	myTree.pubFind(9);

	myTree.PrintinOrder();		//prints the tree in an in-order traversal
	myTree.HorizontalPrint();	//prints the trees horizontally by their height
	cin.ignore(2);
}