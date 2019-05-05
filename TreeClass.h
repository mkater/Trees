#pragma once
#include"NodeClass.h"
#include<string>
#include<iostream>
using namespace std;


class Tree
{
public:
	unsigned int pubFind(int int_Find);		//public function that calls private Find
	void pubInsert(int toInsert);			//public function that calls private Insert
	void PrintinOrder();					//public function that calls private PrivatePrintNode
	void HorizontalPrint();					//public function that calls private PrivateHorizontalPrint
private:
	int getHeightPrivate(Node * n, int depth);	//get height, can be only private as its only used within class
	Node * root = 0;
	unsigned int intFind;
	unsigned int Find(Node * findNode, unsigned int fInt);		//private functions that work recursively.
	void Insert(Node * n, unsigned int fInt);
	void PrivatePrintNode(Node * n, int depth);
	void PrivateHorizontalPrint(Node * n, string * s, const int arraySize, int height);
};