#pragma once
class Node
{
public:
	Node(unsigned int data_in);		//node declarations
	Node(unsigned int data_in, Node * left_in, Node * right_in);
	void setNodeValue(unsigned int data_in);	//set value
	unsigned int getNodeValue();
	void setRightNode(Node * right_in);	//set for each particular node right/left
	void setLeftNode(Node * left_in);
	Node * getRightNode();		//gets Node right left
	Node * getLeftNode();

private:
	Node * left;		//private members left/right and int data
	Node * right;
	unsigned int data;
};