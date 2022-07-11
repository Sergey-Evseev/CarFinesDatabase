#pragma once
#include <iostream>
#include <string>
using namespace std;

class Database
{
	
	class FinesList
	{
	public:
		string fine;
		FinesList* next;
	};

	class Tree
	{
	public:
		Tree* parent;
		Tree* left;
		Tree* right;

		int number;
		FinesList* list;
	};

private:
	int size;
	Tree* root;

public:
	void Push(FinesList *&node, string newStr)
	{
		FinesList *tmp = new FinesList;

		tmp->fine = newStr;
		tmp->next = NULL;

		if (node == NULL)
		{
			node = tmp;
		}
		else
		{
			tmp->next = node;
			node = tmp;
		}
	}

	void ClearList(FinesList* &Head)
	{
		FinesList * curr = Head;
		while (curr)
		{
			FinesList *temp = curr->next;
			delete curr;
			curr = temp;
		}
	}

	void PrintList(FinesList *Head)
	{
		FinesList * curr = Head;
		int count = 1;
		while (curr)
		{
			cout << count << "." << curr->fine << endl;
			curr = curr->next;
			count++;
		}
	}			

	Database();
	~Database();

	void add(int value, string str);
	void add(Tree*&, Tree*, int, string str);
	void PrintAll(Tree*);
	void PrintNumber(int input);
	Tree *  PrintNumber(Tree *root, int input);
	void PrintRange(Tree * node, int left, int right);
	void PrintRange(int left, int right);
	Tree* ReturnRoot();
	void DeleteAll(Tree* temp);
};

