#include"NodeClass.h"

Node::Node(unsigned int data_in)	//basic constructor
{
	data = data_in;
}
Node::Node(unsigned int data_in, Node * left_in, Node * right_in)	//constructor that takes in left and right nodes
{
	data = data_in;
	left = left_in;
	right = right_in;
}

unsigned int Node::getNodeValue()	//gets value of node
{
	return data;
}

void Node::setNodeValue(unsigned int data_in)	//sets value of Node
{
	data = data_in;
}

void Node::setLeftNode(Node * left_in)		//sets left Node
{
	left = left_in;
}
void Node::setRightNode(Node * right_in)	//sets right Node
{
	right = right_in;
}

Node * Node::getRightNode()				//gets right Node
{
	return right;
}

Node * Node::getLeftNode()				//gets left Node
{
	return left;
}

