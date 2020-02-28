// Task3(AVL tree).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include"AVLTree.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	AVLTree<double> first;
	for (int i = 1; i <=6; i++)
		first.add(i);
	first.add(4.5);
	first.add(4.7);
	cout << (string)first << endl;
	first.del(5);
	vector<double> leafs = first.getLeafList();
	for (int i = 0; i < leafs.size(); i++) cout << leafs[i] << "\t";
	cout << endl<<(string)first << endl;
	if (first.contains(6)) cout << "Yes!!!!";
}
