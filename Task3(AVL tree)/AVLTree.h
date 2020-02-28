#pragma once
#include<string>
#include<vector>
using namespace std;
template<class T>
class AVLTree
{
private:
	struct Node
	{
		T data;
		Node* right;
		Node* left;
		int height;
		Node(T _data) :data(_data), right(nullptr), left(nullptr), height(0) {}
	};
	Node* root;

	Node* findMin(Node*);
	Node* removeMin(Node*);
	void make_new_height(Node*&);
	int get_balance(Node*);
	void turnL(Node*&);
	void turnR(Node*&);
	void balance(Node*&);
	void traversal(vector<T>&, Node*);
	void add(T, Node*&);
	void del(T, Node*&);
	bool contains(T, Node*);
	void getLeaf(Node*, vector<T>&);
	string AVLTreeAsString(Node*);
public:
	AVLTree() :root(nullptr) {}
	~AVLTree();
	void dispose(Node*);
	vector<T> traversal();
	void add(T);//insert item
	void del(T);//delete item
	bool contains(T);
	vector<T> getLeafList();
	operator string();
};
template<class T>
typename AVLTree<T>::Node* AVLTree<T>::findMin(Node* root)
{
	if (root->left == nullptr) return root;
	else findMin(root->left);
}
template<class T>
typename AVLTree<T>::Node* AVLTree<T>::removeMin(Node* root)
{
	if (root->left == nullptr) return root->right;
	root->left = removeMin(root->left);
	balance(root);
	return root;
}
template<class T>
void AVLTree<T>::make_new_height(Node*& root)
{
	int heightLeft, heightRight;
	heightLeft = (root->left != nullptr) ? (root->left)->height : 0;
	heightRight = (root->right != nullptr) ? (root->right)->height : 0;
	if (heightLeft > heightRight)
		root->height = heightLeft + 1;
	else
		root->height = heightRight + 1;
}
template<class T>
int AVLTree<T>::get_balance(Node* root)
{
	int heightLeft, heightRight;
	heightLeft = (root->left != nullptr) ? (root->left)->height : 0;
	heightRight = (root->right != nullptr) ? (root->right)->height : 0;
	return heightRight - heightLeft;
}
template<class T>
void AVLTree<T>::turnL(Node*& root)
{
	Node* q = root->left;
	root->left = q->right;
	q->right = root;
	make_new_height(root);
	make_new_height(q);
	root = q;
}
template<class T>
void AVLTree<T>::turnR(Node*& root)
{
	Node* q = root->right;
	root->right = q->left;
	q->left = root;
	make_new_height(root);
	make_new_height(q);
	root = q;
}
template<class T>
void AVLTree<T>::balance(Node*& root)//function to maintain features of  avl tree
{
	make_new_height(root);
	if (get_balance(root) > 1) // if the right subtree is higher than the permissible level
	{
		if (get_balance(root->right) < 0) turnL(root->right);// if the right child has a height of the left subtree greater than the height of the right subtree, then perform a big left turn
		turnR(root);
	}
	else if (get_balance(root) < -1)// if the left subtree is higher than the permissible level
	{
		if (get_balance(root->left) > 0) turnR(root->left);//do big right turn
		turnL(root);
	}
}
template<class T>
AVLTree<T>::~AVLTree()
{
	if (root) {
		this->dispose(this->root);
	}
}
template<class T>
void AVLTree<T>::dispose(Node* root)
{
	if (root)
	{
		dispose(root->left);
		dispose(root->right);
		delete root;
	}
}
template <class T>
void  AVLTree<T>::traversal(vector<T>& vertexes, Node* root)
{
	if (root) {
		traversal(vertexes, root->left);
		vertexes.push_back(root->data);
		traversal(vertexes, root->right);
	}
}
template <class T>
vector<T> AVLTree<T>::traversal()
{
	vector<T> vertexes;
	traversal(vertexes, this->root);
	return vertexes;
}
template<class T>
void AVLTree<T>::add(T data)
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
void AVLTree<T>::add(T data, Node*& root)
{
	if (root == nullptr)
	{
		root = new Node(data);
	}
	else if (data < root->data) add(data, root->left);
	else if (data > root->data) add(data, root->right);
	else throw "This value is already in the tree!";
	balance(root);
}
template<class T>
string AVLTree<T>::AVLTreeAsString(Node* node) {
	string leftStr = (node->left == nullptr) ? "{}" : AVLTreeAsString(node->left);
	string rightStr = (node->right == nullptr) ? "{}" : AVLTreeAsString(node->right);
	string result = "{" + to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
	return result;
}

template<class T>
void AVLTree<T>::del(T data)
{
	this->del(data, this->root);
}
template<class T>
void AVLTree<T>::del(T data, Node*& root) {
	if (root == nullptr) {
		throw "Item to delete was not found";
	}
	if (data > root->data) del(data, root->right);
	else if (data < root->data) del(data, root->left);
	else {
		Node* left=root->left;
		Node* right = root->right;
		delete root;
		if (right == nullptr) {
			root = left;
			return;
		}
		else
		{
			Node* min = findMin(right);// look for a minimum in the right subtree of the deleted node to put this minimum in place of the deleted node
			min->right = removeMin(right);
			min->left = left;
			root = min;
			balance(root);
		}
	}
	balance(root);
}
template<class T>
bool AVLTree<T>::contains(T data)
{
	return contains(data, root);
}
template<class T>
bool AVLTree<T>::contains(T data, Node* root)
{
	if (root == nullptr) return false;
	else if (root->data == data) return true;
	else if (data > root->data) return contains(data, root->right);
	else return contains(data, root->left);
}
template<class T>
vector<T> AVLTree<T>::getLeafList()
{
	vector<T> leafList;
	getLeaf(this->root, leafList);
	return leafList;
}
template<class T>
void AVLTree<T>::getLeaf(Node* root, vector<T>& leaf)
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
AVLTree<T>::operator string()
{
	if (root == nullptr) return "{}";
	else return this->AVLTreeAsString(this->root);
}