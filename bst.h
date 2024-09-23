#pragma once
#include"node.h"

class BinarySearchTree
{
private:
	Node* root;
	int count;

public:
	BinarySearchTree();
	Node* getroot();


	void Insert(string name);
	void Search(string name);
	void Delete(string name);

	void PreorderPrint(Node* root);
	void InorderPrint(Node* root);
	void PostorderPrint(Node* root);

	void FindHeight();

	void FindShortestword();
	void Findmaximumword();
};
