#include "Database.h"

Database::Database()
{
	root = NULL; //������ ������ ���������������� �����
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
		<< "number=" << number << " " << "str=" << str<< endl; //������ ��� �������
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
	cout << "add(int value, string str): " << "\nvalue=" << value << "  " << "str=" << str << endl;//������ ��� �������
	add(root, NULL, value, str);
	cout << "add(int value, string str) (return): " << "\nroot=" << root << " " << "value=" << value << " " << "str=" << str << "\n\n"; //������ ��� �������
}

//����� ������ ������ ���� ������//
void Database::PrintAll(Tree* temp)
{	
	if (temp)
	{		
		PrintAll(temp->left);
		cout << "\n����� ������: " << temp->number << endl;
		cout << "���������: " << endl;
		PrintList(temp->list);
		PrintAll(temp->right);
	}
}

//������ ������ �� ��������� ������ (����������)//
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
//������ �� ��������� ������ 
void Database::PrintNumber(int input)
{
	Tree * node = PrintNumber(root, input);	
	if (node == NULL)
	{
		cout << "\n����� ������: " << input << endl;
		cout << "-��� ��������� �� ������� ������" << endl;
	}
	else
	{
		cout << "\n����� ������: " << node->number << endl;
		cout << "���������: " << endl;
		PrintList(node->list);
	}
}

// ���������� ������ �� ��������� �������//
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
		cout << "\n����� ������: " << node->number << endl;
		cout << "���������: " << endl;
		PrintList(node->list);
	}
	if (node->number < max)
	{

		PrintRange(node->right, min, max);
	}

}

void Database::PrintRange(int min, int max)
{
	cout << "\n========= ��������� � ��������� ������� �� " << min << " �� " << max << ": " << "=========\n";
	PrintRange(root, min, max);  
}
