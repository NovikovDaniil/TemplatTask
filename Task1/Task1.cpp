// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Queue.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	Queue<int> b(2);
	try
	{
		b.push(2);
		b.push(5);
		b.push(6);
	}
	catch (const char* ex)
	{
		cout << "Ошибка: " << ex << endl;
	}
	cout<<endl<<"Element "<< b.pop()<<" deleted"<<endl;
	b.push(6);
	Queue<int> a(4);
	a.push(1);
	a.push(4);
	a.push(8);
	a.push(10);
	Queue<int> c = unionQueues(a, b);
	c.pop();
}

