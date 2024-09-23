#include"bst.h"

BinarySearchTree::BinarySearchTree() {

	root = NULL;
	count = 0;
}
Node* BinarySearchTree::getroot() {
	return root;
}


void BinarySearchTree::Insert(string name1) {

	Node* newnode = new Node();
	newnode->name = name1;

	if (root == NULL)
	{
		cout << endl;
		root = newnode;
		cout << "Suucessfully Inserted Word :) " << endl;
		cout << "Suucessfully Inserted root " << endl;
		cout << " >> Root will store: " << root->name;
		cout << endl;
		count++;
		return;
	}
	else
	{
		Node* temp = root;
		while (temp != NULL)
		{
			if (temp->left == NULL)
			{
				cout << endl;
				temp->left = newnode;
				cout << "Sucessfully Inserted Word :) " << endl;
				cout << "Sucessfully Inserted Left " << endl;
				cout << " >> Left node has Word:  " << temp->left->name;
				cout << endl;
				count++;
				return;
			}


			else if (temp->right == NULL && temp->left != NULL)
			{
				cout << endl;
				temp->right = newnode;
				cout << "Sucessfully Inserted Word :) " << endl;
				cout << "Sucessfully Inserted Word Right  :) " << endl;
				cout << " >> Right node has Word:  " << temp->right->name;
				cout << endl;
				count++;
				return;


			}
			else if (temp->left != NULL)
			{
				temp = temp->left;
			}

			else if (temp->right != NULL)
			{
				temp = temp->right;
			}

		}



	}


}
void BinarySearchTree::Search(string name)
{
	if (root == NULL) {
		cout << " Tree is Empty " << endl;
		return;
	}

	else
	{
		for (int i = 0; i < count; i++)
		{
			Node* temp = root;
			Node* pre = NULL;
			while (temp != NULL) {
				pre = temp;
				if (temp->name == name) {
					cout<<" Found " <<endl;
					return;
				}

				if (temp->right != NULL && temp->right->name == name) {
					cout << " Found " << endl;
					return;
				}
				temp = temp->left;
			}

		}
	}
}
void BinarySearchTree::PreorderPrint(Node* temp) {
    if (temp == NULL) {
        return;
    }

    cout << " The Word is: " << temp->name << endl;
    PreorderPrint(temp->left);
    PreorderPrint(temp->right);
}
void BinarySearchTree::InorderPrint(Node* temp) {

	if (temp == NULL) {
		return;
	}

	PreorderPrint(temp->left);
	cout << " The Word is: " << temp->name << endl;
	PreorderPrint(temp->right);
}
void  BinarySearchTree::PostorderPrint(Node* temp) {
	if (temp == NULL) {
		return;
	}

	PreorderPrint(temp->left);
	PreorderPrint(temp->right);
	cout << " The Word is: " << temp->name << endl;
}
void BinarySearchTree::FindHeight() {

	int level = 0;
	if (root == NULL)
	{
		cout << " Tress is Empty " << endl;
	}
	else
	{
		Node* temp = root;
		while (temp != NULL)
		{
			temp = temp->left;
			level++;
		}
		cout << " The Total level of Tree is: " << level-1<<endl;
		cout << " The Depth Or Height of Tree is: " << pow(2, (level-1)) << endl;

	}


}
void  BinarySearchTree::FindShortestword()
{
	if (root == NULL) {
		cout << " Tree is Empty " << endl;
		return;
	}
	else {
		string shortest = root->name;
		for (int i = 0; i < count; i++) {
			Node* temp = root;
			Node* pre = NULL;
			while (temp != NULL) {
				pre = temp;
				if (temp->name.size() < shortest.size()) {
					shortest = temp->name;
				}

				if (temp->right != NULL && temp->right->name.size() < shortest.size()) {
					shortest = temp->right->name;
				}

				temp = temp->left;
			}
		}
		cout << " The Shortest Word is: " << shortest << endl;
	}
}
void BinarySearchTree::Findmaximumword()
{
	if (root == NULL) {
		cout << " Tree is Empty " << endl;
		return;
	}
	else {
		string longest = root->name;
		for (int i = 0; i < count; i++)
		{
			Node* temp = root;
			Node* pre = NULL;
			while (temp != NULL) {
				pre = temp;
				if (temp->name.size() > longest.size()) {
					longest = temp->name;
				}

				if (temp->right != NULL && temp->right->name.size() > longest.size()) {
					longest = temp->right->name;
				}

				temp = temp->left;
			}
		}
		cout << " The Longest Word is: " << longest << endl;
	}





}
void BinarySearchTree::Delete(string name)
{
	if (root == NULL)
	{
		cout << "Tree is Empty..." << endl;
		return;
	}
	Node* curr = root;
	Node* parent = NULL;
	//search node 
	while (curr != NULL)
	{
		if (curr->name == name)//fount
			break;
		else {//still search
			parent = curr;
			if (name < curr->name)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
	if (curr == NULL || curr->name!= name)
	{
		cout << "not found" << endl;
		return;
	}
	//Case 1: delete a node having zero child
	else if (curr->left == NULL && curr->right == NULL)
	{
	
		if (parent->left == curr) {
			parent->left = NULL;
			delete curr;
			cout << "node deleted" << endl;
			return;
		}
		else {
			parent->right = NULL;
			delete curr;
			cout << "node deleted" << endl;
			return;
		}
	}

	//Case 2: delete a node having single child
	else if (curr->left != NULL && curr->right == NULL)
	{
		if (parent != NULL && parent->left == curr)
		{
			parent->left = curr->left;
			delete curr;
			cout << "node deleted" << endl;
			count--;
			return;
		}
		else {
			parent->right = curr->left;
			delete curr;
			cout << "node deleted" << endl;
			count--;
			return;
		}
	}
	else if (curr->left == NULL && curr->right != NULL)
	{
		if (parent->left == curr) {
			parent->left = curr->right;
			delete curr;
			cout << "node deleted" << endl;
			count--;
			return;
		}
		else {
			parent->right = curr->right;
			delete curr;
			cout << "node deleted" << endl;
			count--;
			return;
		}
	}
	//case 3: delete a node having two child 
	Node* temp = curr->left;
	Node* chkr = temp;
	while (chkr->right != NULL)
	{
		temp = chkr;
		chkr = chkr->right;
	}
	swap(curr->name, chkr->name);
	temp->right = NULL;
	delete chkr;
	cout << "node deleted" << endl;
	count--;
	return;
}



