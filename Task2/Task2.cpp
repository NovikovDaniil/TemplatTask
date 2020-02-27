// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinaryTree<int> a;
	vector<int> v=a.traversal();
	a.add(10);
	a.add(5);
	a.add(12);
	a.add(4);
	cout << (string)a << endl;
	cout << (string)a << endl;
	a.del(5);
	if (a.contains(12)) cout << "Yes!!" << endl;
	cout << (string)a << endl;
	a.del(10);
	cout << (string)a << endl;
	a.del(4);
	cout << (string)a << endl;
	a.del(12);
	cout << (string)a << endl;
	a.add(34);
	a.add(54);
	a.add(17);
	cout << (string)a << endl;
	vector<int> leafs = a.getLeafList();
	for (int i = 0; i < leafs.size(); i++) cout << leafs[i] << "\t";
	vector<int> vertexes = a.traversal();
	cout << endl;
	for (int i = 0; i < vertexes.size(); i++) cout << vertexes[i] << "\t";
	for (int i = 0; i < 70; i += 5) a.add(i);
	if (a.contains(5)) cout << "Element 5 is in the tree" << endl;
	cout << (string)a << endl;
}

