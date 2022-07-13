#include "Database.h"

Database::Database()
{
	root = NULL; //корень дерева инициализируется нулем
	size = 0;
}

Database::~Database()
{
	DeleteAll(root);
}

Database::Tree* Database::ReturnRoot()
{
	return root;
}

void Database::DeleteAll(Tree* temp)
{
	if (temp)
	{
		DeleteAll(temp->left);
		DeleteAll(temp->right);
		ClearList(temp->list);
		delete temp;
	}
}

void Database::add(Tree* &head, Tree* parent, int number, string str)
{
	cout << "add(Tree* &head, Tree* parent, int number, string str): " << "\nhead=" << head << " " << "parent=" << parent << " " 
		<< "number=" << number << " " << "str=" << str<< endl; //строка для отладки
	Tree* temp = new Tree;
	temp->number = number;
	temp->list = NULL;
	temp->left = temp->right = temp->parent = NULL;

	if (!head)
	{
		head = temp;
		Push(head->list, str);
	}
	else
	{
		if (number == head->number)
			Push(head->list, str);
		else if (number < head->number)
			add(head->left, head, number, str);
		else
			add(head->right, head, number, str);
	}
}


void Database::add(int value, string str)
{
	cout << "add(int value, string str): " << "\nvalue=" << value << "  " << "str=" << str << endl;//строка для отладки
	add(root, NULL, value, str);
	cout << "add(int value, string str) (return): " << "\nroot=" << root << " " << "value=" << value << " " << "str=" << str << "\n\n"; //строка для отладки
}

//Метод печати полной базы данных//
void Database::PrintAll(Tree* temp)
{	
	if (temp)
	{		
		PrintAll(temp->left);
		cout << "\nНомер машины: " << temp->number << endl;
		cout << "Нарушения: " << endl;
		PrintList(temp->list);
		PrintAll(temp->right);
	}
}

//Печать данных по заданному номеру (перегрузка)//
Database::Tree * Database::PrintNumber(Tree *node, int input)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (input == node->number)
	{
		return node;
	}
	else if (input < node->number)
	{
		return  PrintNumber(node->left, input);
	}
	else
	{
		return  PrintNumber(node->right, input);
	}

}
//печать по заданному номеру 
void Database::PrintNumber(int input)
{
	Tree * node = PrintNumber(root, input);	
	if (node == NULL)
	{
		cout << "\nНомер машины: " << input << endl;
		cout << "-нет нарушений по данному номеру" << endl;
	}
	else
	{
		cout << "\nНомер машины: " << node->number << endl;
		cout << "Нарушения: " << endl;
		PrintList(node->list);
	}
}

// Распечатка данных по диапазону номеров//
void Database::PrintRange(Tree * node, int min, int max)
{
	if (node == NULL)
	{
		return;
	}
	if (node->number > min)
	{
		PrintRange(node->left, min, max);
	}
	if (node->number >= min && node->number <= max)
	{
		cout << "\nНомер машины: " << node->number << endl;
		cout << "Нарушения: " << endl;
		PrintList(node->list);
	}
	if (node->number < max)
	{

		PrintRange(node->right, min, max);
	}

}

void Database::PrintRange(int min, int max)
{
	cout << "\n========= НАРУШЕНИЯ В ДИАПАЗОНЕ НОМЕРОВ ОТ " << min << " ДО " << max << ": " << "=========\n";
	PrintRange(root, min, max);  
}
