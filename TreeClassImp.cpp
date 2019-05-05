#include"NodeClass.h"
#include"TreeClass.h"
#include<iostream>
#include<string>
using namespace std;

unsigned int Tree::Find(Node * findNode, unsigned int fInt)		//private find function
{
	
	if (findNode == 0)			//if its null/not found return/print -1
	{
		cout << "-1 " << endl;
		return -1;
	}
	else if (findNode->getNodeValue() == fInt)		//else if we've found the value
	{
		cout << findNode->getNodeValue() << " ";
		cout << findNode->getNodeValue() << endl;		//print the value
		return findNode->getNodeValue();
	}

	else if (findNode->getNodeValue() < fInt)		//if node is less than int searching
	{
		cout << findNode->getNodeValue() << " ";
			return Find(findNode->getRightNode(), fInt);	//use recursion to repeat function down right node
	}

	else if (findNode->getNodeValue() > fInt)		//if node is greater than int searching
	{
		cout << findNode->getNodeValue() << " ";
			return Find(findNode->getLeftNode(), fInt);	//use recursion to repeat function down left node
	}
}

unsigned int Tree::pubFind(int int_Find)		//public function
{
	return Find(root, int_Find);		//returns find, with root and int looking for as param
}

void Tree::Insert(Node * n, unsigned int fInt)		//private insert function
{
	if (n->getNodeValue() > fInt)		//if node value greater than int
	{
		if (n->getLeftNode() != nullptr)		//and not null
		{
			Insert(n->getLeftNode(), fInt);		//insert it to the left recursively
		}
		else
		{
			n->setLeftNode(new Node(fInt, 0, 0));		//create new to the left if it is null
		}
	}
	if (n->getNodeValue() < fInt)		//if less
	{
		if (n->getRightNode() != nullptr)		//and right not null
		{
			Insert(n->getRightNode(), fInt);		//insert on right recursively
		}
		else
		{
			n->setRightNode(new Node(fInt, 0, 0));	//else create new node on right
		}

	}
}

void Tree::pubInsert(int toInsert)		//public insert function
{
	if (root == NULL)		//if null
	{
		root = new Node(toInsert, 0, 0);	//create new node
	}
	else
	{
		Insert(root, toInsert);	//call private insert
	}
}



void Tree::HorizontalPrint()		//public print
{
	int h = getHeightPrivate(root, 0) +1;		//calls getheightPrivate of root + 1 into int
	string * s = new string[h];					//creates new string of size h
	PrivateHorizontalPrint(root, s, h, 0);		//calls private function
	for (int i = 0; i < h; i++)					//for height, print string
	{
		cout << s[i] << endl;
	}
}

void Tree::PrivateHorizontalPrint(Node * n, string * s, const int arraySize, int height)		//private function
{


	if (n == 0)		//if null return
	{
		return;
	}

	PrivateHorizontalPrint(n->getLeftNode(), s, arraySize, (height + 1));		//recursively go down left node
	for (int i = 0; i < arraySize; i++)		//going through the array
	{
		if (i == height)
		{
			if (n->getNodeValue() < 10)		//if single digit
			{
				s[i].append(" ");		//add space to array
			
				s[i].append(to_string(n->getNodeValue()));		//and the value of the single digit
			}
			else
			{
				s[i].append(to_string(n->getNodeValue()));		//add the double digit value
			}
		}
		else
		{
			s[i].append("  ");		//if not == height just add two spaces
		}
	}

	PrivateHorizontalPrint(n->getRightNode(), s, arraySize, (height + 1));	//recursively go down right side
}

void Tree::PrintinOrder()		//public print function
{
	PrivatePrintNode(root, 0);
}

void Tree::PrivatePrintNode(Node * n, int depth)		//private print function
{

	if (n == 0)		//if node is null return
	{
		return;
	}
	
	PrivatePrintNode(n->getLeftNode(), (depth + 1));		//recursively print down left node, keep track of depth/height
	for (int i = 0; i < depth; i++)		//print -- for how large depth is
	{
		cout << "--";
	}
	cout << n->getNodeValue() << endl;		//print value of node

	PrivatePrintNode(n->getRightNode(), (depth + 1));		//recursively print right node
}

int Tree::getHeightPrivate(Node * n, int depth)		//get overall height of tree
{
	if (n == 0)		//if null return 0
	{
		return 0;
	}
	else
	{
		if (n->getLeftNode() == 0 && n->getRightNode() == 0)	//if the node has no children
		{
			return depth;
		}
		else
		{
			int lTree = getHeightPrivate(n->getLeftNode(), (depth + 1));	//recursively go down left branch to get value
			int rTree = getHeightPrivate(n->getRightNode(), (depth + 1));	//recursively go down right branch to get value

			if (lTree > rTree)		//whichever one is larger is returned as height
			{
				return (lTree);
			}
			else
			{
				return (rTree);
			}
		}
	}
}
