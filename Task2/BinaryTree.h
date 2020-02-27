#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T>
class BinaryTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node(T _data) :data(_data),left(nullptr), right(nullptr) {}
	};
	Node* root;
	
	void traversal(vector<T>&,Node*);
	void add(T, Node*&);
    void del(T, Node*&);
	bool contains(T, Node*);
	void getLeaf(Node*, vector<T>&);
	string BinaryTreeAsString(Node*);
public:
	void dispose(Node*);
	BinaryTree() :root(nullptr) {}
	~BinaryTree();
	vector<T> traversal();
	void add(T);
	void del(T);
	bool contains(T);
	vector<T> getLeafList();
	operator string();
};
template<class T>
BinaryTree<T>::~BinaryTree()
{
	if (root) {
		this->dispose(this->root);
	}
}
template<class T>
void BinaryTree<T>::dispose(Node*root)
{
	if (root)
	{
		dispose(root->left);
		dispose(root->right);
		delete root;
	}
}
template <class T>
void  BinaryTree<T>::traversal(vector<T>& vertexes, Node* root)
{
	if (root) {
		traversal(vertexes, root->left);
		vertexes.push_back(root->data);
		traversal(vertexes, root->right);
	}
}
template <class T>
vector<T> BinaryTree<T>::traversal()
{
	vector<T> vertexes;
	traversal(vertexes,this->root);
	return vertexes;
}
template<class T>
void BinaryTree<T>::add(T data)
{
	if (root == nullptr)
	{
		root = new Node(data);
	}
	else
	{
		this->add(data, root);
	}
}
template<class T>
void BinaryTree<T>::add(T data, Node*& node)
{
	if (node == nullptr)
	{
		node = new Node(data);
	}
	else if (data < node->data) this->add(data, node->left);
	else if (data > node->data) this->add(data, node->right);
	else throw "This value is already in the tree!";
}
template<class T>
string BinaryTree<T>::BinaryTreeAsString(Node* node) {
	string leftStr = (node->left == nullptr) ? "{}" : BinaryTreeAsString(node->left);
	string rightStr = (node->right == nullptr) ? "{}" : BinaryTreeAsString(node->right);
	string result = "{" + to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
	return result;
}

template<class T>
void BinaryTree<T>::del(T data)
{
	this->del(data, this->root);
}
template<class T>
void BinaryTree<T>::del(T data, Node*& root) {
	if (root == nullptr) {
		throw "Item to delete was not found";
	}
	if (data > root->data) del(data, root->right);
	else if (data < root->data) del(data, root->left);
	else {
		Node* temp = root;
		if (temp->right == nullptr && temp->left == nullptr)
		{
			root = nullptr;
		}
		else if (temp->right == nullptr && temp->left != nullptr)
		{
			root = temp->left;
		}
		else if (temp->left == nullptr && temp->right != nullptr)
		{
			root = temp->right;
		}
		else
		{
			Node*& maxNode=temp->left;//to delete an item will look for the maximum number in the left subtree to replace
			while (maxNode->right) maxNode = maxNode->right;
			temp->data = maxNode->data;
			this->del(maxNode->data, maxNode);
		}
	}
}
template<class T>
bool BinaryTree<T>::contains(T data)
{
	return contains(data, root);
}
template<class T>
bool BinaryTree<T>::contains(T data, Node* root)
{
	if (root == nullptr) return false;
	else if (root->data == data) return true;
	else if (data > root->data) return contains(data, root->right);
	else return contains(data, root->left);
}
template<class T>
vector<T> BinaryTree<T>::getLeafList()
{
	vector<T> leafList;
	getLeaf(this->root, leafList);
	return leafList;
}
template<class T>
void BinaryTree<T>::getLeaf(Node* root, vector<T>& leaf)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		leaf.push_back(root->data);
	}
	else
	{
		if (root->left) getLeaf(root->left, leaf);
		if (root->right) getLeaf(root->right, leaf);
	}
}
template<class T>
BinaryTree<T>::operator string()
{
	if (root == nullptr) return "{}";
	else return this->BinaryTreeAsString(this->root);
}