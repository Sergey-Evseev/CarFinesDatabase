#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "Database.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Database base;
	vector <string> Violation{ "������ �� �������", "���������� ��������", "����� �� ��������", "���� � ��������� ���������",
		"�� ������������ ������ ������������", "������� � ������������ �����", "�������� �� ������ ������������� ����������",
	"�������� �� �������", "�������� ��������", "��������� ������ ���������", "���������� ���������", "������������� ����������" };

	base.add(543, Violation[1]);
	base.add(543, Violation[5]);
	base.add(543, Violation[7]);
	base.add(666, Violation[10]);
	base.add(212, Violation[2]);
	base.add(212, Violation[11]);
	base.add(888, Violation[6]);
	base.add(888, Violation[10]);
	base.add(112, Violation[3]);
	base.add(112, Violation[3]);
	base.add(112, Violation[6]);

	cout << "========= ���������� �� ������ =========\n";
	base.PrintNumber(212);
	base.PrintNumber(300);
	base.PrintRange(600, 999);
	cout << "\n========= ����� ���� ���� =========\n";
	base.PrintAll(base.ReturnRoot());

	return 0;
}